void setup() {
  Serial.begin(9600);
  for (int i = 4; i < 12; i++)
    pinMode(i, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

float Ping()
{
  const int trigPin = 13;
  const int echoPin = 12;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 29 / 2;
}

float lastError = 0, kp = 3.2, kd = 2.1;

void loop() {
  float error = Ping() - 10;
  float prop = error * kp;
  float diff = (error - lastError) * kd;
  float balance = prop + diff;
  lastError = error;

  analogWrite(6, constrain(60 - balance, 0, 100));
  analogWrite(5, constrain(60 + balance, 0, 100));

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

//  Serial.print("prop: ");
//  Serial.print(prop);
//  Serial.print("  diff: ");
//  Serial.print(diff);
//  Serial.print("  bal: ");
//  Serial.print(balance);
//  Serial.print("  laEr: ");
//  Serial.println(lastError);

   Serial.print(prop);
   Serial.print(",");
   Serial.print(diff);
   Serial.print(",");
   Serial.println(balance);
   delay(200);
}
