# 🚗 EMO DRIVE  
## Emotion-Aware Driver Monitoring System

---

## 📌 Overview  
**EMO DRIVE** is an intelligent driver safety system that monitors a driver's **emotional and physiological state in real-time** using sensors and AI analysis.

It combines **hardware (Arduino UNO + sensors)** with a **software backend (Python + AI + APIs)** to detect unsafe driving conditions like **drowsiness, stress, anxiety, alcohol influence, and poor air quality**.

The system doesn’t just detect — it **reacts instantly** using actuators (vibration motor, water spray pump) and generates a **detailed AI safety report** after each session.

---

## 🎯 Objective  
The goal of this project is to:

- 🚗 Improve driver safety using real-time monitoring  
- 🧠 Detect emotional and physical states of the driver  
- ⚠️ Prevent accidents caused by fatigue, stress, or alcohol  
- 📊 Generate intelligent post-drive safety analysis  
- 🌐 Integrate IoT + AI + Environmental data  

---

## ⚙️ Key Features  

- 🧠 Emotion detection (Calm, Angry, Drowsy, Anxiety, Alcohol)  
- ❤️ Heart rate & 🌡️ temperature monitoring  
- 👁️ Blink detection for drowsiness  
- 🌫️ Gas sensor for alcohol / air quality detection  
- 📍 Location-based weather & AQI integration  
- ⚡ Real-time alerts using actuators  
- 📊 AI-generated driving safety report  
- 🌐 Web dashboard for live monitoring  

---

## 🧠 Working Principle  

The system continuously reads sensor data and classifies driver state:

- Sensors collect **BPM, temperature, blink rate, gas levels**
- Data is processed using predefined thresholds
- Driver emotion/state is derived:
  - Low BPM + low blink → **Drowsy**
  - High BPM + high temp → **Angry**
  - High gas → **Alcohol detected**
  - High blink + BPM → **Anxiety**
- Based on detected state:
  - ⚡ Vibration motor alerts driver (stress/anger)
  - 💧 Water pump sprays water (drowsiness)
- Data is sent to backend server
- AI analyzes session and generates **safety report**

---

## 🔌 Hardware Components  

- Arduino UNO  
- Heart Rate Sensor  
- Temperature Sensor  
- MQ Gas Sensor  
- IR Blink Sensor  
- Vibration Motor  
- DC Water Pump  
- Relay Module  
- Power Supply  
- IRFZ44N MOSFET  
- BC547 Transistor  
- Resistors & Jumper Wires  

---

## ⚙️ Role of Each Component  

### ❤️ Heart Rate Sensor  
- Measures BPM  
- Detects stress, anxiety, anger  

---

### 🌡️ Temperature Sensor  
- Detects body temperature  
- Helps identify stress/anger conditions  

---

### 🌫️ MQ Gas Sensor  
- Detects alcohol or harmful gases  
- Triggers **alcohol detection mode**  

---

### 👁️ IR Blink Sensor  
- Tracks eye blinking  
- Low blink rate → drowsiness detection  

---

### ⚡ Vibration Motor  
- Activates during **stress/anger**  
- Provides instant physical alert  

---

### 💧 DC Water Pump  
- Activates during **drowsiness**  
- Sprays water to wake driver  

---

### 🔌 IRFZ44N MOSFET  
- Drives high-power devices (motor/pump)  
- Acts as electronic switch  

---

### 🔀 BC547 Transistor  
- Used for signal amplification  
- Controls actuator triggering  

---

### 🔁 Relay Module  
- Safely switches high voltage/current devices  

---

## 🔧 Pin Configuration (Example)

| Component            | Pin |
|---------------------|-----|
| Heart Rate Sensor   | A0  |
| Temperature Sensor  | A1  |
| MQ Gas Sensor       | A2  |
| IR Blink Sensor     | D2  |
| Vibration Motor     | D3  |
| Water Pump (Relay)  | D4  |

---

## 🎥 Project Demonstration  

👉 [Watch Demo Video](https://drive.google.com/file/d/1v7m25400VcF0xIKQ1GUie3EA5uwwX5fN/view?usp=drivesdk)

---

## 🖥️ Software Architecture  

### 🔹 Backend (Python Flask)
- Handles sensor data  
- Manages session  
- Calculates safety score  
- Generates AI report  

### 🔹 AI Integration
- Uses NVIDIA NIM API (LLaMA model)  
- Provides:
  - Fitness to drive  
  - Risk analysis  
  - Recommendations  
  - Law-based suggestions  

### 🔹 APIs Used
- 🌦️ OpenWeather API → Weather data  
- 🌫️ AQI API → Air quality  
- 🗺️ OpenStreetMap → Road & location data  

---

## 📊 System Output  

- Real-time dashboard  
- Emotion state display  
- Sensor graphs  
- Final report includes:
  - Safety score  
  - Emotion breakdown  
  - AI recommendations  
  - Driving fitness verdict  

---

## 🧪 Observations  

- Drowsiness detected using blink + BPM  
- Stress conditions reflected via heart rate & temperature  
- Alcohol detection triggers immediate warning  
- Environmental data improves safety analysis  
- AI report gives human-like feedback  

---

## 🚀 Applications  

- 🚗 Smart vehicle safety systems  
- 🚛 Fleet driver monitoring  
- 🚕 Ride-sharing safety systems  
- 🏭 Industrial operator monitoring  
- 🧠 Health-aware driving systems  
- 🤖 Future autonomous vehicles  

---

## ✅ Result  

- Successfully built a **real-time driver monitoring system**  
- Achieved **emotion-based detection**  
- Implemented **automatic safety alerts**  
- Generated **AI-based driving analysis reports**  
- Integrated **hardware + software + AI + IoT**  

---

## 🔮 Future Scope  

- 📱 Mobile app integration  
- 📷 Camera-based emotion detection  
- ☁️ Cloud data storage  
- 🤖 Machine learning model improvement  
- 🚗 Smart vehicle integration  
- 🔊 Voice assistant alerts  

---

## 🧠 Key Concepts Used  

- Embedded Systems (Arduino UNO)  
- IoT Systems  
- Emotion Detection  
- Real-Time Monitoring  
- AI Report Generation  
- Flask Backend Development  
- Environmental Data Integration  

---

## 👨‍💻 Author  

**Tharun S**

---

## ⭐ If you like this project  

Give it a ⭐ on GitHub!
