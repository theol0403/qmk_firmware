#!/bin/bash
cd /home/theol/Documents/qmk

if [[ $1 -eq 0 ]]
then
make kyria/rev1:theol0403:flash HAND=MASTER_RIGHT
make kyria/rev1:theol0403:avrdude HAND=MASTER_LEFT
elif [[ $1 -eq 1 ]]
then
make kyria/rev1:theol0403:flash HAND=MASTER_RIGHT
elif [[ $1 -eq 2 ]]
then
make kyria/rev1:theol0403:avrdude HAND=MASTER_LEFT
fi
