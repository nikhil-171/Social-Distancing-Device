/*This poject was created in light of the Coronavirus pandemic.
The code below programs a wearable Arduino social distancing device that will alert the user in a highly populated when a person in within 6 feet of them. 
This would help both the user and others to practice social distancing in order to lower the infection rate. 
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trigPin = 8;
const int echoPin = 9;
const int buzzer = 13;
int duration, distance;

void setup(){
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);           //programming the ultrasonic sensor signal
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;        //utilizing the time differnece in the signal to calculated the distance between people
  distance = distance/30.48;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  lcd.clear();
  lcd.print("Distance: ");
  lcd.println(distance);

  if (distance<6)
  {
    digitalWrite(7, LOW);             //monitoring the distance reorded by the sensor and utilizing a conditional statement to activate proximity buzzer  
    digitalWrite(6, HIGH);
    tone(buzzer, 1000);
    delay(50); 
    digitalWrite(6, LOW);
    tone(buzzer, 1000);
    delay(50);
  }
  else 
  {
    digitalWrite(7, HIGH);
     noTone(buzzer);
  }
  

}
