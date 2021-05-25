package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
	"unicode"
)

const (
	STATE_HEAD int = iota
	STATE_KEYMAPS
	STATE_KEYMAP
	STATE_TAIL
)

func is_comment_line(line string) bool {
	line = strings.TrimSpace(line)
	return strings.HasPrefix(line, "//") || strings.HasPrefix(line, "*") || strings.HasPrefix(line, "/*") || strings.HasPrefix(line, "*/")
}

func print_formatted(kb *keyboard_t, layer *layer_t) []string {
	output := make([]string, 0, 8)
	width := make([]int, len(kb.Rows[0]))
	for i := 0; i < len(width); i++ {
		if len(kb.Spacing) > 0 {
			width[i] = kb.Spacing[0]
		} else {
			width[i] = 8
		}
	}
	for _, row := range kb.Rows {
		for i, ki := range row {
			if ki >= 0 {
				key := layer.Keymap[ki]
				if len(key) > width[i] {
					width[i] = len(key)
				}
			} else {
				ki = -ki
				if ki >= 0 && ki < len(kb.Spacing) {
					if kb.Spacing[ki] > width[i] {
						width[i] = kb.Spacing[ki]
					}
				}
			}
		}
	}
	key_formats := make([]string, len(width))
	for i, w := range width {
		key_formats[i] = fmt.Sprintf("%s%d%s", "%-", w, "s")
	}

	for ri, row := range kb.Rows {
		separator := ""
		line := "    "
		for i, ki := range row {
			if ki < 0 {
				line = line + fmt.Sprintf(key_formats[i], " ")
				line = line + "  "
			} else {
				line = line + fmt.Sprint(separator)
				line = line + fmt.Sprintf(key_formats[i], layer.Keymap[ki])
				separator = ", "
			}
		}

		// the last row does not need a comma at the end
		if ri < (len(kb.Rows) - 1) {
			line = line + ","
		}

		output = append(output, line)
	}
	return output
}

const (
	PARSER_WHITESPACE int = iota
	PARSER_ARRAYITEM
)

func parse_layer_id(line string) string {
	// [ID] = LAYOUT(
	id := make([]rune, 0, 16)
	state := 0
	for _, r := range line {
		if state == 0 {
			if r == '[' {
				state = 1
			}
		} else if state == 1 {
			if r == ']' {
				state = 2
			} else {
				id = append(id, r)
			}
		} else if state == 2 {
			break
		}
	}
	idstr := string(id)
	idstr = strings.TrimSpace(idstr)
	return idstr
}

func parse_elements(line string) []string {
	keymap := make([]string, 0, 80)

	line = strings.TrimRightFunc(line, func(r rune) bool {
		return r == ' ' || r == '/' || r == '*' || r == '\t' || r == '\\'
	})

	state := PARSER_WHITESPACE
	open := 0
	elem := make([]rune, 0, 60)
	for _, r := range line {
		if state == PARSER_WHITESPACE {
			if unicode.IsSpace(r) == false {
				state = PARSER_ARRAYITEM
				elem = elem[:0]
				elem = append(elem, r)
			}
		} else if state == PARSER_ARRAYITEM {
			if open > 0 {
				if r == ']' || r == ')' {
					open -= 1
				}
				elem = append(elem, r)
			} else {
				if r == ',' {
					state = PARSER_WHITESPACE
					elemstr := string(elem)
					elemstr = strings.TrimSpace(elemstr)
					keymap = append(keymap, elemstr)
					elem = elem[:0]
				} else {
					if r == '[' || r == '(' {
						open += 1
					}
					elem = append(elem, r)
				}
			}
		}
	}
	if len(elem) > 0 {
		elemstr := string(elem)
		elemstr = strings.TrimSpace(elemstr)
		keymap = append(keymap, elemstr)
	}
	return keymap
}

func parse_viz_layer_names(line string) []string {
	layer_names := make([]string, 0, 4)
	layers_str := make([]rune, 0, 32)
	state := 0
	for _, c := range line {
		if state == 0 {
			if c == '[' {
				state = 1
			}
		} else if state == 1 {
			if c == ']' {
				state = 2
			} else {
				layers_str = append(layers_str, c)
			}
		} else if state == 2 {
			break
		}
	}
	layers := strings.Split(string(layers_str), ",")
	for _, l := range layers {
		layer_name := strings.TrimSpace(l)
		layer_names = append(layer_names, layer_name)
	}
	return layer_names
}

func index_to_viz(index int) string {
	return fmt.Sprintf("_%03d_", index)
}

func print_viz(k *keyboard_t, layer *layer_t) []string {
	keyboardviz := make([]string, 0, 32)
	for _, line := range k.VizBoard {
		keyboardviz = append(keyboardviz, line)
	}

	spacing := "                          "
	for ki, key := range layer.Keymap {
		keysymbol := ""
		if symbol, ok := k.VizSymbols[key]; ok {
			keysymbol = symbol
		} else if len(key) > k.VizWidth {
			keysymbol = key[(len(key) - k.VizWidth):]
		} else if len(key) < k.VizWidth {
			lp := (k.VizWidth - len(key)) / 2
			rp := k.VizWidth - len(key) - lp
			keysymbol = fmt.Sprintf("%s%s%s", spacing[0:lp], key, spacing[0:rp])
		} else {
			keysymbol = key
		}

		marker := index_to_viz(ki)
		for i := 0; i < len(keyboardviz); i++ {
			if strings.Contains(keyboardviz[i], marker) {
				keyboardviz[i] = strings.Replace(keyboardviz[i], marker, keysymbol, 1)
			}
		}
	}

	return keyboardviz
}

func main() { os.Exit(mainReturnWithCode()) }

func mainReturnWithCode() int {
	scanner := bufio.NewScanner(os.Stdin)
	lines := make([]string, 0, 4096)
	for scanner.Scan() {
		line := scanner.Text()
		lines = append(lines, line)
	}

	// find the config json lines
	collect_json := false
	json := ""
	for _, line := range lines {
		if strings.Contains(line, "qmk-keyboard-format:json:begin") {
			collect_json = true
		} else if strings.Contains(line, "qmk-keyboard-format:json:end") {
			collect_json = false
		} else {
			if collect_json {
				json = json + line
			}
		}
	}

	if json == "" {
		return -1
	}

	kb, err := UnmarshalKeyboard([]byte(json))
	if kb == nil || err != nil {
		fmt.Printf("error, cannot unmarshall json")
		return -2
	}

	keymaps_begin := "keymaps[]"
	keymaps_end := "};"
	keymap_begin := "LAYOUT("
	keymap_end1 := "),"
	keymap_end2 := ")"
	keymapvizbegin := "qmk-keyboard-format:keymapviz:begin"
	keymapvizend := "qmk-keyboard-format:keymapviz:end"

	output := make([]string, 0, 1024)

	layers := make(map[string]*layer_t)

	doviz := 0
	state := STATE_HEAD
	layer := &layer_t{}
	for _, line := range lines {

		if strings.Contains(line, keymapvizbegin) {
			doviz = doviz | 1
		} else if strings.Contains(line, keymapvizend) {
			doviz = doviz | 2
		}

		// here we check if the line is a '//' comment and skip processing it
		if is_comment_line(line) {
			output = append(output, line)
		} else {
			if state == STATE_HEAD {
				if strings.Contains(line, keymaps_begin) {
					state = STATE_KEYMAPS
					output = append(output, line)
				} else {
					output = append(output, line)
				}
			} else if state == STATE_KEYMAPS {
				if strings.Contains(line, keymap_begin) {
					layer_name := parse_layer_id(line)
					layer = &layer_t{Name: layer_name, Keymap: make([]string, 0, 104)}
					layers[layer_name] = layer
					state = STATE_KEYMAP
					output = append(output, line)
				} else if strings.Compare(strings.TrimSpace(line), keymaps_end) == 0 {
					state = STATE_TAIL
					output = append(output, line)
				} else {
					output = append(output, line)
				}
			} else if state == STATE_KEYMAP {
				if strings.TrimSpace(line) == keymap_end1 || strings.TrimSpace(line) == keymap_end2 {
					// do we have a parsed keymap, if so write it out here in a formatted form
					//if len(keymap) == keyboard.numkeys {
					formatted := print_formatted(kb, layer)
					for _, l := range formatted {
						output = append(output, l)
					}
					//}
					layer = nil
					state = STATE_KEYMAPS
					output = append(output, line)
				} else {
					// collect the elements from these lines
					elems := parse_elements(line)
					layer.Keymap = append(layer.Keymap, elems...)
				}
			} else if state == STATE_TAIL {
				output = append(output, line)
			}
		}
	}

	if doviz == 3 {
		// iterate over all output lines and identify locations where we need to output ascii-art for a layer
		doviz = 0
		layers_to_viz := make([]string, 0, 4)
		output_temp := make([]string, 0, 1024)
		for _, line := range output {
			if doviz == 0 && strings.Contains(line, keymapvizbegin) {
				doviz = 1
				layers_to_viz = parse_viz_layer_names(line)
				output_temp = append(output_temp, line)
			} else if doviz == 1 && strings.Contains(line, keymapvizend) {
				// output the necessary layers as ascii-art
				for _, ln := range layers_to_viz {
					if layer, ok := layers[ln]; ok {
						output_temp = append(output_temp, fmt.Sprintf("  // Layer %s", ln))
						layer_viz := print_viz(kb, layer)
						output_temp = append(output_temp, layer_viz...)
					}
				}
				output_temp = append(output_temp, line)
				doviz = 0
			} else if doviz == 0 {
				output_temp = append(output_temp, line)
			}
		}
		output = output_temp
	}

	for _, l := range output {
		fmt.Println(l)
	}

	return 0
}

func UnmarshalKeyboard(data []byte) (*keyboard_t, error) {
	r := &keyboard_t{}
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *keyboard_t) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

type keyboard_t struct {
	Name       string            `json:"name"`
	Numkeys    int               `json:"numkeys"`
	Rows       [][]int           `json:"rows"`
	VizWidth   int               `json:"vizcellwidth"`
	VizBoard   []string          `json:"vizboard"`
	VizSymbols map[string]string `json:"vizsymbols"`
	Spacing    []int             `json:"spacing"`
}

type layer_t struct {
	Name   string
	Keymap []string
}

// key symbols
// http://xahlee.info/comp/unicode_computing_symbols.html
