
#include <RadioHead.h>
#include <RH_ASK.h>
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "Debug.h"

RH_ASK driver;


 float HN = 4;
 float MN = 2.5;
 float LN = 2;
 int tx_delay = 10;

void setup()
{
    Serial.begin(115200);
    if (!driver.init())
    {
        Serial.println("Inizializzazione del modulo RF fallita");
    }
}

void loop()
{
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen))
    {
        Serial.print("Messaggio ricevuto: ");

        switch (buf[0])
        {
        case 'w':
           

            break;
        case 'a':
            
            break;
        

        default:
       
        break;
        }
    }
    else
    {
       
    }

    delay(10);
}

