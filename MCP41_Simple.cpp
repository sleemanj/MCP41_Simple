/** 
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
 * @see http://ww1.microchip.com/downloads/en/DeviceDoc/11195c.pdf
 */


#include "MCP41_Simple.h"
#include <inttypes.h>
#include <Arduino.h>
#include <SPI.h>

/** Initialise potentiometer on the default SPI bus. */

MCP41_Simple::MCP41_Simple()                  { _spiBus = &SPI;    }

/** Initialise potentiometer on a specified SPI bus.
 * 
 *  If you have more than one SPI bus available, you can pass an appropriate
 *  SPIClass object here.
 * 
 *  Example:
 *   
 *    MCP41_Simple MyPot(SPI1);
 * 
 * This is untested, but should work, assuming your alternative SPI bus also 
 * inherits from SPIClass like the default SPI bus does.
 */

MCP41_Simple::MCP41_Simple(SPIClass &spiBus ) { _spiBus = &spiBus; }
      

/** Begin communication to the potentiometer using the supplied pin as it's 
 *  chipSelect.
 */

void MCP41_Simple::begin(uint8_t chipSelectPin)
{
  _chipSelectPin = chipSelectPin;
  digitalWrite(chipSelectPin, HIGH);
  pinMode(chipSelectPin, OUTPUT);
  _spiBus->begin();
}

/** Set the wiper position of the potentiometer, to a position between 0 and 255.
 */

void MCP41_Simple::setWiper(uint8_t value)
{
  digitalWrite(_chipSelectPin, LOW);
  _spiBus->transfer(B00010001);
  _spiBus->transfer(value);  
  digitalWrite(_chipSelectPin, HIGH);
}

/** Put the potentiometer in shutdown mode, output B gets tied to the Wiper, and output A is tri-stated. 
 */

void MCP41_Simple::shutdownMode()
{
  digitalWrite(_chipSelectPin, LOW);
  _spiBus->transfer(B00100001);
  _spiBus->transfer(0);  
  digitalWrite(_chipSelectPin, HIGH);
}
