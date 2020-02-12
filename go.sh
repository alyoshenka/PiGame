#!/bin/bash

echo "compiling"
g++ -Wall -c "%f"

echo "building"
make 

echo "executing"
"sudo /home/jay/PiGame/PiGame"
