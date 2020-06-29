 // include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 
 int ThermistorPin = A0;
int ledPin = 10;   //the number of the LED pin
 int ldrPin = A1;  //the number of the LDR pin
float R1 = 10000;
int Vo;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

 int dtime=1000;
 
 void setup() {
lcd.begin(16, 2);
lcd.print("Inactive Mode");
pinMode(A2,INPUT);
pinMode(9,OUTPUT);//AC out
pinMode(8,OUTPUT);//Fan out
pinMode(ledPin, OUTPUT);  //initialize the LED pin as an output
pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
 }

void loop() {
  if(analogRead(A2)<700)
   {
              lcd.clear();

    lcd.setCursor(0, 0);
  // print LCD Heder
  lcd.print("Tem. AC Fan Lig.");
  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

   if (ldrStatus <=300) {

    digitalWrite(ledPin, HIGH);               //turn LED on
lcd.setCursor(13, 1);
  // print the light is on
  lcd.print("ON");
    
   }
  else {

    digitalWrite(ledPin, LOW);          //turn LED off
   lcd.setCursor(13, 1);
  // print the light is off
  lcd.print("OFF");

  }
  
   
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  //Tf = (Tc * 9.0)/ 5.0 + 32.0; 
  
lcd.setCursor(0, 1);
  // print Temperature
  lcd.print(Tc);
   
  if ((Tc>=0)&&(Tc<15) )
   
    {
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
   
lcd.setCursor(6, 1);
  // print the AC is off
  lcd.print("OFF");

    lcd.setCursor(9, 1);
  // print the Fan is off
  lcd.print("OFF");
  delay(dtime);
     
  }
  else if((Tc>=15)&&(Tc<20))
  {
    digitalWrite(9,HIGH);//AC on
    digitalWrite(8,LOW);//Fan off
   
     lcd.setCursor(6, 1);
  // print the AC is on
  lcd.print("ON");
    lcd.setCursor(9, 1);
  // print the Fan is off
  lcd.print("OFF");
  delay(dtime);
}
else
{
  digitalWrite(9,HIGH);//AC on
    digitalWrite(8,HIGH);//Fan on
  
     lcd.setCursor(6, 1);
  // print the AC is on
  lcd.print("ON");

    lcd.setCursor(9, 1);
  // print the Fan is on
  lcd.print("ON");
  delay(dtime);
}
}
else 
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Inactive Mode  ");

 digitalWrite(9,LOW);//AC off
 digitalWrite(8,LOW);//Fan off
 digitalWrite(ledPin, LOW);//LIGHT OFF

delay(1000);
}
}

