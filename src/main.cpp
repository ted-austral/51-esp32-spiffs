
/*
 *  main.cpp - Project 51-esp32-spiffs
 *      How to construct and mount an SPIFFS
 *      and list a file in it
 *
 *      Austral - 2020 - IntroComp - EAM
 *
 *  Taken from Random Nerd Tutorials
 *  Introducing SPIFFS
 *  https://randomnerdtutorials.com/esp32-vs-code-platformio-spiffs/
 */

#include <Arduino.h>
#include "SPIFFS.h"
 
void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
  
    if(!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
  
    File file = SPIFFS.open("/text.txt");
    if(!file)
    {
        Serial.println("Failed to open file for reading");
        return;
    }
  
    Serial.println("File Content:");
    while(file.available())
    {
        Serial.write(file.read());
    }
    file.close();
}
 
void
loop(void)
{
}
