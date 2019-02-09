void Print()
{
  Serial.print("flag: ");
  Serial.print(flag);
  Serial.print("  DistF: ");
  Serial.print(dist[0]);
  Serial.print("  DistR: ");
  Serial.print(dist[1]);
  Serial.print("  kp: ");
  Serial.print(kp);
  Serial.print("  kd: ");
  Serial.print(kd);
  Serial.print("  del: ");
  Serial.print(del);
}
