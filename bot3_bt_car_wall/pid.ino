void pid(int pin)
{
  float error = Ping(pin) - 10;
  float prop = error * kp;
  float diff = (error - lastError) * kd;
  float balance = prop + diff;
  lastError = error;

  analogWrite(6, constrain(sp - balance, 0, 150));
  analogWrite(5, constrain(sp + balance, 0, 150));

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  if (flag == 5)
  {
    Serial.print("P : ");
    addZero(prop);
    Serial.print(" D: ");
    addZero(diff);
    Serial.print(" PD: ");
    addZero(balance);
    Serial.println();
  }
}
