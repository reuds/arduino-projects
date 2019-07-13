
/* A simple program to sequentially turn on and turn off 5 LEDs. */ 
/* Modified from original by Demir Yusuf Aslan in 2019 as his first project.*/
/* Special thanks to the youtuber that shared this sketch. I forgot his name.*/

/* LED pins */
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;


void setup() {
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);
}


void loop() {

  /* I worked hard on this part to make the LEDs blink in sequence 
  (only three leds active at any moment). 
  Inspired by WinXP's boot screen. */
  
  digitalWrite(LED1, HIGH);    
  delay(300);                
  digitalWrite(LED2, HIGH);    
  delay(300);                      
  digitalWrite(LED3, HIGH);    
  delay(300);                  
  digitalWrite(LED4, HIGH);                     
  digitalWrite(LED1, LOW);  
  delay(300);              
  digitalWrite(LED5, HIGH);    
  digitalWrite(LED2, LOW);     
  delay(300);                
  digitalWrite(LED3, LOW);   
  delay(300);                  
  digitalWrite(LED4, LOW);     
  delay(300);          
  digitalWrite(LED5, LOW);
  delay(300);     
}
