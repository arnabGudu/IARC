void condtn(int pin)
{
  //forward();

  if (Ping(RIGHT) > 15 && pin == RIGHT)
  {
    right();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }

  if (Ping(FRONT) < 15 && pin == FRONT)
  {
    left();
    //      milis = millis();
    //      while (millis() - milis > 1000)
    //        Print();
    delay(del);
  }
}
