int bal = 33;       //bal is used because two motors were not rotating at same speed
int sp = 100;               //speed

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

//////////////////////////////////PING/////////////////////////////////

int dist[2] = {15, 15};     //max dist from obstacle
float distn[2] = {0, 0};    //used to store distance calculated

float Ping(int pin)
{
  const int trigPin[2] = {A0, 13};    //Trigger pins {FRONT, RIGHT, LEFT}
  const int echoPin[2] = {A1, 12};    //Echo    pins {FRONT, RIGHT, LEFT}

  digitalWrite(trigPin[pin], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[pin], HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin[pin], LOW);

  distn[pin] = pulseIn(echoPin[pin], HIGH) / 29 / 2;    //return value in cm
  //distn[pin] = constrain(distn[pin], 0, 25);      //used to restrict dist between 0 to 25cm
  return distn[pin];
}

//////////////////////////////////////PID///////////////////////////////
float lastError = 0;
float Kp = 0.7;           //to be calculated experimentally      
float Ki = 0.005;
float Kd = 1.3;
//float threshold = 25; //max possible error

void pid(int pin)
{
  float input = Ping(pin);                //collect dist
  float error = Ping(pin) - dist[pin];    //finding error
  float prop = error;
  float diff = error - lastError;
  float intg = error + intg;
  float balance = prop * kp + diff * kd + intg * ki;
  lastError = error;

  if (pin == LEFT)
  {
    balance = -1 * balance;     //since same formula is used for both left and right sensors
  }

  analogWrite(6, constrain(sp - balance, 0, 150));
  analogWrite(5, constrain(sp + balance, 0, 150));

  //for always forward
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
///////////////////////////*******END OF FUNCTIONS********/////////////////////////////



void setup()
{
  Serial.begin(9600);
  for (int i = 4; i < 12; i++)
    pinMode(i, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, INPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
}

int del = 800;              //delay for sharp turns

void loop()
{
  float frontPing = Ping(FRONT);
  float rightPing = Ping(RIGHT);
  //float leftPing  = Ping(LEFT);

  if (node == RIGHT)
  {
    if (frontPing > dist[FRONT] && rightPing < dist[RIGHT])
    {
      pid();            //if no obstacle infront and wall on side then follow wall with pid
    }
    else if (frontPing > dist[FRONT] && rightPing > dist[RIGHT])
    {
      right();          //if no obstacle infront and no wall then turn right
      delay(del);
    }
    else
    {
      left();           //if obstacle infront then turn left
      delay(del);
    }
  }
  else
  {
    if (frontPing > dist[FRONT] && rightPing < dist[RIGHT])
    {
      pid();            //if no obstacle infront and wall on side then follow wall with pid
    }
    else if (frontPing > dist[FRONT] && rightPing > dist[RIGHT])
    {
      right();          //if no obstacle infront and no wall then turn right
      delay(del);
    }
    else
    {
      left();           //if obstacle infront then turn left
      delay(del);
    }    
  }
}
