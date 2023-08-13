#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include <IRremote.h>
#include <Keyboard.h>

const int RECV_PIN = 9;
// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiWire oled;

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup()
{
  Serial.begin(9600);

  Wire.begin();
  Wire.setClock(400000L);

#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0

  oled.setFont(Adafruit5x7);
  
  delay(2000);
  oled.clear();
  oled.set1X();      // Normal 1:1 pixel scale

  oled.setCursor(0,0);
  oled.println("leumas.Tech");


  
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5 ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6 ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN ");
    }
    Serial.print("  ");
    Serial.print(results.value, HEX);

    switch(results.value)
    {

      case 0xF7C03F : printstring("Hello from button 1"); break;
      case 0xF740BF : openapp("Google Chrome"); break;
      case 0xF7807F : searchWebFor("Google Chrome", "https://www.leumas.tech"); break;
      
      case 0xF700FF : keyshortcut2(KEY_LEFT_CTRL, 'V'); break; // Example for paste
      case 0xF7E01F : keyshortcut3(KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_DELETE); break; 
      case 0xF7609F : printstringenter("testing 1"); break;
//-------------------------------------------------
      case 0xFF18E7 : Keyboard.print("test string"); break;
      case 0xFF9867 : Keyboard.print("test string"); break;
      case 0xFF58A7 : Keyboard.print("test string"); break;
      case 0xFFD827 : Keyboard.print("test string"); break;

    }
    Serial.print("  ");
    Serial.println(results.bits);

    // Display IR code on OLED
    oled.clear();
    oled.setCursor(0,0);
    oled.println("IR Signal Received");
    oled.setCursor(0,10);
    oled.print("Code: ");
    oled.print(results.value, HEX);
    
    irrecv.resume(); // Receive the next value
  }
}



// 1. Print string
void printstring(String str) {
  Keyboard.print(str); 
  delay(1000); 
}

// 2. Print string and press Enter
void printstringenter(String str) {
  Keyboard.print(str); 
  delay(500); 
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

// 3. Open app
void openapp(String appname) {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(appname);
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

// 4. Search web for
void searchWebFor(String browser, String url) {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(browser);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();
  Keyboard.print(url);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();
}

// 5. Key shortcut with 2 keys
void keyshortcut2(uint8_t key1, uint8_t key2) {
  Keyboard.press(key1);
  Keyboard.press(key2);
  Keyboard.releaseAll();
}

// 6. Key shortcut with 3 keys
void keyshortcut3(uint8_t key1, uint8_t key2, uint8_t key3) {
  Keyboard.press(key1);
  Keyboard.press(key2);
  Keyboard.press(key3);
  Keyboard.releaseAll();
}

// 7. Key shortcut with 4 keys
void keyshortcut4(uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4) {
  Keyboard.press(key1);
  Keyboard.press(key2);
  Keyboard.press(key3);
  Keyboard.press(key4);
  Keyboard.releaseAll();
}
