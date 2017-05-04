#include <VirtualWire.h>


int loopDetectedPin = 2; // Use Pin 3 as our Input
int loopDetectedVal = HIGH; // This is where we record our Sound Measurement
//boolean bAlarm = false;
//int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high

/*Variablen Section*//////////////
const char *msg = "220";  //SenderNummer
//////////////////////////////////

#undef int
#undef abs
#undef double
#undef float
#undef round

void setup()
{

 // Serial.begin(9600);
  pinMode (loopDetectedPin, INPUT) ; // input from the Sound Detection Module
  // Initialise the IO and ISR
  vw_set_ptt_inverted(true); // Required for RF Link module
  vw_setup(2000);                 // Bits per sec
  vw_set_tx_pin(A3);                // pin 3 is used as the transmit data out into the TX Link module, change this as per your needs

}

void loop()
{
  loopDetectedVal = digitalRead (loopDetectedPin) ; // read the sound alarm time
  if (loopDetectedVal == LOW) // If we hear a sound

  //  if (!bAlarm) {
//      Serial.println("msg");
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx();                                          // Wait for message to finish
//      bAlarm = true;
    }



//   delay(200);
//}



