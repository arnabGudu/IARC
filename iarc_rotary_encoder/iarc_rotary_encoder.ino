#define encoderPin1 2
#define encoderPin2 3

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
  Serial.begin (9600);

  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);

  digitalWrite(encoderPin1, HIGH);    //pull up
  digitalWrite(encoderPin2, HIGH);    //pull up

  attachInterrupt(0, updateEncoder, CHANGE);    //here 0 is not pin 0 it is interrupt no 0 which is always assigned to pin 2
  attachInterrupt(1, updateEncoder, CHANGE);    //here 1 is not pin 1 it is interrupt no 1 which is always assigned to pin 3
}

//1 rotation = 60 sensor value
//dist = no of rotation * dist of one rotation

void loop() {
  
  Serial.println(encoderValue);
  delay(1000);
}


void updateEncoder() {
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) | LSB; //if MSB = 1 and LSB = 0 -- encoded = 10 this is the magic of bit shift operator
  int sum  = (lastEncoded << 2) | encoded; //adding lastEncoded infront of encoded => a 4 bit binary

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;  //clockwise spinning sequence 00 01 11 10
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;  //anti clockwise spinning seq 01 11 10 00

  lastEncoded = encoded;
}
