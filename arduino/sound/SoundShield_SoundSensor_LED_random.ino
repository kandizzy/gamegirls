#include <SPI.h>           // SPI library
#include <SdFat.h>         // SDFat Library
#include <SdFatUtil.h>     // SDFat Util Library
#include <SFEMP3Shield.h>  // Mp3 Shield Library

SdFat sd; // Create object to handle SD functions
SFEMP3Shield MP3player;

int led = 13; //LED test to SoundSensor//erase!!!
int threshold = 450; //Change This  SoundSensor
int volume; //SoundSendor
int tweets = 5;
int array [] = {"track001.mp3", "track002.mp3", "track003.mp3"};
long randNumber;


void setup() {

  Serial.begin(9600); // Serial port begin
  randomSeed(0);
  pinMode(led, OUTPUT); //LED test to SoundSensor//erase!!!

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

}

void loop() {
  //

  volume = analogRead(A0); // Reads the value from the Analog PIN A0

  if (volume >= threshold) {
    digitalWrite(led, HIGH); //Turn ON Led //LED test to SoundSensor//erase!!!
    //start playing track 1
    Serial.println("me too!");
    for (int j = 0; j < tweets ; j++) {
      randNumber = random(3);
      Serial.println(randNumber);

      MP3player.playMP3(array[randNumber]); // play track by file name.

      delay(2000);
      MP3player.stopTrack();

    }
  }
  else {
    digitalWrite(led, LOW); // Turn OFF Led //LED test to SoundSensor//erase!!!
  }


  Serial.println(volume); //to noise value
  delay(100);

}
