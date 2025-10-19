#include <Arduino.h>
#line 1 "C:\\Users\\Titania\\Desktop\\isaac\\test\\LL_control\\LL_TX\\LL_TX.ino"
#include <RadioHead.h>
#include <RH_ASK.h>

RH_ASK driver;
#define DEBOUNCE_DELAY 40

void RF_TX(char msg1);

#line 9 "C:\\Users\\Titania\\Desktop\\isaac\\test\\LL_control\\LL_TX\\LL_TX.ino"
void setup();
#line 20 "C:\\Users\\Titania\\Desktop\\isaac\\test\\LL_control\\LL_TX\\LL_TX.ino"
void loop();
#line 9 "C:\\Users\\Titania\\Desktop\\isaac\\test\\LL_control\\LL_TX\\LL_TX.ino"
void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);


    if (!driver.init()) {
        Serial.println("Errore durante l'inizializzazione del modulo RF.");
        while (1);
    }
}

void loop() {
    if (Serial.available() > 0) {
        char input = Serial.read();

        while (input == '\n' || input == '\r') {
            if (Serial.available() > 0) {
                input = Serial.read();
            }
        }





        if (input == 'w' || input == 'W') {RF_TX('w'); }

        if (input == 'a' || input == 'A') { RF_TX('a'); }

        if (input == 's' || input == 'S') { RF_TX('s');}

        if(input == 'd' || input == 'D'){ RF_TX('d'); }


        if(input == 'k' || input == 'K'){ RF_TX('k'); }

        if(input == 'l' || input == 'L'){ RF_TX('l'); }

        if(input == 'j' || input == 'J'){ RF_TX('j'); }


        if(input == 't' || input == 'T'){ RF_TX('t'); }

        if(input == 'y' || input == 'Y'){ RF_TX('y'); }

        if(input == 'g' || input == 'G'){ RF_TX('g'); }

        if(input == 'h' || input == 'H'){ RF_TX('h'); }

        if(input == 'f' || input == 'F'){ RF_TX('f'); }

        if(input == 'c' || input == 'C'){ RF_TX('c'); }

        if(input == 'v' || input == 'V'){ RF_TX('v'); }

        if(input == 'b' || input == 'B'){ RF_TX('b'); }


    }

    delay(DEBOUNCE_DELAY);
}

void RF_TX(char msg1) {
    uint8_t data[] = {msg1};
    bool success = driver.send(data, sizeof(data));
    if (success) {
        driver.waitPacketSent();

    }

    return;
}

