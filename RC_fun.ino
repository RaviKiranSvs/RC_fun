float Vc,R=820,C=0;
unsigned long t0=0,trc=0;
float dt=0;
byte d=0;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop()
{
  Vc=analogRead(0)*5;
  Vc=Vc/1024;
  Serial.print(5);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(Vc);
  Serial.print(" ");
  Serial.print(.632*5);
  Serial.print(" ");
  Serial.print(d);
  Serial.print(" ");
  Serial.print(t0);
  Serial.print(" ");
  Serial.print(trc);
  Serial.print(" ");
  Serial.println(C);

  if(Vc==0)
  {
    digitalWrite(2,1);
    t0=millis();
  }

  if(Vc<.63*5) d=0;

  if(Vc>=.63*5&&d==0)
  {
    trc=millis();
    d=1;
  }

  if(Vc>=4.90)
  {
    digitalWrite(2,0);
  }

  if(t0!=0&&trc!=0)
  {
    dt=(float)(trc-t0)/1000;
    C=(float)(dt/R)*1000;
    t0=0;
    trc=0;
  }

  delay(100);
}
