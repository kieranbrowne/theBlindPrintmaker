#!/bin/bash

make run
img=`ls -1 bin/data | tail -1`
#scp bin/data/$img to webserver
cat bin/log.csv
python python/newPrint.py
