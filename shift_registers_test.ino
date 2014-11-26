// program to test using two 4094 shift registers 
//
// if everything is correct, it will light up one LED at a time
//
int latchPin = 10;
int clockPin = 11;
int dataPin = 12;

int testPin = 13;
volatile int state = HIGH;

void setup() {
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   pinMode(testPin, OUTPUT);
   digitalWrite(latchPin, 0); //make sure data isn't latched
   digitalWrite(testPin, state);
   
}

void loop() 
{ 
   unsigned long outputpattern = 1; //stores the output pattern as an unsigned long, that is, four bytes
   long pattern_first_byte; 
   long pattern_second_byte; 
   long pattern_third_byte; 
 
   for (int i=0 ; i < 24; i++)
   {
//       pattern_third_byte = (outputpattern >> 16) & 0x00F;
//       pattern_second_byte = (outputpattern >> 8) & 0x00F;
//       pattern_first_byte = outputpattern & 0x00F;
       if (state == HIGH)
       {
         pattern_third_byte = 0x000F;
         pattern_second_byte = 0x000F;
         pattern_first_byte = 0x000F;
       }
       else
       {
         pattern_third_byte = 0x0000;
         pattern_second_byte = 0x0000;
         pattern_first_byte = 0x0000;
       }
       
     
     
       shiftOut(dataPin, clockPin, MSBFIRST, (byte) pattern_third_byte); 
       shiftOut(dataPin, clockPin, MSBFIRST, (byte) pattern_second_byte); 
       shiftOut(dataPin, clockPin, MSBFIRST, (byte) pattern_first_byte); 
       
       digitalWrite(latchPin, 1); // flick the latch to put the data on the output pins
       
       delay(1);
       
       digitalWrite(latchPin, 0);
       
       delay(2500);
       
       outputpattern = outputpattern << 1; // shift the outputpattern left by one bit
       
       state = !state;
       digitalWrite(testPin, state);
   }
}
