//Ref: http://yehnan.blogspot.tw/2013/01/arduinods18b20.html

// 匯入程式庫標頭檔
#include <OneWire.h>
#include <DallasTemperature.h>

// Arduino數位腳位2接到1-Wire裝置
#define ONE_WIRE_BUS 3

// 運用程式庫建立物件
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(115200);
  //Serial.begin(9600);
  Serial.println("Temperature Sensor");
  // 初始化
  sensors.begin();
  
  // Initial Led
  pinMode(13, OUTPUT);
}

void loop(void)
{
  // 要求匯流排上的所有感測器進行溫度轉換（不過我只有一個）
  sensors.requestTemperatures();

  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置
  Serial.println(sensors.getTempCByIndex(0));
  // blink led when we output the temperature data.
  blink_led();
  delay(1000);
}

void blink_led(void)
{
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
}

