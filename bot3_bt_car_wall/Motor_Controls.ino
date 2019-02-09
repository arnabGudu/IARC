int bal = 33;

void forward()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void backward()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void right()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void left()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void fleft()
{
  analogWrite(5, sp - 60);
  analogWrite(6, sp - bal);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void fright()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal - 60);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void bright()
{
  analogWrite(5, sp);
  analogWrite(6, sp - bal - 60);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void bleft()
{
  analogWrite(5, sp - 60);
  analogWrite(6, sp - bal);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void stop()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
