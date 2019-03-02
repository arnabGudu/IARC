//float Kp = 25;
//float Ki = 0.15;
//float Kd = 1200;
//float error, errorLast, erroInte;

void pid()
{
  float input = Ping(RIGHT);
  float error = Ping(RIGHT) - dist[RIGHT];
  float prop = error * kp;
  float diff = (error - lastError) * kd;
  float balance = prop + diff;
  lastError = error;

  /*
    float errorDiff;
    float output;
    error = error * 0.7 + input * 0.3; // filter
    //error = input;
    errorDiff = error - errorLast;
    erroInte = constrain(erroInte + error, -50, 50);
    output = Kp * error + Ki * erroInte + Kd * errorDiff;
    Serial.print(error); Serial.print(' ');
    Serial.print(erroInte); Serial.print(' ');
    Serial.print(errorDiff); Serial.print(' ');
    Serial.println(output);
    errorLast = error;

    return output;
  */

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
