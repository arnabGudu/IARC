const int motIn[6] = {5, 6, 8, 9, 10, 11};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
    pinMode(motIn[i], OUTPUT);
  for (int i = 0; i < 6; i++)
    pinMode(A0 + i, INPUT);
}

int lastError = 0;

const float kp = 10, kd = 10;

void loop()
{
  bool buff[6];
  for (int i = 0; i < 6; i++)
    buff[i] = digitalRead(A0 + i);

  float error = 0;
  error += buff[0] * -5;
  error += buff[1] * -2;
  error += buff[2] * -1;
  error += buff[3] * +1;
  error += buff[4] * +2;
  error += buff[5] * +5;

  float diff = error - lastError;
  float balance = kp * error + kd * diff;
  lastError = error;

  int val = (buff[0] | buff[1] << 1 | buff[2] << 2 | buff[3] << 3 | buff[4] << 4 | buff[5] << 5);
  if (val == B111111)
  {
    analogWrite(5, 0);
    analogWrite(6, 0);
  }
  else
  {
    analogWrite(5, constrain(60 - balance, 0, 100));
    analogWrite(6, constrain(60 + balance, 0, 100));
  }

  if (error > abs(5))
    delay(1000);

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  Serial.print("Error: ");
  Serial.print(error);
  Serial.print("\tVal: ");
  Serial.print(val, BIN);
  Serial.print("\tDiff: ");
  Serial.print(diff);
  Serial.print("\tBalance: ");
  Serial.println(balance);

}
