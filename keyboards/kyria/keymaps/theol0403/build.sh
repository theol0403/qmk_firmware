#!/bin/bash
cd /home/theol/Documents/qmk_firmware

if [[ $1 -eq 0 ]]
then
make kyria/rev1:theol0403:flash HAND=RIGHT
make kyria/rev1:theol0403:avrdude HAND=LEFT
elif [[ $1 -eq 1 ]]
then
make kyria/rev1:theol0403:flash HAND=RIGHT
elif [[ $1 -eq 2 ]]
then
make kyria/rev1:theol0403:avrdude HAND=LEFT
fi
