# Dumb Driving - A dead-simple "autonomous" driving algorithm for Felix, an MSP432 controlled robot

Wanted to extend upon the last lab of my Embedded and Robotics class, and so implemented quite possibly the simplest "autonomous" driving algorithm.

Check out the video [here](https://drive.google.com/file/d/1EO9thUppSEr8WAN29p4802wbmTjE2wA0/view?usp=sharing).

If you wish to try out the code yourself, you must have the hardware listed below. The software is less of a requirement, though you do have to have the header files provided by TI for the hardware abstraction layer (HAL), the code that abstracts away all the raw register values into readable, usable structs.

## Hardware
* [MSP432p401r](https://www.ti.com/tool/MSP-EXP432P401R) LaunchPad microcontroller development board
* [TI-RSLK MAX](https://university.ti.com/programs/RSLK/) robot kit

## Software
* Code Composer Studio IDE for debugging
* C programming language (of course)
