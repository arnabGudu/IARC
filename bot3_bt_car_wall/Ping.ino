float Ping(int pin)
{
  const int trigPin[2] = {A0, 13};
  const int echoPin[2] = {A1, 12};
  float distn;

  digitalWrite(trigPin[pin], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[pin], HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin[pin], LOW);

  distn = pulseIn(echoPin[pin], HIGH) / 29 / 2;
  distn = constrain(dist[pin], 0, 25);
  return distn;
}
