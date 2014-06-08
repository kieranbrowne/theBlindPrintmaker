# The Blind Printmaker

The Blind Printmaker is an artificial intelligence which produces original artistic images via computational logic. The software learns from human evaluation, developing over time. The aim of the project is to crowd-source a set of computer interperatable guidelines which most successfully interface with the human visual and emotional systems and in a sense 'hack' into a creative art space.

## Commands
- ```./browse``` sources images to draw shape primitives from.
- ```./execute``` compile, run, rewrite, repeat.
- ```./reset``` returns mutated code to stable state based on .bak files.

## Dependencies
The Blind Printmaker is currently cobbled together from openFrameworks, Python and BASH code. There are plans to move Python functionality to openFrameworks at some stage.
All code runs on 64bit Linux and is untested on other systems.
The ```browse``` script makes use of ```avconv```, ```convert``` and ```wget``` and therefore requires some specific packages to be installed. Other commands should be standard to all BASH versions that I am aware of.

