// This is needed to use the functions of the LCD library.
#include <LiquidCrystal.h>

// This defines the LCD pins.
LiquidCrystal lcd(35,4,3,33,2,31);
LiquidCrystal lcd2(41,7,6,39,5,37);

// This is to initialize the pin number of 
// the solenoid features. Button output analog
// and the pins to control power to each end of the
// solenoid.

int buttonone = 34;
int solenoidfore1 = 36;
int solenoidback1 = 38;

int buttontwo = 40;
int solenoidfore2 = 42;
int solenoidback2 = 44;

int buttonthree = 46;
int solenoidfore3 = 48;
int solenoidback3 = 50;

// This is to initialize the player counter and the playerswitch
// for counting logic.

int counter = 0;
int playerswitch = 2;
int playeronescore = 0;
int playertwoscore = 0;

void setup()
{
  // This indicates the LCD size. 16 characters and 2 lines of
  // characters. 
  
  lcd.begin(16, 2);
  lcd2.begin(16, 2);
  
  // This ensures a LCD wipe to erase anything that was printed
  // on the LCD before during startup or when power is turned on.
  
  lcd.clear();
  lcd2.clear();
  
  // This initiates the pinmode INPUT for digitalRead to identify
  // if an IR signal is received. We have 6 IR sensors thus 6 
  // digital pin INPUT reads.
  
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  pinMode(30, INPUT);
  pinMode(32, INPUT);
  
  // These initiate the movement of the solenoid mechanism.
  // It causes 2 different pins to have an OUTPUT mode to set
  // the solenoid power on one side to LOW or HIGH and then
  // initializes the analog read that is needed for the 
  // if statement in the loop method.
  
  pinMode(buttonone, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(solenoidfore1, OUTPUT);
  pinMode(solenoidback1, OUTPUT);
  pinMode(buttontwo, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(solenoidfore2, OUTPUT);
  pinMode(solenoidback2, OUTPUT);
  pinMode(buttonthree, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(solenoidfore3, OUTPUT);
  pinMode(solenoidback3, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // This senses if a switch on the console is turned to one player
  // or two player mode.
  
  int playerpower;
  playerpower = digitalRead(43);  
  
  // The following analogRead if statements allow the 
  // recognition of the analog that the button outputs when
  // pushed and if it is greater than 500 it will power the solenoid
  // correctly.
  
   int x;
   x = analogRead(A0);
   digitalWrite(buttonone, HIGH);
   
   if(x > 500)
   {
     digitalWrite(solenoidfore1, HIGH);
     digitalWrite(solenoidback1, LOW);
     delay(250);
     digitalWrite(solenoidfore1, LOW);
     digitalWrite(solenoidback1, HIGH);
     delay(100);
     digitalWrite(solenoidfore1, LOW);
     digitalWrite(solenoidback1, LOW);
     delay(1000);
   }
   
   int y;
   y = analogRead(A1);
   digitalWrite(buttontwo, HIGH);
   
   if(y > 500)
   {
     digitalWrite(solenoidfore2, HIGH);
     digitalWrite(solenoidback2, LOW);
     delay(250);
     digitalWrite(solenoidfore2, LOW);
     digitalWrite(solenoidback2, HIGH);
     delay(100);
     digitalWrite(solenoidfore2, LOW);
     digitalWrite(solenoidback2, LOW);
     delay(1000);
   }
   
   int z;
   z = analogRead(A2);
   digitalWrite(buttonthree, HIGH);
   
   if(z > 500)
   {
     digitalWrite(solenoidfore3, HIGH);
     digitalWrite(solenoidback3, LOW);
     delay(250);
     digitalWrite(solenoidfore3, LOW);
     digitalWrite(solenoidback3, HIGH);
     delay(100);
     digitalWrite(solenoidfore3, LOW);
     digitalWrite(solenoidback3, LOW);
     delay(1000);
   }
  
  // This alligns the LCD cursor on the monitor to be placed
  // at the beginning of the monitor screen. 
  
  lcd.setCursor(0,0);
  lcd2.setCursor(0,0);
  
  // This initializes the IR digitalReads so that it can 
  // eventually be recognized and manipluated in the counter
  // system. 
  
  int irOne;
  irOne = digitalRead(22);
  
  int irTwo;
  irTwo = digitalRead(24);
  
  int irThree;
  irThree = digitalRead(26);
  
  int irFour;
  irFour = digitalRead(28);
  
  int irFive;
  irFive = digitalRead(30);
  
  int irSix;
  irSix = digitalRead(32);
  
  // The following if statements indicate which IR receiver
  // will return the point counter and then switch the player
  // if it the sensor line is broken.
  
  if(irOne = 0)
  {
    counter = 2;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  
  if(irTwo = 0)
  {
    counter = 3;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  
  if(irThree = 0)
  {
    counter = 4;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  
  if(irFour = 0)
  {
    counter = 2;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  if(irFive = 0)
  {
    counter = 3;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  
  if(irSix = 0)
  {
    counter = 2;
    
    if(playerswitch = 2)
    {
      playerswitch = 1;
    }
    else if(playerswitch = 1)
    {
      playerswitch = 2;
    }
    
  }
  
  // The following is the counter system that will display
  // the players score on the monitor and count up by one 
  // each time. If one of the players reaches 20 points 
  // the LCD will print out who wins and reset the scores.
  // The for loop was needed in order to satisfy the 
  // counting recognition by one as requested by the client.
  
  while(playerpower == 1)
  {
    if(playerswitch == 1)
    {
      for(int i = 1; i < counter; i++)
      {
        if(playeronescore == 20)
        {
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Player 1 Wins!");
          lcd2.print("Player 1 Wins!");
          playeronescore = 0;
          playertwoscore = 0;
        }
        
        else if(playeronescore != 20)
        {
          playeronescore++;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Playerscore:" + String(playeronescore));
          delay(500);
        }
      }
      counter = 0;
    }
    
    else if(playerswitch == 2)
    {
      for(int i = 1; i < counter; i++)
      {
        if(playertwoscore == 20)
        {
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Player 2 Wins!");
          lcd2.print("Player 2 Wins!");
          playeronescore = 0;
          playertwoscore = 0;
        }
        
        else if(playertwoscore!= 20)
        {
          playertwoscore++;
          lcd2.clear();
          lcd2.setCursor(0,0);
          lcd2.print("Playerscore:" + String(playeronescore));
          delay(500);
        }
      }
      counter = 0;
    }
  }
  
  while(playerpower == 0)
  {
    if(playerswitch == 1)
    {
      for(int i = 1; i < counter; i++)
      {
        if(playeronescore == 20)
        {
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Player 1 Wins!");
          lcd2.print("Player 1 Wins!");
          playeronescore = 0;
          playertwoscore = 0;
        }
        
        else if(playeronescore != 20)
        {
          playeronescore++;
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Playerscore:" + String(playeronescore));
          lcd2.print("Playerscore:" + String(playeronescore));
        }
      }
      counter = 0;
    }
    
    else if(playerswitch == 2)
    {
      for(int i = 1; i < counter; i++)
      {
        if(playeronescore == 20)
        {
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Player 1 Wins!");
          lcd2.print("Player 1 Wins!");
          playeronescore = 0;
          playertwoscore = 0;
        }
        
        else if(playeronescore != 20)
        {
          playeronescore++;
          lcd.clear();
          lcd2.clear();
          lcd.setCursor(0,0);
          lcd2.setCursor(0,0);
          lcd.print("Playerscore:" + String(playeronescore));
          lcd2.print("Playerscore:" + String(playeronescore));
        }
        
      }
      counter = 0;
    }
  }
}

// Spencer Davis Milbrandt - University of Colorado  Boulder - 2014
