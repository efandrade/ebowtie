#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUM_LEDS 94
#define BRIGHTNESS 10

//Button global variables
const int buttonPin1 = 2;
const int buttonPin2 = 3;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonCounter1 = 0;
int buttonCounter2 = 0;

int buttonResult = 0;


int showNumber = 2;
int brightNumber = 5;


int brightnessLevels[4] = { 55, 70, 85, 100 };
int bowtieShape [8][17] = { {1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
                            {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
                            {1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1},
                            {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
                            {1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1} };
                           
int bowtieInd [8][17];
int screen [8][17];
int k = 0;
int l = 0;
        
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //int k = 0;

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  //for ( int m = 0; m < 5; m++) {
  //Serial.begin(9600);
  //Serial.print("hello");
  //}  

  /*for ( int j = 0; j < 17; j++ ) {
    for ( int i = 7; i >= 0 ; i-- ) {
      screen[i][j] = l;
      l++;
      if ( bowtieShape[i][j] == 1 ) {
        bowtieInd [i][j] = k;
        k++;
      }
    }
  }*/
  
  
  
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'   buttonState1 = digitalRead(buttonPin1);
   
  //strip.clear();
}

void loop() {
  
  
   //buttonState1 = digitalRead(buttonPin1);
   //buttonState2 = digitalRead(buttonPin2);
   
  
  //strip.setPixelColor(45,strip.Color(0,255,0,50));
  //joker(10);
  //strip.show();
  //Serial.print("test");
  //Serial.print('\n');
  //Serial.print(bowtieInd[0][0]);
  if (buttonCounter1 == 0) {
    colorAllPixels( 50, 25 , 100);
    //rainbow(5);
  }
  else if (buttonCounter1 == 1) {
    colorAllPixels( 90, 0 , 160);
    //joker(10);
  }
  else if (buttonCounter1 == 2 ) {
    colorAllPixels( 160, 0, 90);
  }
  //delay(10);
  
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j)));
      //buttonResult = buttonPressed;
      if (buttonPressed() == 1) {
        return;
      }
      
   /*strip.setPixelColor(10,255,255,255);
   strip.setPixelColor(17,255,255,255);
   strip.setPixelColor(28,255,255,255);
   strip.setPixelColor(27,255,255,255);
   strip.setPixelColor(26,255,255,255);
   strip.setPixelColor(25,255,255,255);
   
   int m = 55;
   
   strip.setPixelColor(m+10,255,255,255);
   strip.setPixelColor(m+16,255,255,255);
   strip.setPixelColor(m+28,255,255,255);
   strip.setPixelColor(m+27,255,255,255);
   strip.setPixelColor(m+26,255,255,255);
   strip.setPixelColor(m+25,255,255,255);*/
      
      
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}

void joker(int wait) {
  int J [5][19] = { {0,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0},
                    {0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1},
                    {0,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,1,0},
                    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1},
                    {0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1} };
   int pos [2] = {2,0};
   
   for (int i = 17; i >=-19; i--) {
     colorAllPixels(190,0,60);
     pos[1] = i;
     place(J,pos);
     strip.show();
     delay(200);
     strip.clear();
     
     if (buttonPressed() == 1) {
        return;
     }
   }
  
}

void place(int letter[5][19],int *loc) {
  //Serial.print(bowtieInd[loc[0]][loc[1]]);
  
  int num = 0;
  int x = 0;
  int y = 0;
  
  
  for (int i = 0; i < 5; i++) {
    
    for (int j = 0; j < 19; j++) {
      num = letter[i][j];
      //delay(100);
      if (num == 1 ) {
        x = loc[0] + i;
        y = loc[1] + j;
        
        if (( x <= 7) && ( x >=0 )) {
          if (( y <= 16) && ( y >=0 )) {
            if (bowtieShape[x][y] == 1) {
          strip.setPixelColor(bowtieInd[x][y],0,255,0);
          //Serial.print(bowtieInd[0][0]);
          //Serial.print('\n');
            }
          }
        }
      }
    }
  }
}
//int move(intitial,dir) {

void colorAllPixels( int r, int g, int b) {
  for( int i = 0; i < NUM_LEDS; i++ ) {
     strip.setPixelColor(i, r, g, b);
     if (buttonPressed() == 1) {
        return;
     }
  }
}

int buttonPressed() {
  
   buttonState1 = digitalRead(buttonPin1);
   buttonState2 = digitalRead(buttonPin2);
   
   //delay(1);
   
   if (buttonState1 == HIGH) {
     if (buttonCounter1 == showNumber) {
       buttonCounter1 == 0;
     }
     else {
       buttonCounter1++;
     }
     return 1;
    }
    
    if (buttonState2 == HIGH) {
     if (buttonCounter2 == brightNumber) {
       buttonCounter1 == 0;
     }
     else {
       buttonCounter2 = buttonCounter2 + 1;
     }
     return 2;
    }
    
   return 0;
}
