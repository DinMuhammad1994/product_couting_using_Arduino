#include <LiquidCrystal.h>

#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int relay = 13; 

unsigned int ballcount = 0;
unsigned int tballs = 0; // total balls
int ballf = 0; // ball flag.  
int resetb = 3; // to reset the relay , this can be laser or an infrared sensor. 

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("TBalls     Current");
  attachInterrupt(0, add, FALLING);  
pinMode(resetb, INPUT); 
digitalWrite(resetb, HIGH); 
 
  pinMode( relay, OUTPUT);
  digitalWrite(relay, LOW); 
  
     ballcount = 0;
tballs = 0; 
  
}

void loop() {
  
  
 if ( ballf == 1 ) // the lcd is updated only when ballf = 1, this way the controller won't be busy in printing the values on lcd again and again. 
 {
   //Print out result to lcd
   lcd.clear();
   lcd.print("TBalls  Current");
   lcd.setCursor(0,1);
   lcd.print(tballs);
   
   lcd.setCursor(8,1);
   lcd.print(ballcount);
  
  ballf = 0; 
   
 }
 
 if ( digitalRead(resetb) == LOW)
 {
   digitalWrite(relay, LOW); 
 }

}


void add()
 { 

   ballf = 1; 
      ballcount++; 
    tballs = tballs + 1;  
      if (ballcount >= 10) 
      {
        digitalWrite(relay, HIGH);  
        ballcount = 0; 
      }
         
   
 }
