#include <M5StickC.h>
#include "key.h"

#define ANALOG_PIN 36
int val = 0;
bool existKey = false;
bool preExistKey = false;

// the setup routine runs once when M5StickC starts up
void setup(){
  // Initialize the M5StickC object
  M5.begin();
  M5.Axp.ScreenBreath(10); 
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setSwapBytes(false);

  M5.Lcd.fillScreen(BLACK);
}

// the loop routine runs over and over again forever
void loop() {
  M5.update();
  val = analogRead(ANALOG_PIN);

  // 鍵の有無判定
  if(val > 500){
    existKey = true;
  }else{
    existKey = false;
  }

  // 画面描画
  if(existKey && !preExistKey)
  {
    // 鍵がおかれた
    M5.Lcd.startWrite();
    M5.Lcd.pushImage(40, 0, imgWidth, imgHeight, img);
    // 描画終了
    M5.Lcd.endWrite();
  }else if(!existKey && preExistKey){
    M5.Lcd.fillScreen(BLACK);
  }

  // 状態の更新
  preExistKey = existKey;
  
  delay(1000);
}
