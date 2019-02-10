void pid(int pin)
{
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

  if (flag == 5)
  {
    Serial.print("prop: ");
    Serial.print(prop);
    Serial.print("  diff: ");
    Serial.print(diff);
    Serial.print("  bal: ");
    Serial.print(balance);
    Serial.print("  laEr: ");
    Serial.println(lastError);
  }
}
