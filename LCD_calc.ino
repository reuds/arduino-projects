/* Serial arduino calculator
in this project, you can make basic
arithmetic with the help of arduino,
almost like a very rustic calculator.
It accepts two numbers and a signal, and
makes the operation, witch can be of +, -, * or /.
E.G. : send "2+3" (Without quotes and with no
space separing the info), and arduino answers 5.
Digit "7-3" and arduino te responde com 4.

Criado por João Paulo Rodrigues Poltronieri

Errors fixed, translations made and added LCD support by Demir Aslan 2019.

This code is on public domain
*/

#include <Arduino.h>
#include <LiquidCrystal.h>

// first of all, create variables to store
// the information sent to arduino

long number1; // first number of the calculation,
// sent through the Serial monitor

// If you take a look, it's a long varible, so
// we're able to use big numbers

long number2; // second number sent through the SM

char calSignal; // create a char variable to store
// the calcuation signal.

long result; // result of the calculation

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); // begins serial communications
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Enter calc to");
  lcd.setCursor(0,1);
  lcd.print("Serial Monitor");
  Serial.println();
  // prints this to test serial communication, and
  // prints a line space
}

void loop() {
  if(Serial.available() > 0) {
    // if there is data being sent to arduino,
    
    number1 = Serial.parseInt();
    // number1 will be the first number
    
    // Note the use of "Serial.parseInt, so,
    // in case you use 23, it stores in 
    // number1 the number 23
    
    // if we used Serial.read(), it would
    // only store 2
    
    calSignal = Serial.read(); // calSignal will be the first
    // info after the first number
    
    number2 = Serial.parseInt(); // stores the second
    // number in number2
    
    solve(); // Custom function to solve the calculations
 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Result = ");
    lcd.print(result);
    // Prints the result of the calculation
    lcd.setCursor(0,1);
    lcd.print("Enter calc"); // prints
    Serial.println(); // jumps a line
  }
}

void solve() { // Custom function that
  // solves the calculations
  
  switch (calSignal) {
    // Here we use "switch...case" to save some space on
    // the sketch. It's, basicaly, a function that verifies
    // various "if" statements.
    
    // Here, it verifies what's the value held by 
    // calSignal. Basicaly, it verifies the "signal"
    // of the calculation
    
    case '+' : // if calSignal is '+'
    result = number1 + number2; // sums the numbers
    // and makes result hold the value of the calculation
    break; // break to exit the "case"
    case '-' : // if calSignal is '-'
    result = number1 - number2; // subtracts the numbers
    // and makes result hold the value of the calculation
    break; // break to exit the "case"
    case '*' : // if calSignal is '*'
    result = number1 * number2; // multiplies the numbers
    // and makes result hold the value of the calculation
    break; // break to exit the "case"
    case '/' : // if calSignal is '/'
    result = number1 / number2; // divides the numbers
    // and makes result hold the value of the calculation
    // PS: in case the division isn't exact, the result 
    // will be the nearest integrer
    break; // break to exit the "case"
    default : // If it's not any of these...
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ERROR");
      // Creates an "error"
      Serial.println();
      result = 0;
  }
}
