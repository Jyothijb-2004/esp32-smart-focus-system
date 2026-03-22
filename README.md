# ESP32 Smart Focus Environment System

# Overview
This project is an IoT-based system built using ESP32 that monitors environmental conditions such as temperature and humidity. It evaluates a "Focus Score" using a lightweight decision model and classifies the environment for productivity.

# Features
- Real-time temperature & humidity monitoring
- Focus score calculation (heuristic model)
- Environment classification (Good / Moderate / Poor)
- Cloud integration using ThingSpeak
- Alert system using LED

# Tech Stack
- ESP32
- Arduino C/C++
- ThingSpeak API
- Wokwi Simulation

# How It Works
Sensor data is collected using DHT22 → processed using scoring logic → sent to ThingSpeak → visualized on dashboard.

# Data Fields
- Field 1: Temperature
- Field 2: Humidity
- Field 3: Focus Score
- Field 4: Status Code

# Future Improvements
- Add TinyML model for prediction
- Mobile notification system
- Real-time control system
