#!/usr/bin/env python 
from random import random, randint

def getNumPrints():
    search = "float p"
    file = open("src/ofApp.h", "r+")
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
    file = open("src/ofApp.h", "r+")
    contents = file.read()
    cursorLoc = contents.find(search)
    postCursor = contents[cursorLoc:]
    file.seek(cursorLoc,0)
    file.write(appendix+postCursor)
    file.close()

def replanImage():
    searchStart = "//!s!//"
    searchEnd   = "//!e!//"
    file = open("src/ofApp.cpp", "r+")
    contents = file.read()
    prechange = contents[:contents.find(searchStart)+len(searchStart)]
    postchange = contents[contents.find(searchEnd):]
    file.close()
    file = open("src/ofApp.cpp", "w+")

    nl = "\n    "
    h = str(randint(0,255))
    s = str(randint(0,255))
    b = str(randint(0,255))
    a = str(randint(50,200))
    appendix = nl+"print.colour("+h+","+s+","+b+","+a+");"
    appendix += prtRd()
    appendix += prtRd()
    appendix += prtRd()

    file.write(prechange+appendix+postchange)
    file.close()

def prtRd():
    #print.read(p0000,100,100,200,0);
    nl = "\n    "
    string = nl+"print.read(p"
    string += str(randint(0,getNumPrints())).zfill(4)
    b = 100 # border
    s = randint(1,400)
    x = randint(b,600-b-s)
    y = randint(b,600-b-s)
    string += "," + str(x) + "," + str(y) + "," + str(s) + ",0);" + nl 

    return string
    


### MAIN ###

writeNewPrint("//!!//",carvePrint())
replanImage()
