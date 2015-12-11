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
    pinMode(30+i, INPUT);
 }

  Serial.begin(9600);
}

void loop() {

	Serial.println(get_ph(100));
}

int decode_value(char val){

	int value;
	switch(val){
		case 63:
			value=0;
			break;
		case 6:
			value=1;
			break;
		case 91:
			value=2;
			break;
		case 79:
			value=3;
			break;
		case 102:
			value=4;
			break;
		case 108:
			value=5;
			break;
		case 125:
			value=6;
			break;
		case 7:
			value=7;
			break;
		case 127:
			value=8;
			break;
		case 103:
			value=9;
			break;
		default:
			value=-1;
			break;

	}	

	return value;
}

float get_ph(int sample){

	float phVal=0;
	int val2;
	int val3;
	boolean one;

	for(int i=0;i<sample;i++){
		char a=0, b=0, c = 0;

		do{
			  if (digitalRead(30+9))
			    a |= 1;
			  if (digitalRead(30+18))
			    a |= 2;
			  if (digitalRead(30+17))
			    a |= 4;
			  if (digitalRead(30+16))
			    a |= 8;  
			  if (digitalRead(30+15))
			    a |= 16;
			  if (digitalRead(30+8))
			    a |= 32;
			   if (digitalRead(30+7))
			    a |= 64;


			  if (digitalRead(30+5))
			    b |= 1;
			  if (digitalRead(30+6))
			    b |= 2;
			  if (digitalRead(30+13))
			    b |= 4;
			  if (digitalRead(30+12))
			    b |= 8;  
			  if (digitalRead(30+11))
			    b |= 16;
			  if (digitalRead(30+4))
			    b |= 32;
			   if (digitalRead(30+3))
			    b |= 64;
			   /*if (digitalRead(30+2))
			   {
			    b |= 128;   //first digit indicating 1
			   }*/
			  

			    //Serial.write(255);
			    //Serial.print(a, BIN);
			    //Serial.print(" ");
			    //Serial.println(b, BIN);
			    /*if(decode_value(a)>=0&&decode_value(b)>=0){
				    Serial.print(decode_value(a));
				    Serial.print(".");
				    Serial.println(decode_value(b));
			 }*/


			one = digitalRead(32);
			val2 = decode_value(a);
			val3 = decode_value(b);
		} while(val2<0||val3<0);

		String value="";

		if(one){
			value+=1;
		}
		
		value+=String(val2);
		value+=String(val3);

		phVal += value.toInt();
	}

	phVal /= (sample*10);

	return phVal;

}
