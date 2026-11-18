# Environmental Monitoring System - Test Results

## Testing Environment
Wokwi ESP32 Simulator

## Test Cases

| Test | Temperature | Humidity | Expected Result |
|---|---|---|---|
| 1 | 24°C | 40% | Normal |
| 2 | 32°C | 40% | Alert |
| 3 | 25°C | 75% | Alert |
| 4 | 35°C | 80% | Alert |
| 5 | 28°C | 60% | Normal |

## Expected Behaviour
- OLED displays temperature and humidity.
- LED turns ON when temperature is >= 30°C.
- LED turns ON when humidity is >= 70%.
- LED remains OFF when both readings are below their limits.

## Testing Notes
- Simulation used for testing.
- Physical hardware testing not performed.
