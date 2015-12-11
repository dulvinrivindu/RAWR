/*
RAWR
Team CREWEight
HackaDev ImpactUVA
2015/12/11
*/


void setup() {
  // put your setup code here, to run once:

int i = 0;
 for (int i = 1; i <= 18; i++)
 {
    pinMode(20+i, INPUT);
 }

  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char a=0, b=0, c = 0;


  if (digitalRead(20+9))
    a |= 1;
  if (digitalRead(20+18))
    a |= 2;
  if (digitalRead(20+17))
    a |= 4;
  if (digitalRead(20+16))
    a |= 8;  
  if (digitalRead(20+15))
    a |= 16;
  if (digitalRead(20+8))
    a |= 32;
   if (digitalRead(20+7))
    a |= 64;


  if (digitalRead(20+5))
    b |= 1;
  if (digitalRead(20+6))
    b |= 2;
  if (digitalRead(20+13))
    b |= 4;
  if (digitalRead(20+12))
    b |= 8;  
  if (digitalRead(20+11))
    b |= 16;
  if (digitalRead(20+4))
    b |= 32;
   if (digitalRead(20+3))
    b |= 64;

   if (digitalRead(20+2))
   {
    b |= 128;   //first digit indicating 1
   }
  

    //Serial.write(255);
    Serial.print(a, BIN);
    Serial.print(" ");
    Serial.println(b, BIN);
 

}
