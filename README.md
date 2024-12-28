# Plant Monitoring System

This project is a simple **Plant Monitoring System** that uses a **DHT11** temperature and humidity sensor to monitor environmental conditions and control a buzzer and LED based on user input. It displays the humidity and temperature readings on a **16x2 LCD** and provides feedback using a buzzer (for alerts) and an LED (to indicate status).

## Features

- **Temperature and Humidity Monitoring:**
  - Measures the **temperature** (in Celsius and Fahrenheit) and **humidity** of the environment using the **DHT11 sensor**.
  
- **Buzzer Feedback:**
  - The buzzer is activated based on a digital input (pin D4). When the input is LOW, the buzzer is off, and when it is HIGH, the buzzer is turned on with a short delay.

- **LED Feedback:**
  - An **LED** is controlled by a digital input on pin D5. If the input is LOW, the LED is off. When the input is HIGH, the LED turns on and blinks with a short delay.

- **LCD Display:**
  - The **16x2 LCD** displays the current **humidity** and **temperature** readings in real-time.

- **Heat Index Calculation:**
  - Computes and displays the **heat index** based on the temperature and humidity.

## Hardware Components

- **ESP8266/ESP32 Board** (e.g., NodeMCU or Wemos D1 mini)
- **DHT11 Temperature and Humidity Sensor**
- **16x2 LCD Display** with I2C interface
- **Buzzer**
- **LED**
- **Digital Input Pins (D4 and D5)** for user interaction

## Circuit Diagram

- **DHT11 Sensor:** 
  - `VCC` to 3.3V
  - `GND` to GND
  - `Data Pin` to D3 (GPIO0)
  
- **Buzzer:** Connected to D6.
- **LED:** Connected to D7.
- **Digital Inputs:**
  - **D4** for buzzer control (HIGH to activate buzzer, LOW to turn off).
  - **D5** for LED control (HIGH to turn on LED, LOW to turn off).

## Software Requirements

- **Arduino IDE**
- **DHT Sensor Library** for reading temperature and humidity values.
- **LiquidCrystal_I2C Library** for controlling the LCD display.

### Install Libraries

1. Go to **Sketch > Include Library > Manage Libraries** in the Arduino IDE.
2. Search and install the following libraries:
   - **DHT Sensor Library** (by Adafruit)
   - **LiquidCrystal_I2C** (for LCD control)

## Setup

1. Open the Arduino IDE and select the correct **Board** and **Port** for your ESP8266/ESP32.
2. Upload the code to your board after ensuring the wiring is correct.
3. Monitor the output using the **Serial Monitor** for debugging.

## Code Explanation

### Key Components:

- **DHT11 Sensor:** 
  - Measures the **temperature** and **humidity** of the surrounding environment.
  - The sensor data is read every 2 seconds, and the values are shown on both the **Serial Monitor** and the **LCD**.

- **Buzzer Feedback:**
  - The buzzer is controlled by the digital input pin D4. When the input is LOW, the buzzer is turned off. When it is HIGH, the buzzer is turned on with a short delay.
  
- **LED Feedback:**
  - The LED is controlled by the digital input pin D5. When the input is LOW, the LED is turned off. When it is HIGH, the LED blinks with a short delay.
  
- **Heat Index Calculation:**
  - The heat index is calculated both in **Celsius** and **Fahrenheit** and displayed on the LCD and the Serial Monitor.
  
- **LCD Display:**
  - The **LCD screen** displays the **humidity** and **temperature** readings in real-time, updating every 2 seconds.
  
### Code Flow:

1. The program initializes the **DHT11 sensor** and **LCD display**.
2. It continuously reads the **humidity** and **temperature** from the DHT11 sensor every 2 seconds.
3. It calculates the **heat index** using the temperature and humidity.
4. The **LCD** updates with the current humidity and temperature values.
5. The **Serial Monitor** outputs the sensor readings and heat index for debugging.
6. The **LED** and **buzzer** are controlled by digital inputs on pins D4 and D5, respectively.

### Error Handling:

- If the sensor readings fail (i.e., if they are `NaN`), the program prints an error message to the Serial Monitor.

## Troubleshooting

- **LCD not displaying properly:**
  - Ensure the I2C address of your LCD is correct (default is `0x27`).
  - Verify the wiring and ensure the LCD's backlight is working.

- **Buzzer not responding:**
  - Check the connection to pin D6 and ensure the buzzer is functional.

- **LED not turning on/off:**
  - Verify the input on pin D5 is correct, and check if the LED is connected properly to pin D7.

## License

This project is open-source and can be freely modified for personal or educational purposes.
