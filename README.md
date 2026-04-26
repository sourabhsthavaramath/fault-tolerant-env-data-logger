# Fault-Tolerant Environmental Data Logger

> STM32-based embedded system for temperature monitoring with RTC timestamping, EEPROM backup, and Wi-Fi data transmission.

---

## 📌 Overview

This project reads temperature using an LM35 sensor, timestamps it using DS1307 RTC, and ensures reliable data logging using EEPROM during network failures. Data is transmitted using ESP8266 when internet is available.

---
⚙️ Features

* LM35 temperature sensing (ADC)
* DS1307 RTC (I2C)
* EEPROM backup storage
* ESP8266 Wi-Fi communication (UART)
* LCD display
* Fault-tolerant data logging

---

## 🔄 Workflow

1. Read time from RTC
2. Read temperature from LM35
3. Check internet status
4. Store data in EEPROM if offline
5. Send data when online

---

## 🛠️ Tech Stack

* Embedded C
* STM32 HAL
* I2C, UART, ADC

---

## 🔐 Wi-Fi Setup

```c
#define WIFI_SSID       "YOUR_SSID"
#define WIFI_PASSWORD   "YOUR_PASSWORD"
```

---

## 📜 Note

This project is based on an academic template and enhanced with fault-tolerant logging and Wi-Fi integration.

---
