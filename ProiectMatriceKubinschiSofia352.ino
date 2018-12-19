#include "LedControl.h" 
#include <LiquidCrystal.h>
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
unsigned long lastUpdate = 0;
const int buttonPin = 9;
int delayTime = 60;
int buttonState = 0;
int level = 0;
int life = 5;
int matrix[8][8] = {0};
int stopped;
int reset;
int fullCol;

void setup()
{
 lc.shutdown(0, false); // turn off power saving, enables display
 lc.setIntensity(0, 2); // sets brightness (0~15 possible values)
 lc.clearDisplay(0);// clear screen
 Serial.begin(9600); 
 pinMode(buttonPin, INPUT);
 lcd.begin(16, 2);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Press button to");
 lcd.setCursor(0,1);
 lcd.print("start game");
}

void drawOne()                 //function drawing 1 on the matrix
{
 lc.clearDisplay(0);
 lc.setLed(0, 3, 2, true);
 lc.setLed(0, 2, 3, true);
 lc.setLed(0, 1, 4, true);
 lc.setLed(0, 2, 4, true);
 lc.setLed(0, 3, 4, true);
 lc.setLed(0, 4, 4, true);
 lc.setLed(0, 5, 4, true);
 lc.setLed(0, 6, 4, true);
}

void drawTwo()                 //function drawing 2 on the matrix
{
 lc.setLed(0, 1, 3, true);
 lc.setLed(0, 1, 4, true);
 lc.setLed(0, 2, 2, true);
 lc.setLed(0, 2, 5, true);
 lc.setLed(0, 3, 4, true);
 lc.setLed(0, 4, 3, true);
 lc.setLed(0, 5, 2, true);
 lc.setLed(0, 5, 3, true);
 lc.setLed(0, 5, 4, true);
 lc.setLed(0, 5, 5, true);
}

void drawThree()               //function drawing 3 on the matrix
{
 lc.setLed(0, 1, 3, true);
 lc.setLed(0, 1, 4, true);
 lc.setLed(0, 2, 2, true);
 lc.setLed(0, 2, 5, true);
 lc.setLed(0, 3, 4, true);
 lc.setLed(0, 4, 3, true);
 lc.setLed(0, 5, 4, true);
 lc.setLed(0, 6, 5, true);
 lc.setLed(0, 6, 2, true);
 lc.setLed(0, 7, 3, true);
 lc.setLed(0, 7, 4, true);
}

void drawFour()                //function drawing 4 on the matrix
{
 lc.setLed(0, 1, 4, true);
 lc.setLed(0, 2, 3, true);
 lc.setLed(0, 3, 2, true);
 lc.setLed(0, 3, 3, true);
 lc.setLed(0, 3, 4, true);
 lc.setLed(0, 3, 5, true);
 lc.setLed(0, 4, 4, true);
 lc.setLed(0, 5, 4, true);
 lc.setLed(0, 6, 4, true);
}

void drawSad()                 //function drawing a sad smiley on the matrix
{
 lc.setLed(0, 1, 1, true);
 lc.setLed(0, 2, 1, true);
 lc.setLed(0, 1, 2, true);
 lc.setLed(0, 2, 2, true);
 lc.setLed(0, 1, 5, true);
 lc.setLed(0, 1, 6, true);
 lc.setLed(0, 2, 5, true);
 lc.setLed(0, 2, 6, true);
 lc.setLed(0, 6, 1, true);
 lc.setLed(0, 5, 2, true);
 lc.setLed(0, 5, 3, true);
 lc.setLed(0, 5, 4, true);
 lc.setLed(0, 5, 5, true);
 lc.setLed(0, 6, 6, true);
}

void drawHeart()               //function drawing a heart on the matrix
{
 lc.setLed(0, 1, 2, true);
 lc.setLed(0, 1, 6, true);
 lc.setLed(0, 2, 1, true);
 lc.setLed(0, 2, 3, true);
 lc.setLed(0, 2, 5, true);
 lc.setLed(0, 2, 7, true);
 lc.setLed(0, 3, 1, true);
 lc.setLed(0, 3, 4, true);
 lc.setLed(0, 3, 7, true);
 lc.setLed(0, 4, 1, true);
 lc.setLed(0, 4, 7, true);
 lc.setLed(0, 5, 2, true);
 lc.setLed(0, 5, 6, true);
 lc.setLed(0, 6, 3, true);
 lc.setLed(0, 6, 5, true);
 lc.setLed(0, 7, 4, true);
}

void clearMatrix()              //function that clears the matrix
{
 for (int i = 0; i < 8; i++)
 {
  for (int j = 0; j < 8; j++)
  {
    matrix[i][j] = 0;
  }
 }
}

void showMatrix()                  //function used for verifying the matrix
{              
 for (int i = 0; i < 8; i++)
 {
  for (int j = 0; j < 8; j++)
  {
    Serial.print(matrix[i][j]);
  }
  Serial.println(" ");
 }
}

void checkMatrix()                  //function that checks whether a full column is lit or not
{
  fullCol = 1;
  int count = 0;
  if (level == 3 || level == 1) 
  {
    for (int i = 0; i < 8; i++)
    {
      if (matrix[i][3] == 0)
      {
        fullCol = 0;
      }
    }
    if (fullCol == 1)
    {
      count++;
      fullCol = 1;
      for (int i = 0; i < 8; i++)
      {
        if (matrix[i][4] == 0)
        {
          fullCol = 0;
        }
      }
     if (fullCol == 1)
     {
       count++;
     }
     if (count >= 1)
     {
       fullCol = 1;
     }
    }
   }
   if (level == 2)
   {
     for (int i = 1; i < 7; i++)
     {
       if (matrix[i][3] == 0)
       {
         fullCol = 0;
       }
     }
     if (fullCol == 1)
     {
       count++;
       fullCol = 1;
       for (int i = 1; i < 7; i++)
       {
         if (matrix[i][4] == 0)
         {
           fullCol = 0;
         }
       }
     }
     if (fullCol == 1)
     {
       count++;
       fullCol = 1;
       for (int i = 1; i < 7; i++)
       {
         if (matrix[i][5] == 0)
         {
           fullCol = 0;
           if (count >= 1)
           {
             fullCol = 1;
           }
         }
       }
     }
   }
}
  
void drawBase(int length)               //function that draws the base line with a given length
{
 switch (length)
 {
    case 4:   
    {
      for (int col = 2; col < 6; col++)   
      {
        lc.setLed(0, 7, col, true);
        matrix[7][col] = 1; 
      }
      break;
    }
    case 3:
    {   
      for(int col = 3; col < 6; col++)
      {
        lc.setLed(0, 7, col, true);
        matrix[7][col] = 1; 
      }
      break;
    }
    case 2:
    {
      lc.setLed(0,7,3,true);
      lc.setLed(0,7,4,true);
      matrix[7][3] = 1; 
      matrix[7][4] = 1;
      break;
    }
    case 1:
    {  
      lc.setLed(0,7,4,true);
      matrix[7][4] = 1; 
      break;
    }
 }
}

void valid(int length)                    //function that checks if the current line is at the end of the row 
{
 if (level == 4)
 {
   if (stopped-length != 4) 
   {
      reset = 1;  
   }
 }
 if (level == 3)
 {
   if (stopped-length < 2 || stopped-length > 4) 
   {
     reset = 1;  
   }
 }
 if (level == 2)
 {
   if (stopped-length < 1 || stopped-length > 5) 
   {
     reset = 1;
   }
 }
 if (level == 1)
 {
   if (stopped-length > 4) 
   {
     reset = 1;
   }
 }
}

void lifePrint()                  //function that prints the current number of hearts left in the current game
{
  lcd.clear();
  if (life == 1)
  {
    lcd.print(life);
    lcd.print(" heart left");
  }
  else
  {
    lcd.print(life);
    lcd.print(" hearts left");
  }
}

void movement(int rowNumber, int length)            //function that moves the line on the matrix
{
 if (life == 0) 
 {
   level = 5;
   return 0;
 }  
 for (int col = 0; col < length; col++)    
 { 
   if ((millis() - lastUpdate) >= delayTime)
   {
     lastUpdate = millis();
     lc.setLed(0, rowNumber, col, true); 
     matrix[rowNumber][col] = 1;
   }
   else 
   {
     col--;
   }
 }
 int i = length-1;
 int pressed = 0;
 while (i < 13) 
 {
   if ((millis() - lastUpdate) >= delayTime)
   {
     lastUpdate = millis();
     if(digitalRead(buttonPin) == HIGH)
     {
       stopped = i;
       pressed = 1;
       i = 14;
     }
     else if(i < 8) 
     {
       lc.setLed(0, rowNumber, i, true);
       matrix[rowNumber][i] = 1;
       lc.setLed(0, rowNumber, i-length, false);
       matrix[rowNumber][i-length] = 0;
     }
     else 
     {
       lc.setLed(0, rowNumber, i-length, false);
       matrix[rowNumber][i-length] = 0;
     }
     i++;
   }
 }
 reset = 0;
 valid(length); 
 if (i == 13 || reset == 1) 
 {  
   life--;
   lcd.clear();
   lifePrint();  
   for (int clr = 0; clr < 8; clr++) 
   {  
      lc.setLed(0, rowNumber, clr, false);
      matrix[rowNumber][clr] = 0;
   }
   movement(rowNumber, length);
 }
 else if (rowNumber > 1) 
 {  
   movement(rowNumber-1, length);
 }
 else 
 {
   checkMatrix();
   if (fullCol == 1)
   {
     level++;
   } 
   else 
   {
     life--;  
     lifePrint();
   }
 }
}

void userInterraction()                    //function that checks if the button is pressed or not
{
 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH)
 {
   level = 1;
   lcd.clear();
   lcd.print("START!");
   lcd.setCursor(0,1);
   lcd.print("You get 5 hearts");
 }
 else
 {
   buttonState = 0;
 }
}

void drawUpperLine()                 //function that lights the upper line of the matrix 
{
 for (int col = 0; col < 8; col++)                                       
 {
   lc.setLed(0, 0, col, true); 
   matrix[0][col] = 1; 
 }
}

void firstLevel()                   //function that specifies the parameters and functions used in the first level
{
 int length = 4;
 int rowNumber = 6;
 drawBase(length);
 movement(rowNumber, length);
}

void secondLevel()                   //function that specifies the parameters and functions used in the second level
{
 int length = 3;
 int rowNumber = 6;
 drawBase(length);
 movement(rowNumber, length);
}

void thirdLevel()                    //function that specifies the parameters and functions used in the third level
{
 int length = 2;
 int rowNumber = 6;
 drawBase(length);
 movement(rowNumber, length);
}

void fourthLevel()                   //function that specifies the parameters and functions used in the fourth level
{
 int length = 1;
 int rowNumber = 6;
 drawBase(length);
 movement(rowNumber, length);
}

void fullMatrix()                      //function that lights all the leds of the matrix
{ 
 for (int row = 0; row < 8; row++)
 {
   for (int col = 0; col < 8; col++)
   {
     lc.setLed(0, row, col, true); 
   }
 }
}

void gameOver()                //function for printing and ending the game
{
 lcd.clear();
 if (life == 0)
 {
   drawSad();
   lcd.clear();
   lcd.print("YOU LOSE!");
 }
 else
 {
   drawHeart();
   lcd.clear();
   lcd.print("YOU WIN!");
 }
 delay(250);
 lcd.setCursor(0,1);
 lcd.print("Press to play");
 level = 0;
 life = 5;
}

void loop()
{
 if (level == 0)
 {
   userInterraction();
 }
 switch (level)                     
 {
       case 1:
       {
         lc.clearDisplay(0);
         clearMatrix();
         drawOne();
         delay(1000);
         lc.clearDisplay(0);
         drawUpperLine();
         firstLevel();
         break;
       }
       case 2:
       {
         lc.clearDisplay(0);
         clearMatrix();
         drawTwo();
         delay(1000);
         lc.clearDisplay(0);
         drawUpperLine();
         secondLevel();
         break;
       }
       case 3:
       {
         lc.clearDisplay(0);
         clearMatrix();
         drawThree();
         delay(1000);
         lc.clearDisplay(0);
         drawUpperLine();
         thirdLevel();
         break;
       }
       case 4:
       {
         lc.clearDisplay(0);
         clearMatrix();
         drawFour();
         delay(1000);
         lc.clearDisplay(0);
         drawUpperLine();
         fourthLevel();
         break;
       }
       case 5:
       {
         lc.clearDisplay(0);
         gameOver();
         break;
       }
 }
}
