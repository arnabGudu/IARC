void condtn(int pin)
{
  //forward();

  if (Ping(RIGHT) > dist[RIGHT] && pin == RIGHT)
  {
    right();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }

  if (Ping(FRONT) < dist[FRONT] && pin == FRONT)
  {
    left();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }
}
