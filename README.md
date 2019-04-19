<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [MCP41_Simple](#mcp41_simple)
  - [About MCP41xxx Digital Potentiometers](#about-mcp41xxx-digital-potentiometers)
  - [Wiring](#wiring)
  - [Download, Install and Example](#download-install-and-example)
  - [Troubleshooting](#troubleshooting)
  - [Full Class Reference](#full-class-reference)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# MCP41_Simple
Simple Arduino Library for the MCP41 Series Of 8 Bit Digital Potentiometers (MCP41010, MCP41050, MCP41100)

## About MCP41xxx Digital Potentiometers

The MCP41xxx series of digital Potentiometers have an 8 bit wiper and can be used as potentiometers, or as variable resistors (in the normal manner, that is, tie the Wiper output to the bottom leg).

They have about +/- 20% Tolerance

They are controlled via SPI, this makes it very easy to control them.

## Wiring 

These devices are SPI based, and this library uses the hardware SPI class.

MCP41xx  | Arduino
-------- | ------- 
 Pin 1 (CS)  | Pin 10 or any other unused pin.
 Pin 2 (SCK) | SCK, Pin 13 on Uno/Pro-Mini/Nano, Pin 52 on Mega, otherwise this is often specifically marked.
 Pin 3 (SI)  | MOSI, Pin 11 on Uno/Pro-Mini/Nano, Pin 51 on Mega, otherwise this is often specifically marked.
 Pin 4 (Vss) | Gnd
 Pin 8 (Vdd) | 5v (or 3v3)
 
The remaining pins of the MCP41xxx (5, 6 and 7) are the potentiometer pins, which can largely be used like you would a potentiometer.  Pins 5 and 7 are the "ends" and pin 6 is the wiper.  If using as a "variable resistor" the datasheet recommends to tie wiper (6) to the B end (5).  In general, the B end is best to ground if either of them will be I believe.

**MISO Pin on Arduino** it is likely that you will not be able to use the MISO pin on your arduino in addition to the above as your microcontroller probably asserts control over that pin when using SPI, even though we never need to read any data from it ourselves.

## Download, Install and Example

* Download: http://sparks.gogo.co.nz/MCP41_Simple.zip
* Open the Arduino IDE (this library was tested in 1.6.13, but older versions should be fine too)
* Select the menu item Sketch > Import Library > Add Library
* Choose to install the MCP41_Simple.zip file you downloaded
* Now you can choose File > Examples > MCP41_Simple > HelloWorld

Upload the example to your Arduino and stand back in awe of the results. 

Try the other examples for more excitement.

## Troubleshooting

The CS pin can not simply be connected to ground like some other SPI devices, it is critical that the library has control over it.

There really isn't anything else to troubleshoot except your wiring, so, check your wiring.

## Full Class Reference

I recommend to just look at the examples which show you how to use all the features, but if you want the nitty-gritty then here is the [full class reference](https://rawgit.com/sleemanj/MCP41_Simple/dbacf9a/docs/html/class_m_c_p41___simple.html)

Thanks to the super kind folks of [RawGit](https://rawgit.com/) and [MaxCDN](http://www.maxcdn.com/)


