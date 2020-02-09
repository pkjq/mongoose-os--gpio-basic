/*
 * Copyright (c) 2018-2020 pkjq
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GD16967C8_8DF8_4448_9780_3D84133A672C
#define GD16967C8_8DF8_4448_9780_3D84133A672C


namespace gpio
{
// Pins used during Boot:
// The ESP8266 can be prevented from booting if some pins are pulled LOW or HIGH.
// The following list shows the state of the following pins on BOOT:
//      * GPIO16: pin is high at BOOT
//      * GPIO0:  boot failure if pulled LOW
//      * GPIO2:  pin is high on BOOT, boot failure if pulled LOW
//      * GPIO15: boot failure if pulled HIGH
//      * GPIO3:  pin is high at BOOT
//      * GPIO1:  pin is high at BOOT, boot failure if pulled LOW
//      * GPIO10: pin is high at BOOT
//      * GPIO9:  pin is high at BOOT


// Pins HIGH at Boot:
// There are certain pins that output a 3.3V signal when the ESP8266 boots.
// The following GPIOs output a HIGH signal on boot:
//      * GPIO16
//      * GPIO3
//      * GPIO1
//      * GPIO10
//      * GPIO9


// GPIOs connected to the Flash Chip:
//      * GPIO6 to GPIO11 are usually connected to the flash chip in ESP8266 boards.
// This pins are not recommended to use.


enum class ESP01: int
{
    Tx          = 1,
    Led         = Tx,
    Rx          = 3,

    Gpio_0      = 0,
    Gpio_2      = 2,
};
}


#endif//GD16967C8_8DF8_4448_9780_3D84133A672C
