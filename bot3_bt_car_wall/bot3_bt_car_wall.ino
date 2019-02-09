#define RIGHT 1
#define FRONT 0

void forward();
void backward();
void left();
void right();
void fleft();
void fright();
void bleft();
void bright();
void stop();
int Ping(int);
void Print();

int sp = 100;
int dist[2] = {0, 0};

void setup() {
  Serial.begin(9600);
  for (int i = 4; i < 12; i++)
    pinMode(i, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, INPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
}

bool flag = 0;
double milis = 0;

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();

    switch (ch)
    {
      case 'F': forward();  break;
      case 'B': backward(); break;
      case 'L': left();     break;
      case 'R': right();    break;
      case 'G': fleft();    break;
      case 'I': fright();   break;
      case 'H': bleft();    break;
      case 'J': bright();   break;
      case 'S': stop();     break;
      case '1': sp = 60;    break;
      case '2': sp = 80;    break;
      case '3': sp = 190;    break;
      case '4': sp = 100;   break;
      case '5': sp = 120;   break;
      case '6': sp = 140;   break;
      case '7': sp = 160;   break;
      case '8': sp = 180;   break;
      case '9': sp = 200;   break;
      case 'q': sp = 210;   break;
      case 'W': digitalWrite(4, HIGH);  break;
      case 'w': digitalWrite(4, LOW);   break;
      case 'U': digitalWrite(7, HIGH);  break;
      case 'u': digitalWrite(7, LOW);   break;
      case 'V': flag = 1;   break;
      case 'v': flag = 0;   break;
        //      case 'o': bal++;  break;
        //      case 'p': bal--;  break;
    }
  }
  if (flag == 1)
  {
    forward();
    
    if (Ping(RIGHT) > 15)
    {
      right();
//      milis = millis();
//      while (millis() - milis > 1000)
//        Print();
      delay(1000);
    }

    if (Ping(FRONT) < 15)
    {
      left();
//      milis = millis();
//      while (millis() - milis > 1000)
//        Print();
      delay(1000);
    }
  }
  Print();
}
