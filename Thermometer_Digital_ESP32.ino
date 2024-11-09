#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define DHTPIN 4      
#define DHTTYPE DHT22       

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Termometer");
  display.setCursor(0, 20);
  display.print("Digital");
  display.setCursor(0, 40);
  display.print("by Yogengs");
  display.display(); 
  dht.begin();
  delay(4000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Suhu");
  display.setCursor(0, 15);
  display.print(String(temperature) + " *C");
  display.setCursor(0, 31);
  display.print("Kelembapan");
  display.setCursor(0, 46);
  display.print(String(humidity) + " %");
  display.display();
  delay(1000);
}
