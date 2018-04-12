#include <TimerOne.h>
#include <String.h>
long num;

int dirx = 11;
int diry = 5;
int enax = 6;
int enay = 3;
int pulx = 9;
int puly = 10;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Timer1.initialize();

  pinMode(dirx,OUTPUT);
  pinMode(diry,OUTPUT);
  pinMode(enax,OUTPUT);
  pinMode(enay,OUTPUT);
  pinMode(pulx,OUTPUT);
  pinMode(puly,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:


   if (Serial.available()>0)
   {

     if (Serial.peek() == 'x')
     {
        Serial.read();
        num = Serial.parseInt();

        Stepperx(num);

        Serial.println(num);       
     }

     if (Serial.peek() == 'y')
     {
        Serial.read();
        num = Serial.parseInt();

        //Serial.println(num);

        Steppery(num);
     }

     Serial.read();

    
   }


}


void Stepperx(long num)
{
  long period; 
  
  if(num == 0)
  {
    digitalWrite(enax,HIGH);
  }
  else
  {
    digitalWrite(enax,LOW);
  }


  if(num < 0)
  {
    digitalWrite(dirx,HIGH); 
  }
  else if(num > 0)
  {
    digitalWrite(dirx,LOW);
  }
  
  num = abs(num);
  period = map(num,1,100,2000,4000);

  Timer1.pwm(pulx,512,period);
  

}


void Steppery(long num)
{

  long period;

  if(num == 0)
  {
    digitalWrite(enay,HIGH);
  }
  else
  {
    digitalWrite(enay,LOW);
  }


  if(num < 0)
  {
    digitalWrite(diry,HIGH); 
  }
  else if(num > 0)
  {
    digitalWrite(diry,LOW);
  }
  
  num = abs(num);
  period = map(num,1,100,2000,4000);

  Timer1.pwm(puly,512,period);
  

}


