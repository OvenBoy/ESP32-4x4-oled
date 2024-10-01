#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Keypad.h>


#define SCREEN_WIDTH 128  // OLED width,  in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels

// #define BUTTON_PIN 18
#define SHORT_PRESS_TIME 300

//keypad variables
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {15, 4, 16, 17}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 18, 19, 23}; //connect to the column pinouts of the keypad

//changing variables
int lastState = LOW;
int currentState;
unsigned long pressTime = 0;
unsigned long releaseTime = 0;
bool isPressing = false;
bool isLongPress = false;

int screenIdx = 0;

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1)
      ;
  }

  delay(2000);          // wait two seconds for initializing
  oledInit();

  // pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  char key = keypad.getKey();
  
  switch(key){
    case 0:
      Serial.println("0");
      break;
    case 1:
      Serial.println("1");
      break;
    case 2:
      Serial.println("2");
      break;
    case 3:
      Serial.println("3");
      break;
    case 4:
      Serial.println("4");
      break;
    case 5:
      Serial.println("5");
      break;
    case 6:
      Serial.println("6");
      break;
    case 7:
      Serial.println("7");
      break;
    case 8:
      Serial.println("8");
      break;
    case 9:
      Serial.println("9");
      break;
    case "A":
      Serial.println("UP");
      break;
    case "B":
      Serial.println("SELECT");
      break;
    case "C":
      Serial.println("C");
      break;
    case "D":
      Serial.println("LEFT");
      break;
    case "E":
      Serial.println("DOWN");
      break;
    case "F":
      Serial.println("RIGHT");
      break;

      
  }

  delay(10);
  
  // if(lastState == HIGH && currentState == LOW){
  //   pressTime = millis(); //read ms of btn down
  //   isPressing = true;
  //   isLongPress = false;
  // }
  // else if(lastState == LOW && currentState == HIGH){
  //   isPressing = false;
  //   releaseTime = millis(); //read ms of btn up
    
  //   long pressDuration = releaseTime - pressTime;

  //   if(pressDuration < SHORT_PRESS_TIME && isLongPress == false){
  //     Serial.println("short");
  //     displayNextScreen(screenIdx);
  //   }
  // }

  // if(isPressing == true && isLongPress == false){
  //   long pressDuration = millis() - pressTime;

  //   if(pressDuration > SHORT_PRESS_TIME){
  //     Serial.println("long");
  //     isLongPress = true;
  //     displaySelectScreen();
  //   }
  // }


  // lastState = currentState;

}

void oledInit(){
  oled.clearDisplay();  // clear display

  oled.setTextSize(1.1);     // set text size
  oled.setTextColor(WHITE);  // set text color
  oled.setFont(&FreeMono12pt7b);
  oled.setCursor(0, 15);     // set position to display (x,y)
  oled.println("Screen 0");  // set text
  oled.display();               // display on OLED
}

/*
=====DISPLAY METHODS=========
*/
void displayNextScreen(int index){
  if(screenIdx == 0){
    displayScreen1();
    screenIdx++;
    return;
  }
  else if(screenIdx == 1){
    displayScreen2();
    screenIdx++;
    return;
  }
  else if(screenIdx == 2){
    displayScreen0();
    screenIdx = 0;
    return;
  }
}

void displayScreen0() {
  oled.setCursor(0, 15);     // set position to display (x,y)
  oled.clearDisplay();
  oled.println("Screen 0");  // set text
  oled.display();               // display on OLED
}

void displayScreen1() {
  oled.setCursor(0, 15);     // set position to display (x,y)
  oled.clearDisplay();
  oled.println("Screen 1");  // set text
  oled.display();               // display on OLED
}

void displayScreen2() {
  oled.setCursor(0, 15);     // set position to display (x,y)
  oled.clearDisplay();
  oled.println("Screen 2");  // set text
  oled.display();               // display on OLED
}

void displaySelectScreen() {
  oled.setCursor(0, 15);     // set position to display (x,y)
  oled.clearDisplay();
  oled.println("Screen L");  // set text
  oled.display();               // display on OLED
}
