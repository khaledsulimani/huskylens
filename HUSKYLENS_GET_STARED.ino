#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX
// HUSKYLENS green line >> Pin 10; blue line >> Pin 11
const int ledPin = 7;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    mySerial.begin(9600);
    while (!huskylens.begin(mySerial))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
}

void loop() {
    if (!huskylens.request()) {
        Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
        digitalWrite(ledPin, LOW);  // Turn off LED on failure
    }
    else if (huskylens.available()) {
        bool faceDetected = false;
        while (huskylens.available()) {
            HUSKYLENSResult result = huskylens.read();
            if (result.command == COMMAND_RETURN_BLOCK) {
                faceDetected = true;
                printResult(result);
            }
        }
        if (faceDetected) {
            digitalWrite(ledPin, HIGH);
            Serial.println("Face detected");
        } else {
            digitalWrite(ledPin, LOW);
            Serial.println("No face detected");
        }
    }
    else {
        digitalWrite(ledPin, LOW);
        Serial.println("No face detected");
    }
    
    delay(100); // Add small delay to prevent flooding
}

void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
}
}