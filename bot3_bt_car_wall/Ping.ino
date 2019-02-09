int Ping(int pin)
{
  const int trigPin[2] = {A0, 13};
  const int echoPin[2] = {A1, 12};

  digitalWrite(trigPin[pin], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[pin], HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin[pin], LOW);

  dist[pin] = pulseIn(echoPin[pin], HIGH) / 29 / 2;
  dist[pin] = constrain(dist[pin], 0, 25);
  return dist[pin];
}
