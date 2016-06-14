#include<Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD(11,10,9,2,3,4,5); 

#define trigPin 13 
#define echoPin 12 
Servo servo_test;
int angle = 0; 

void setup() 
{ 
  servo_test.attach(6); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  LCD.begin(16,2); // lcd command to display
  LCD.setCursor(0,0);  //Set LCD cursor 
  LCD.print("Distance"); 
}

void loop() {
  long duration, distance;
  int c,location = 1;
  long disminimum, disarray[180];
  for(angle = 0; angle < 180; angle += 1)    // move servo by 1 degree
  {                                  
   servo_test.write(angle);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  disarray[angle] = distance;
  }
   disminimum = disarray[0];
   for (c = 1; c < 180; c++)
   {
      if (disarray[c] < disminimum)
      {
        disminimum = disarray[c];
        location = c+1;
        
        }
    
    }
    /*Serial.println("the object is at distance");
    Serial.println(disminimum);
    Serial.println("at location");
    Serial.println(location);*/
LCD.setCursor(9,0);
LCD.print("            ");
LCD.setCursor(9,0);
LCD.print(disminimum);
LCD.setCursor(0,1);
LCD.print("Angle");
LCD.setCursor(6,1);
LCD.print(location);

 
    
   for(angle = 180; angle>=0; angle = angle-1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              
    delay(100);                       
  } 

  
}


