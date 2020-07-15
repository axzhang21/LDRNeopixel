#include <Adafruit_NeoPixel.h>
#define LED_PIN 9
#define LED_COUNT 10
#define LDR_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  strip.begin();
  strip.show();
}

void loop() 
{
  int input = analogRead(LDR_PIN);
  int brightness =map(input, 0, 1023, 0, 255);
  Serial.println(input);
  Serial.println(brightness);

  //tedious->for loop(s)/function(s)?
  colorFlow(strip.Color(255, 0, 0), brightness);//red
  colorFlow(strip.Color(255, 50, 0), brightness);//red-orange
  colorFlow(strip.Color(255, 100, 0), brightness);//orange-red
  /*colorFlow(strip.Color(255, 150, 0), brightness);//orange
  colorFlow(strip.Color(255, 200, 0), brightness);//yellow
  colorFlow(strip.Color(255, 250, 0), brightness);//bright-yellow
  colorFlow(strip.Color(200, 255, 0), brightness);//yellow-green
  colorFlow(strip.Color(150, 255, 0), brightness);//green-yellow
  colorFlow(strip.Color(100, 255, 0), brightness);//green
  colorFlow(strip.Color(50, 255, 0), brightness);//still green...
  colorFlow(strip.Color(0, 255, 50), brightness);//green
  colorFlow(strip.Color(0, 255, 100), brightness);//green-blue
  colorFlow(strip.Color(0, 255, 150), brightness);//light blue
  colorFlow(strip.Color(0, 255, 200), brightness);//
  colorFlow(strip.Color(0, 255, 250), brightness);//
  colorFlow(strip.Color(0, 200, 255), brightness);//getting darker...
  colorFlow(strip.Color(0, 150, 255), brightness);//
  colorFlow(strip.Color(0, 100, 255), brightness);//
  colorFlow(strip.Color(0, 0, 255), brightness);//darkest blue
  colorFlow(strip.Color(50, 0, 255), brightness);//getting purple...
  colorFlow(strip.Color(100, 0, 255), brightness);//
  colorFlow(strip.Color(150, 0, 255), brightness);//
  colorFlow(strip.Color(200, 0, 255), brightness);//turning lighter and into pink?
  colorFlow(strip.Color(255, 0, 255), brightness);//
  colorFlow(strip.Color(255, 0, 200), brightness);//
  colorFlow(strip.Color(255, 0, 150), brightness);//
  colorFlow(strip.Color(255, 0, 100), brightness);//
  colorFlow(strip.Color(255, 0, 50), brightness);//*/

  
}

void colorFlow(uint32_t color, int wait)
{
  for(int i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i, color);
    strip.show();
    delay(100);
  }
}
