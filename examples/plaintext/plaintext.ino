//
// Thermal Printer Demo
// written by Larry Bank
// Copyright (c) 2020 BitBank Software, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <Thermal_Printer.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println((char *)"Scanning for BLE printer");
  if (tpScan())
  {
    Serial.println((char *)"Found a printer!, connecting...");
    if (tpConnect())
    {
      Serial.println((char *)"Testing plain text printing");
      tpSetFont(0, 0, 0, 0, 0);
      // for GOOJPRT PT-210
      // uint8_t font_a_cmd[] = {0x1b,'M',0x00};
      // tpWriteRawData(&font_a_cmd[0],sizeof(font_a_cmd));
      tpPrint((char *)"12x24 plain text\n");
      // for GOOJPRT PT-210
      // uint8_t font_b_cmd[] = {0x1b,'M',0x01};
      // tpWriteRawData(&font_b_cmd[0],sizeof(font_b_cmd));
      tpSetFont(1, 0, 0, 0, 0);
      tpPrint((char *)"9x17 plain text\n");
      tpSetFont(1, 1, 0, 0, 0);
      tpPrint((char *)"Underlined\n");
      tpSetFont(1, 0, 1, 0, 0);
      tpPrint((char *)"Double Wide\n");
      tpSetFont(1, 0, 0, 1, 0);
      tpPrint((char *)"Double Tall\n");
      tpSetFont(1, 0, 1, 1, 0);
      tpPrint((char *)"Double Tall+Wide\n");
      tpSetFont(1, 0, 1, 1, 1);
      tpPrint((char *)"Double Tall+Wide + emphasized\n");
      // Give printer some time to finish printing.
      delay(1000);
      Serial.println((char *)"Disconnecting");
      tpDisconnect();
      Serial.println((char *)"Done!");
      while (1) delay(1000);
    }
  }
  else
  {
    Serial.println((char *)"Didn't find a printer :( ");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
