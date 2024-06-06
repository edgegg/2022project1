int buzzer = 4;
int GREEN = 5;
int BLUE = 6;
int RED = 7;
int sw1 = 8;
int sw2 = 9;
int tri = 13;
int echo = 12;
int sw1_state;
int sw2_state;
long duration, cm;
int a = 0;
int b = 0;
int c = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop()
{
  digitalWrite(tri,LOW); //HIGH신호를 보내기 전에 LOW신호를 출력해서 출력을 깨끗하게
  delayMicroseconds(2);

  digitalWrite(tri, HIGH);
  delayMicroseconds(10);
  digitalWrite(tri, LOW);

  duration = pulseIn(echo, HIGH);
  cm = (duration/2)/29.4;

  Serial.print(cm);
  Serial.println("cm");

  sw1_state = digitalRead(sw1);
  sw2_state = digitalRead(sw2);

  if(sw1_state==1 && sw2_state==0)
  {
    a=1;
    b=0;
    c=0;
  }
  if(sw1_state==0 && sw2_state==1)
  {
    a=0;
    b=1;
    c=0;
  }
  if(sw1_state==1 && sw2_state==1)
  {
    a=0;
    b=0;
    c=1;
  }

  if(a==1)
  {
    LED(cm);
  }
  if(b==1)
  {
    BUZ(cm);
  }
  if(c==1)
  {
    LED(cm);
    BUZ(cm);
  }

  delay(500);
}

void LED(int n) // LED 함수
{
  switch(n/10) // 10cm 단위로 나눠서 작동
  {
    case 0:
    //0~10
    digitalWrite(GREEN, HIGH);
    delay(100);
    digitalWrite(GREEN, LOW);
    delay(100);
    digitalWrite(BLUE, HIGH);
    delay(100);
    digitalWrite(BLUE, LOW);
    delay(100);
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(100);
    break;

    case 1:
    //10~20
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    delay(200);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    delay(200);
    break;

    case 2:
    //20~30
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    delay(500);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    delay(500);
    break;

    case 3:
    //30~40
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, HIGH);
    break;

    case 4:
    //40~50
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    digitalWrite(RED, LOW);
    break;

    case 5:
    //50~60
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    break;

    default:
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(RED, LOW);
    break;
  }
}

void BUZ(int n) // Buzzer 함수
{
  switch(n/10) // 10cm 단위로 나눠서 작동
  {
    case 0:
    //0~10
    tone(buzzer, 3000, 1000);
    case 1:
    //10~20
    tone(buzzer, 2500, 600);
    case 2:
    //20~30
    tone(buzzer, 2000, 400);
    break;

    case 3:
    //30~40
    tone(buzzer, 1500, 200);
    break;

    case 4:
    //40~50
    tone(buzzer, 1000, 100);
    break;

    case 5:
    //50~60
    tone(buzzer, 500, 50);
    break;

    case 6:
    //50~60
    tone(buzzer, 100, 10);
    break;

    default:
    noTone(buzzer);
    break;
  }
}
