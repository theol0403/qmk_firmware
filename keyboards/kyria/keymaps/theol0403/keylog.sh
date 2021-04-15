#!/bin/bash

hid_listen | egrep --line-buffered "(0x[A-F0-9]+,)?(NA|[0-9]+),(NA|[0-9]+),[0-9]{1,2}" >> /home/theol/Documents/qmk/keyboards/kyria/keymaps/theol0403/keylog.csv
