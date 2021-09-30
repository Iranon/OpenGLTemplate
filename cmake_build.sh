#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

#-Building
echo ""
cmake . -B build
cd build && cmake --build .

#-Running
echo -e "\n_> Searching for application to be launched...\n"
app=""
found=false
for entry in $(ls)
do
	if [ ! -d "$entry" ] && [ -x "$entry" ]; then
		app=$entry
		found=true
		break;
	fi
done
if [ "$found" = true ]; then
	echo -e "\n_> ${GREEN}Launching $app...${NOCOLOR}\n"
	./$app
else
	echo -e "\n${RED}-Executable not found-${NOCOLOR}\n"
fi
