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
float Ping(int);
void Print();
void pid(int);
void condtn();

int sp = 100;
int dist[2] = {15, 15};
float distn[2] = {0, 0};
float kp = 5, kd = 2;
int del = 800;
float lastError = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 4; i < 12; i++)
    pinMode(i, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, INPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
}

int flag = 0;
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
      //      case '1': sp = 60;    break;
      //      case '2': sp = 80;    break;
      //      case '3': sp = 190;    break;
      //      case '4': sp = 100;   break;
      //      case '5': sp = 120;   break;
      //      case '6': sp = 140;   break;
      //      case '7': sp = 160;   break;
      //      case '8': sp = 180;   break;
      //      case '9': sp = 200;   break;
      //      case 'q': sp = 210;   break;

      case '0': flag = 1;         break;
      case '1': flag = 2;         break;
      case '2': kp += 0.5;        break;
      case '3': kp -= 0.5;        break;
      case '4': kd += 0.5;        break;
      case '5': kd -= 0.5;        break;
      case '6': dist[FRONT]++;    break;
      case '7': dist[FRONT]--;    break;
      case '8': del += 100;       break;
      case '9': del -= 100;       break;
      case 'a': sp += 10;         break;
      case 'b': sp -= 10;         break;
      case 'c': dist[RIGHT]++;    break;
      case 'd': dist[RIGHT]--;    break;
      case 'q': flag = 0; stop(); break;

      case 'W': digitalWrite(4, HIGH);  break;
      case 'w': digitalWrite(4, LOW);   break;
      case 'U': digitalWrite(7, HIGH);  break;
      case 'u': digitalWrite(7, LOW);   break;
    }
  }    
  follow();
}
