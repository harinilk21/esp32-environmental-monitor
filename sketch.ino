#include <Wire.h>
#include <DHTesp.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin configuration
#define DHT_PIN 15
#define LED_PIN 2

#define SDA_PIN 21
#define SCL_PIN 22

// OLED configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

// Create sensor and display objects
DHTesp dhtSensor;

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// Environmental alert limits
const float TEMP_LIMIT = 30.0;
const float HUMIDITY_LIMIT = 70.0;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Initialize temperature sensor
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // Initialize I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize OLED
  if (!display.begin(
      SSD1306_SWITCHCAPVCC,
      OLED_ADDRESS))
  {
    Serial.println("OLED Error!");
    while (true)
    {
      delay(100);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("ENVIRONMENT MONITOR");
  display.println("System Starting...");
  display.display();

  Serial.println("Monitoring Started");

  delay(1500);
}

void loop()
{
  // Read temperature and humidity
  TempAndHumidity data =
      dhtSensor.getTempAndHumidity();

  float temperature = data.temperature;
  float humidity = data.humidity;

  // Check for invalid readings
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Sensor Error!");

    digitalWrite(LED_PIN, LOW);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("SENSOR ERROR");
    display.display();

    delay(2000);
    return;
  }

  // Check environmental conditions
  bool alert =
      (temperature >= TEMP_LIMIT ||
       humidity >= HUMIDITY_LIMIT);

  // LED control
  digitalWrite(LED_PIN, alert ? HIGH : LOW);

  // Serial Monitor output
  Serial.println("----------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  Serial.print("Status: ");

  if (alert)
    Serial.println("ALERT");
  else
    Serial.println("NORMAL");

  // OLED display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("ENVIRONMENT MONITOR");
  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  display.setCursor(0, 20);

  display.print("Temperature: ");
  display.print(temperature, 1);
  display.println(" C");

  display.println();

  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println(" %");

  display.println();

  display.print("Status: ");

  if (alert)
    display.println("ALERT!");
  else
    display.println("NORMAL");

  display.display();

  delay(2000);
}
