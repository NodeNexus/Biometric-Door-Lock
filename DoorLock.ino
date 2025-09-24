#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

Servo myServo;
#define SERVO_PIN 9
#define LED_GREEN 6
#define LED_RED 7

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  
  Serial.begin(9600);
  finger.begin(57600);
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Locked position
  
  if (finger.verifyPassword()) {
    Serial.println("Fingerprint sensor detected.");
  } else {
    Serial.println("Fingerprint sensor not found :(");
    while (1) { delay(1); }
  }
}

void loop() {
  getFingerprintID();
  delay(50);
}

int getFingerprintID() {
  int p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.print("Access Granted, ID: ");
    Serial.println(finger.fingerID);
    digitalWrite(LED_GREEN, HIGH);
    myServo.write(90); // Unlock
    delay(3000);
    myServo.write(0);  // Lock again
    digitalWrite(LED_GREEN, LOW);
  } else {
    Serial.println("Access Denied!");
    digitalWrite(LED_RED, HIGH);
    delay(1000);
    digitalWrite(LED_RED, LOW);
  }
  return finger.fingerID;
}
