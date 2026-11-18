# ESP32 Environmental Monitoring System

## Project Overview
The ESP32 Environmental Monitoring System measures temperature and humidity using a DHT22 sensor. The readings are displayed on an OLED screen. An LED indicator alerts users when the temperature or humidity exceeds the predefined limits.

## Objectives
- Monitor environmental temperature.
- Measure relative humidity.
- Display sensor readings on an OLED display.
- Generate an alert when predefined thresholds are exceeded.

## Components Used
- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- SSD1306 OLED Display (128×64)
- Red LED
- 220Ω Resistor
- Wokwi Simulator

## Software and Libraries
- Arduino C++
- Wokwi
- DHT sensor library for ESPx
- Adafruit SSD1306
- Adafruit GFX Library
- Adafruit BusIO

## Working Principle
1. The DHT22 sensor measures temperature and humidity.
2. ESP32 reads the sensor values.
3. The OLED displays the readings.
4. If temperature reaches 30°C or humidity reaches 70%, the LED turns ON.
5. Otherwise, the LED remains OFF.

## Threshold Conditions
- Temperature: 30°C
- Humidity: 70%

## Simulation
Open ESP32 Environmental Monitoring Simulation: https://wokwi.com/projects/480939037016287233

## Testing Environment
Wokwi ESP32 Simulator.

**Note:** This project was developed and tested using simulation. Physical hardware testing has not been performed.

## Future Improvements
- Wi-Fi connectivity
- Cloud data monitoring
- Live environmental dashboard
- Historical data logging

## Author
ECE Student | Embedded Systems and IoT Enthusiast
