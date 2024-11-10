#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <MPU6050.h>

RF24 radio(7, 8);  // CE, CSN pins for NRF24L01
const byte address[6] = "00001";
MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();

  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Define tilt thresholds
  int threshold = 5000;

  // Hand tilt forward (Y-axis positive)
  if (ay > threshold) {  
    radio.write("F", 1);  // Send 'F' for forward
    Serial.println("Forward");
  }
  // Hand tilt backward (Y-axis negative)
  else if (ay < -threshold) {  
    radio.write("B", 1);  // Send 'B' for backward
    Serial.println("Backward");
  }
  // Hand tilt left (X-axis negative)
  else if (ax < -threshold) {  
    radio.write("L", 1);  // Send 'L' for left
    Serial.println("Left");
  }
  // Hand tilt right (X-axis positive)
  else if (ax > threshold) {  
    radio.write("R", 1);  // Send 'R' for right
    Serial.println("Right");
  }
  // Neutral position (no significant tilt)
  else {  
    radio.write("S", 1);  // Send 'S' for stop (neutral position)
    Serial.println("Stop/Neutral");
  }

  delay(100);  // Slow down sending rate
}