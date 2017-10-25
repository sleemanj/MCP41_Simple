/**
 * Simple MCP41xxx Library Example - Increase and Decrease Resistance
 *
 * First increases resistance from zero to max, and then from max to zero
 * and then repeats, in other words, a fade-up and fade-down.
 * 
 * Wiring:
 * 
 *   MCP41xxx Pin 1 (CS)  => Arduino Pin 10 (see note below)
 *   MCP41xxx Pin 2 (SCK) => Arduino Pin SCK  (13 on Uno/Pro-Mini etc) 
 *   MCP41xxx Pin 3 (SI)  => Arduino Pin MOSI (11 on Uno/Pro-Mini etc)
 *   MCP41xxx Pin 4 (Vss) => Gnd
 *   MCP41xxx Pin 5 (Potentiometer B) => MCP41xxx Pin 6 (Potentiometer Wiper) 
 *   MCP41xxx Pin 6 (Potentiometer Wiper) => Multimeter Common Socket (Multimeter in resistance mode)
 *   MCP41xxx Pin 7 (Potentiometer A) => Multimeter Ohm's Socket  (Multimeter in resistance mode)
 *   MCP41xxx Pin 8 (Vdd) => 5v
 * 
 * Upload sketch and observe the resistance changing on the multimeter.
 * 
 * CS NOTE:  Unlike many other SPI devices, you can not just ground the CS pin
 *           it must be controlled by the library.
 * 
 * Copyright (C) 2017 James Sleeman
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 * 
 * @author James Sleeman, http://sparks.gogo.co.nz/
 * @license MIT License
 */

#include <MCP41_Simple.h>

MCP41_Simple MyPot;

const uint8_t CS_PIN = 10;
uint8_t CUR_VAL      = 0;
uint8_t DIRECTION    = 1;

void setup() {
  // put your setup code here, to run once:
  MyPot.begin(CS_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  MyPot.setWiper(CUR_VAL);
  if(DIRECTION)
  {
    CUR_VAL++;
    if(CUR_VAL==0) DIRECTION = 0;
  }
  else
  {

    CUR_VAL--;
    if(CUR_VAL==0) DIRECTION = 1;
  }
  
  delay(250);
}