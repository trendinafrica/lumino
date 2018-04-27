unsigned long interval=1000; // the time we need to wait
unsigned long previousMillis=0;


   unsigned long currentMillis = millis();
 
   // time to toggle LED on Pin 12?
   if ((unsigned long)(currentMillis - previousMillisLED12) >= intervalLED12) {
      LED12state = !LED12state;
      digitalWrite(12, LED12state);
      // save current time to pin 12's previousMillis
      previousMillisLED12 = currentMillis;
   }
 
// time to toggle LED on Pin 13?
  if ((unsigned long)(currentMillis - previousMillisLED13) >= intervalLED13) {
      LED13state = !LED13state;
      digitalWrite(13, LED13state);
      // save current time to pin 12's previousMillis
      previousMillisLED13 = currentMillis;
  }


if(distance < 10 && distance > 5)
{
  Presence = 1;
  
}

if(distance >= 10 || distance <= 5)
{
  Presence = 0;
  
}


