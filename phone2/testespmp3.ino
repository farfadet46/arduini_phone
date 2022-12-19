
//#include <DFPlayer_Mini_Mp3.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

//#define PIN_BUSY A0
int lecture = 0;

SoftwareSerial mp3Serial(D3, D4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup () {
  mp3Serial.begin(9600);
  Serial.begin(115200);
  if (!myDFPlayer.begin(mp3Serial, false)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(200); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  Serial.println("starting...");

  int valeur = myDFPlayer.readFileCounts();
  Serial.println(valeur);
}

void loop () {
 //Serial.println(lecture);
 if(lecture == 0 )
 {
  myDFPlayer.playMp3Folder(666);
  lecture = 1;
  Serial.println("écoute de la piste 666");
  }
}
