# Plant Monitoring System

This project implements a simple plant monitoring system that measures temperature and humidity using a DHT11 sensor. The system uses an LCD display to show the current temperature and humidity readings. A buzzer sounds an alert if a certain condition is met, and an LED is used to indicate the status of the system.

## Features

- **Temperature and Humidity Monitoring**: Measures temperature (Celsius and Fahrenheit) and humidity using the DHT11 sensor.
- **LCD Display**: Displays the temperature and humidity readings on a 16x2 LCD screen.
- **Buzzer**: Alerts with a buzzer when a certain condition (sensor reading) is met.
- **LED Indicator**: Lights up an LED based on sensor values.
- **Real-time Monitoring**: Continuous measurement with updates displayed every 2 seconds.

## Components Needed

- **DHT11 Temperature and Humidity Sensor**
- **NodeMCU or ESP8266** (or any microcontroller with digital I/O pins)
- **16x2 LCD Display with I2C Interface**
- **Buzzer**
- **LED**
- **Resistors (for LED and Buzzer)**
- **Jumper Wires**
- **Breadboard** (optional for testing)

## Circuit Diagram

- **DHT11 Sensor**: Connect the VCC pin to 3.3V, GND to ground, and the DATA pin to D3 on the NodeMCU (or your microcontroller).
- **LCD**: Connect the SDA pin to D2 and SCL to D1 on the NodeMCU (or the respective pins on your microcontroller). Connect VCC and GND pins to 3.3V and GND, respectively.
- **Buzzer**: Connect one pin to D6 and the other to GND.
- **LED**: Connect the positive leg of the LED to D7 and the negative leg to GND (through a current-limiting resistor if necessary).
- **Button or Sensor for Input**: Connect D4 and D5 to the appropriate sensors or buttons.

## Code Explanation

### Libraries

```cpp
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```
