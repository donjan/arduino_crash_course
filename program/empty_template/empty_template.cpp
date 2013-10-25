// Author:  Mario S. Könz <mskoenz@gmx.net>
// Date:    15.10.2013 01:07:01 CEST
// File:    empty template.cpp

#include <Arduino.h>

int led = 13;

class program {
public:
    program() : pin_(13) , btn_(2){
        setup();
    }
    void setup() {
        Serial.begin(460800);
        Serial.println("Foo");
        pinMode(btn_, INPUT_PULLUP);
        pinMode(pin_, OUTPUT);
        //~ digitalWrite(pin_, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    void loop() {
        digitalWrite(pin_, !digitalRead(btn_));
    }
private:
    int const pin_;
    int const btn_;
};

#include <main.hpp>
