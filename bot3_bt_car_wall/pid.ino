int lastError = 0;

void pid(int pin)
{
  int error = Ping(pin) - 10;
  int balance = error * kp + (error - lastError) * kd;
  lastError = error;
  analogWrite(6, constrain(60 - balance, 0, 100));
  analogWrite(5, constrain(60 + balance, 0, 100));

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
