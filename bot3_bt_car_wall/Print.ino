void Print()
{
  Serial.print("flag:");
  Serial.print(flag);
  Serial.print("\tDistF: ");
  Serial.print(dist[0]);
  Serial.print("\tDistR: ");
  Serial.print(dist[1]);
  Serial.print("\tkp: ");
  Serial.print(kp);
  Serial.print("\tkd: ");
  Serial.print(kd);
  Serial.print("\tdel: ");
  Serial.println(del);
}
