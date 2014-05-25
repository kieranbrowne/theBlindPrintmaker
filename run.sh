#!/bin/bash

make
make run
#scp bin/data/$img to webserver
cat bin/log.csv
python python/newPrint.py
img=`ls -1 bin/data | tail -1`
display `echo bin/data/$img`
