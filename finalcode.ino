 #include <LiquidCrystal.h> 
  
  const int switchPin = 8; 
  int sw_state = 0; 
  int presses = 0; 
  int val; 
  int oldval = 0; 
  float TC;
  float Luxlvl=0;
  int FAN = 6;
  
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
  
  int led = 13; 
  
  void setup() { 
  
    lcd.begin(16, 2); 
    pinMode(switchPin,INPUT); 
    pinMode(led,OUTPUT); 
  
  } 
  
  void loop() { 
  
    val = digitalRead(switchPin); 
    
    if ((val == LOW) && (oldval == HIGH)){ 
    presses = presses +1; 
  
    delay(50); 
    } 
  
    oldval = val; 
  
    digitalWrite(led,HIGH); 
  
  switch(presses){ 
  
     case 0: 
  
     lcd.setCursor(0,0); 
     lcd.print("Aleena P!");   
     
     lcd.setCursor(0,1); 
     lcd.print("roject");  
  
     break; 
  
  case 1:  

//Temperature mode

TEMP();

  
    lcd.setCursor(0,0); 
    lcd.print("Temp="); 
     
    lcd.setCursor(0,1); 
    lcd.print(" "); 
    
    delay(200); 
     
    lcd.print(TC);
    lcd.setCursor(5,1);
    lcd.print("degrees C");
    
    break; 
  
    case 2: 

 //HUMIDITY MODE 
  
     lcd.setCursor(0,0); 
     lcd.print("Humidity ="); 
     
     lcd.setCursor(0,1); 
     lcd.print("   "); 
     break;  
  
  
  case 3:  
  
// LIGHT

     lcd.setCursor(0,0); 
     lcd.print("Lux lvl"); 
     
     lcd.setCursor(0,1); 
     lcd.print(""); 
     delay(200);
  
     break; 

 case 4:  
//turn on fan

lcd.print("Fan: on");
digitalWrite(FAN,HIGH);
break;   

 case 5:  
//turn off fan

lcd.print("Fan: off");
digitalWrite(FAN,LOW);
break;   

  
     default: 
  
  presses = 0; 
  
  } 
  
  } 

void TEMP(void)
{
 float R=4700;
 float ADC;
 float BETA=3950;
 float R0=5000;
 float T0=298.15;
 ADC = analogRead(A0);
 float T,RT;
 float A,B;

 A=(R*ADC);
 B=(1023-ADC);
 RT=A/B;

 T=1/((1/T0)+(1/BETA)*log(RT/R0));
 TC=T-273.15;

 if (TC>29)
 {
  analogWrite(FAN, 255);
 }

 else
 {
  analogWrite (FAN, 0);
 }



}

void LIGHT (void)
{
 float V;
 float constant=1333.0;
 ADC=analogRead(A2);
 V=ADC*5.0/1023;
 Luxlvl=V*constant;
} 
