void Print()
{
  Serial.print(" kp: ");
  Serial.print(kp);
  Serial.print(" kd: ");
  Serial.print(kd);
  Serial.print(" disF: ");
  Serial.print(dist[FRONT]);
  Serial.print(" disR: ");
  Serial.print(dist[RIGHT]);
  Serial.print(" del: ");
  Serial.print(del);
  Serial.print(" sp: ");
  Serial.print(sp);
  Serial.print(" distnF: ");
  Serial.print(distn[FRONT]);
  Serial.print(" distnR: ");
  Serial.println(distn[RIGHT]);
}

void addZero(int i)
{
  if (i > 100)
    Serial.print(i);
  else if (i > 10 && i < 100)
  {
    Serial.print("0");
    Serial.print(i);
  }
  else
  {
    Serial.print("00");
    Serial.print(i);
  }
}

void addZero(float i)
{
  if (i < 0)
  {
    i *= -1;
    Serial.print("- ");
    Serial.print(i);
  }
  else if (i > 100)
    Serial.print(i);
  else if (i > 10 && i < 100)
  {
    Serial.print(" ");
    Serial.print(i);
  }
  else
  {
    Serial.print("  ");
    Serial.print(i);
  }
}
