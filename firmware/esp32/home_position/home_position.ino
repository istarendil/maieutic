#include <Wire.h> 
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

/* Servo limits definitions (ms) */
#define servo_min  0.95 
#define servo_max  2.1 

void setup() {
  pca.begin();
  pca.setOscillatorFrequency(25000000);     // The internal oscilator for the PCA9685 chip is aproximately 25MHz
  pca.setPWMFreq(50);

}

void loop() {
    
  set_servo_deg(0, 90);
  set_servo_deg(1, 90);
  set_servo_deg(2, 90);
  set_servo_deg(3, 90);
  set_servo_deg(4, 90);
  set_servo_deg(5, 90);
  set_servo_deg(6, 90);
  set_servo_deg(7, 90);
  set_servo_deg(8, 90);
  set_servo_deg(9, 90);
  set_servo_deg(10, 90);
  set_servo_deg(11, 90);
  set_servo_deg(12, 90);
  set_servo_deg(13, 90);
  set_servo_deg(14, 90);
  set_servo_deg(15, 90);
  delay(1000);
  
  delay(50);
   
}

void set_servo_ms(uint8_t channel, double pulse) {
  double pulselength;
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 50;       // 50 Hz
  pulselength /= 4096;     // 12 bits of resolution
  pulse *= 1000;           // convert to ms
  pulse /= pulselength;
  pca.setPWM(channel, 0, pulse);
}

void set_servo_deg(uint8_t channel, double angle){
  double factor;
  double pulse;

  factor = (servo_max - servo_min)/2;
  pulse = (angle*factor/90) + servo_min;
  set_servo_ms(channel, pulse);
  return;
}
