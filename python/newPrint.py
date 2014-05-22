#!/usr/bin/env python 
from random import random

def getNumPrints():
    search = "float p"
    file = open("src/ofApp.h.test", "r+")
    contents = file.read()
    index = 0
    num = 0
    while search in contents[index:]:
        index += contents[index:].find(search)+len(search)
        num = contents[index:index+4]
    file.close()
    return int(num)
    
def carvePrint():
    ''' '''
    numVerts = 5
    pattern = "\n        float p"
    pattern += str(getNumPrints() + 1).zfill(4)
    pattern += "["+str(numVerts)+"][2] = {"
    for i in range(numVerts):
        x = "{0:.3f}".format(round(random(),3))
        y = "{0:.3f}".format(round(random(),3))
        pattern += "{"+x+","+y+"}"
        if i != numVerts-1:
            pattern += ","
    pattern += "};"
    print pattern
    return pattern

def writeNewPrint(search,appendix):
    file = open("src/ofApp.h.test", "r+")
    contents = file.read()
    cursorLoc = contents.find(search)
    postCursor = contents[cursorLoc:]
    file.seek(cursorLoc,0)
    file.write(appendix+postCursor)
    file.close()

def replanImage():
    searchStart = "//!s!//"
    searchEnd   = "//!e!//"
    file = open("src/ofApp.cpp.test", "r+")
    contents = file.read()
    prechange = contents.find(searchStart)
    postchange = contents[contents.find(searchEnd):]

    appendix = ""

    file.write(prechange+appendix+postchange)
    file.close()

    return 0
    
writeNewPrint("//!!//",carvePrint())