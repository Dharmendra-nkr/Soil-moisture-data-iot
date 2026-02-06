# Soil Moisture Monitoring IoT System

An ESP8266-based IoT system that monitors soil moisture levels in real-time and sends data to ThingSpeak cloud platform for visualization and analysis.

![ThingSpeak Dashboard](D:\GitREPOS\Soil_moisture_iot\images\thinkspeak_dashboard.png)
*Real-time soil moisture monitoring dashboard on ThingSpeak*

## 📋 Overview

This project implements an automated soil moisture monitoring system using ESP8266 microcontroller. The system reads moisture levels from a capacitive soil moisture sensor, displays the data on serial monitor, controls an LED/relay based on moisture threshold, and uploads the data to ThingSpeak cloud platform every 20 seconds for remote monitoring and analysis.

## ✨ Features

- **Real-time Monitoring**: Continuous soil moisture measurement using analog sensor
- **Cloud Integration**: Automatic data upload to ThingSpeak platform
- **Smart Control**: Automated LED/relay activation when moisture drops below 50%
- **WiFi Connectivity**: ESP8266 WiFi module for internet connectivity
- **Data Visualization**: CSV data exports from ThingSpeak for analysis
- **Serial Debugging**: Real-time status updates via serial monitor

## 🛠️ Hardware Requirements

- **ESP8266 Development Board** (NodeMCU/Wemos D1 Mini)
- **Capacitive Soil Moisture Sensor** (Analog output)
- **LED/Relay Module** (connected to D0 pin)
- **Jumper Wires**
- **USB Cable** for programming
- **WiFi Network**

## 📊 Pin Configuration

| Component | Pin |
|-----------|-----|
| Soil Moisture Sensor | A0 |
| LED/Relay Control | D0 |

## 🔧 Software Dependencies

```cpp
- ESP8266WiFi.h
- ThingSpeak.h
```

## 📁 Project Structure

```
Soil_moisture_iot/
├── main/
│   ├── main.ino          # Main Arduino sketch
│   └── secrets.h         # WiFi & ThingSpeak credentials (gitignored)
├── 1.csv                 # ThingSpeak data export
├── feeds.csv             # ThingSpeak feeds export
├── .gitignore            # Git ignore rules
└── README.md             # This file
```

## ⚙️ Setup Instructions

### 1. Hardware Setup
- Connect the soil moisture sensor's analog output to A0 pin
- Connect LED/relay module to D0 pin
- Connect VCC to 3.3V and GND to ground

### 2. Software Configuration

Create a `secrets.h` file in the `main/` directory with the following content:

```cpp
// WiFi credentials
#define SECRET_SSID "your_wifi_ssid"
#define SECRET_PASS "your_wifi_password"

// ThingSpeak credentials
#define SECRET_CH_ID 0000000  // Your channel ID
#define SECRET_WRITE_APIKEY "YOUR_WRITE_API_KEY"
```

### 3. ThingSpeak Setup
1. Create a free account at [ThingSpeak.com](https://thingspeak.com)
2. Create a new channel
3. Add Field 1 with label "Moisture_level"
4. Copy your Channel ID and Write API Key to `secrets.h`

### 4. Upload Code
1. Open `main/main.ino` in Arduino IDE
2. Select board: **ESP8266** (NodeMCU 1.0 or your variant)
3. Select correct COM port
4. Upload the sketch

## 🚀 How It Works

1. **Sensor Reading**: The capacitive soil moisture sensor measures soil moisture via analog signal (0-1023)
2. **Conversion**: Raw analog value is converted to percentage (0-100%)
   - Formula: `moisture = 100.0 - ((raw / 1023.0) * 100.0)`
3. **Threshold Control**: If moisture ≤ 50%, LED/relay turns ON (LOW state)
4. **WiFi Connection**: ESP8266 connects to WiFi network
5. **Cloud Upload**: Moisture data is sent to ThingSpeak every 20 seconds
6. **Data Logging**: ThingSpeak stores and visualizes the data in real-time

## 📈 Data Analysis

The project includes CSV exports from ThingSpeak:
- **1.csv**: Contains timestamp, entry ID, and moisture level readings
- **feeds.csv**: Complete feed data with additional metadata

Sample data shows moisture levels ranging from -0.09% to ~40%, with measurements taken every 20-22 seconds.

## 🔍 Serial Monitor Output

```
=== ESP8266 START ===
Raw: 550 | Moisture: 46.23%
Connecting to WiFi: YourSSID
WiFi Connected
ThingSpeak update SUCCESS
--------------------
```

## 📱 Monitoring Your Data

Access your ThingSpeak channel to:
- View real-time graphs
- Export historical data
- Set up alerts and notifications
- Integrate with MATLAB for advanced analysis
- Create public/private visualizations

## 🎯 What Was Accomplished

This project successfully implements:
- ✅ ESP8266-based IoT sensor node
- ✅ Real-time soil moisture monitoring
- ✅ WiFi connectivity and cloud integration
- ✅ ThingSpeak data uploading and storage
- ✅ Automated irrigation control logic (LED/relay)
- ✅ Data collection and CSV exports
- ✅ Git version control with proper .gitignore
- ✅ Secure credential management

## 🔐 Security

The `secrets.h` file containing WiFi credentials and API keys is excluded from version control via `.gitignore` to protect sensitive information.

## 📝 Future Enhancements

- Add multiple sensor support
- Implement deep sleep for battery operation
- Add SMS/email notifications
- Create mobile app integration
- Add temperature and humidity sensors
- Implement automatic watering system

## 📄 License

This project is open-source and available for educational and personal use.

## 👨‍💻 Author

Dharmendra

## 🔗 Links

- [ThingSpeak Platform](https://thingspeak.com)
- [ESP8266 Documentation](https://arduino-esp8266.readthedocs.io/)
- [Project Repository](https://github.com/Dharmendra-nkr/Soil-moisture-data-iot)

---

**Note**: Remember to update the ThingSpeak dashboard image by placing your screenshot in `images/thingspeak_dashboard.png`
