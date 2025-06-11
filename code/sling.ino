#include <Servo.h>

#define SERVO_PIN1 3
#define SERVO_PIN2 9
#define SERVO_PIN3 10
#define POT_PIN1 A0
#define POT_PIN2 A1
#define BUTTON_PIN 2

Servo myservo1;
Servo myservo2;
Servo myservo3;

int val1, val2;
int servo3Position = 90;
int buttonState = 0;

void setup() {
  myservo1.attach(SERVO_PIN1);
  myservo2.attach(SERVO_PIN2);
  myservo3.attach(SERVO_PIN3);
  pinMode(BUTTON_PIN, INPUT);

  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  delay(500);
}

void loop() {
  val1 = analogRead(POT_PIN1);
  int angle1 = map(val1, 0, 1023, 0, 180);
  myservo1.write(angle1);  

  val2 = analogRead(POT_PIN2);
  int angle2 = map(val2, 0, 1023, 0, 180);
  myservo2.write(angle2);  

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    if (servo3Position < 180) {
      servo3Position += 5;
    }
    delay(1);
  } else {
    if (servo3Position > 0) {
      servo3Position -= 5;
    }
    delay(1);
  }

  myservo3.write(servo3Position);
  delay(15);
}
