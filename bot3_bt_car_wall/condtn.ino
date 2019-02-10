void condtn(int pin)
{
  //forward();

  if (Ping(RIGHT) > minDist && pin == RIGHT)
  {
    right();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }

  if (Ping(FRONT) < minDist && pin == FRONT)
  {
    left();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }
}
