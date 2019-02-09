void pid(int pin)
{
  int error = Ping(pin) - 10;
  int balance = error * kp + (error - lastError) * kd;
  delay(100);
  lastError = error;
  
  analogWrite(6, constrain(60 - balance, 0, 100));
  analogWrite(5, constrain(60 + balance, 0, 100));

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  if(flag == 5)
  {  
    Serial.print("  error: ");
    Serial.print(error);
    Serial.print("  laEr: ");
    Serial.print(lastError);
    Serial.print("  bal: ");
    Serial.print(balance);
  }
}
