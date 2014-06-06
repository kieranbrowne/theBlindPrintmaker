#!/bin/bash

cd bin/data/inspiration
for f in *.jpg
do convert $f -resize 320x320 $f
done
avconv -r 1/5 -i *.jpg -c:v libx264 ins.mp4

