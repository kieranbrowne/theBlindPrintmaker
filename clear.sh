#!/bin/bash

echo -n > bin/log.csv
rm bin/data/*.png
cp src/ofApp.h.bak src/ofApp.h
cp src/ofApp.cpp.bak src/ofApp.cpp
cp bin/data/inspiration/ins.mp4.bak bin/data/inspiration/ins.mp4
