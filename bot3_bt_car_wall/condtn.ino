void condtn(int pin)
{
  if (Ping(RIGHT) > dist[RIGHT] && pin == RIGHT)
  {
    right();
    delay(del);
  }

  if (Ping(FRONT) < dist[FRONT] && pin == FRONT)
  {
    left();
    delay(del);
  }
}
