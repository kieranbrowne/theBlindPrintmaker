#!/usr/bin/env python 

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
    pattern += "["+str(numVerts)+"][2] = "
    print pattern
    return pattern

def writeToOfApp(search,appendix):
    file = open("src/ofApp.h.test", "r+")
    fullFile = file.read()
    cursorLoc = fullFile.find(search)
    postCursor = fullFile[cursorLoc:]
    file.seek(cursorLoc,0)
    file.write(appendix+postCursor)
    file.close()

writeToOfApp("//!!//",carvePrint())
