#!/bin/bash

echo -n > bin/log.csv
rm bin/data/*.png
cp src/ofApp.h src/ofApp.h.test
cp src/ofApp.cpp src/ofApp.cpp.test
