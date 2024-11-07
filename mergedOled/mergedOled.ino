#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <chipl_Anim.h>
#include <AMTeK_Logo.h>
#include <patient_Onboard.h>
#include <oxygen_Screen.h>
#include <Aqi_Screen.h>
#include <Temp_Screen.h>
#include <Hum_Screen.h>
#include <Alc_Screen.h>

#define postSwitch 4
#define data 18

int count = 0;
int loopSwitchVal = 0;
int switchState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(data, INPUT);
  pinMode(postSwitch, INPUT);
  
  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    // for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer.
  display.clearDisplay();

  boot();
}

void loop() {
  Serial.println(F("Loop entered"));
  loopSwitchVal = digitalRead(data);
  switchState = digitalRead(postSwitch);
  Serial.println(switchState);
  if(switchState == 1)
  {
    if (count == 0)
    {
      firstndhalfScreen();
      delay(1000);
      count++; 
    }
    Serial.println(loopSwitchVal);
    if(loopSwitchVal == 1)
    {
      switch(count)
      {
        case 1:
          secondScreen( 25.0 );
          count++;
          break;
        case 2:
          thirdScreen("Good");
          count++;
          break;
        case 3:
          thirdScreeneco(440);
          count++;
          break;
        case 4:
          thirdScreenvoc(440);
          count++;
          break;
        case 5:
          fourthScreen(25.0);
          count++;
          break;
        case 6:
          fifthScreen(70.0);
          count++;
          break;
        case 7:
          sixthScreen("High");
          count = 1;
          break;
        default:
          firstScreen();
          break;
      }
    }
    else
    {
      secondScreen( 25.0 );
    }
  }
  else
  {
    firstScreen();
    count = 0;
  }
  delay(1000);
  
}
