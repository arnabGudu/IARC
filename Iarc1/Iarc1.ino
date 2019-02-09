const int trigPin = 5, echoPin = 6;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  float dist = pulseIn(echoPin, HIGH) / 29 / 2;

  for (int i = 0; i < 5; i++)
  {
    Serial.print(analogRead(15 + i));
    Serial.print("\t");
  }
  if (dist > 15)
  { 
    turnRight();
    Serial.print(">15");
    
  }
  else
    Serial.print(dist);
  Serial.println(" cm");

}

void turnRight()
{
  //  digitalWrite(motorL, HIGH);
  //  digitalWrite(motorR, LOW);
  //  delay(100);
}
