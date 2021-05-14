#!/bin/bash

if [[ $1 == "clean" ]]; then
	for filename in *; do
		# echo $filename
		if [[ -x $filename ]]; then
			# echo $filename
			gio trash $filename
		fi
	done
	gio trash runsample.py
	exit 0
fi

var=$(pwd)/runsample.py

if [ ! -f "$var" ]; then
	echo "file not exists"
	pwd
	cp ~/Documents/CP/Resources/Helper/runsample.py .
fi

python3 runsample.py --f $1
