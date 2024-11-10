Hand Gesture Controlled Car using Arduino Nano, MPU6050, and nRF24L01
This project involves building a hand gesture-controlled car using Arduino Nano, MPU6050 (accelerometer + gyroscope), nRF24L01 transceivers, and an optional ultrasonic sensor for obstacle detection. The car's movement is controlled by the user's hand gestures, detected through the MPU6050 sensor and transmitted via the nRF24L01.

Table of Contents
Introduction
Hardware Requirements
Software Requirements
Circuit Diagram
Working Principle
Installation and Setup
Usage
Future Enhancements
License
Introduction
The goal of this project is to control a car's movement (forward, backward, left, right, and stop) based on hand gestures. The project utilizes an MPU6050 sensor to capture hand motions, and nRF24L01 transceivers for wireless communication between the transmitter (controlled by the hand) and the receiver (attached to the car). An ultrasonic sensor is also used to detect and avoid obstacles.

Hardware Requirements
Arduino Nano (2 units: one for transmitter, one for receiver)
MPU6050 (3-axis accelerometer and gyroscope)
nRF24L01 Transceiver (2 units)
L298N Motor Driver
DC Motors (4 units)
Ultrasonic Sensor (optional, for obstacle avoidance)
Power Supply (Batteries for transmitter and receiver)
Chassis (car frame)
Wheels
Jumper wires and breadboard
Software Requirements
Arduino IDE
RF24 Library for nRF24L01: Download Here
MPU6050 Library: Download Here
Circuit Diagram
You can refer to the schematic diagrams provided in the circuit_diagrams folder to connect your components properly:

Transmitter Setup:
Arduino Nano + MPU6050 + nRF24L01
Receiver Setup:
Arduino Nano + nRF24L01 + Motor Driver + DC Motors + Ultrasonic Sensor
Working Principle
Transmitter (Hand Gesture Controller)
The transmitter is worn on the hand, and the MPU6050 sensor detects the orientation and movement of the hand. The data is processed by the Arduino Nano and sent to the receiver using the nRF24L01 module.

Receiver (Car)
The receiver, attached to the car, receives the data from the transmitter and controls the motor driver to move the car accordingly. The ultrasonic sensor detects obstacles and stops or changes the car's direction.

Installation and Setup
Clone this repository:

bash
Copy code
git clone https://github.com/your-username/hand-gesture-car.git
cd hand-gesture-car
Install the necessary libraries:

Open Arduino IDE.
Go to Sketch -> Include Library -> Manage Libraries.
Search and install RF24 and MPU6050 libraries.
Upload the Code:

Open the transmitter code (transmitter/transmitter.ino) in Arduino IDE and upload it to the Arduino Nano connected to the MPU6050.
Open the receiver code (receiver/receiver.ino) in Arduino IDE and upload it to the Arduino Nano connected to the motor driver.
Wiring:

Follow the provided circuit diagrams to connect the components.
Usage
Power on the transmitter (battery connected to Arduino Nano).
Power on the receiver (battery connected to Arduino Nano on the car).
Move your hand to control the car:
Tilt forward: Move car forward.
Tilt backward: Move car backward.
Tilt left: Turn left.
Tilt right: Turn right.
Keep hand steady: Stop the car.
The ultrasonic sensor (if included) will automatically prevent collisions by stopping or redirecting the car when an obstacle is detected.
Future Enhancements
Gesture Customization: Implement more complex gestures for additional control features.
Speed Control: Add a feature to control the speed of the car based on hand tilt intensity Project1