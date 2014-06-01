#!/bin/bash

cd bin/data/inspiration
avconv -r 1/5 -i *.jpg -c:v libx264 ins.mp4
cd ../../../
make
make run
#scp bin/data/$img to webserver
cat bin/log.csv
python python/newPrint.py
img=`ls -1 bin/data | tail -1`
display `echo bin/data/$img`
