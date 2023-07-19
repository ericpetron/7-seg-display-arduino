// Author Eric Petron, petro227@umn.edu

// #define DISP1 (PORTD ^= 0x84)
// #define DISP2 (PORTD ^=)

// the setup function runs once when you press reset or power the board
void setup() {
   Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}
char inp;
// the loop function runs over and over again forever
void loop() {

   Serial.println("send a 1 digit number to be displayed\nor 'r' for it to count up");

   
   if (Serial.available()) {
      inp = Serial.read();
   }

   if (inp == '1' || inp == '2'
      || inp == '3' || inp == '4' 
      || inp == '5' || inp == '6'
      || inp == '7' || inp == '8'
      || inp == '9' || inp == '0') {
      char digit = convertToInt(inp);
      displayNum(digit);
   }

   if (inp == 'r') {
      countUp();
   }
   delay(5000);
}


char convertToInt(char chr) {
   switch (chr) {
      case 48:
        return 0;
        break;
      case 49: 
        return 1;
        break;
      case 50: 
        return 2;
        break;
      case 51: 
        return 3;
        break;
      case 52: 
        return 4;
        break;
      case 53: 
        return 5;
        break;
      case 54: 
        return 6;
        break;
      case 55: 
        return 7;
        break;
      case 56: 
        return 8;
        break;
      case 57:
        return 9;
        break;
      default:
        return 'r';
        break;
   }
}




void displayNum(int num) {
   PORTB = 0x00;
   switch(num) {
         case 1 :
         PORTD = 0x84;
         break;
      case 2 :
         PORTD = 0x5C;// displays num 2
         PORTB = 0x01;
         break;
      case 3 :
         PORTD = 0xDC;
         break;
      case 4 :
         PORTD = 0xB4;
         break;
      case 5 :
         PORTD = 0xF8;
         break;
      case 6 :
         PORTD = 0xF8;
         PORTB = 0x01;
         break;
      case 7 :
         PORTD = 0x8C;
         break;
      case 8 :
         PORTD = 0xFC;
         PORTB = 0x01;
         break;
      case 9 :
         PORTD = 0xFC;
         break;
      case 0:
         PORTB = 0x01;
         PORTD = 0xEC;
         break;
      default :
        PORTD = 0xFC;
        PORTB = 0x01;
   }

}


void countUp() {
   for (int i = 0; i < 10; i++) {
    PORTB = 0x00;
    switch(i) {
      case 1 :
         PORTD = 0x84;
         break;
      case 2 :
         PORTD = 0x5C; // displays num 2
         PORTB = 0x01;
         break;
      case 3 :
         PORTD = 0xDC;
         break;
      case 4 :
         PORTD = 0xB4;
         break;
      case 5 :
         PORTD = 0xF8;
         break;
      case 6 :
         PORTD = 0xF8;
         PORTB = 0x01;
         break;
      case 7 :
         PORTD = 0x8C;
         break;
      case 8 :
         PORTD = 0xFC;
         PORTB = 0x01;
         break;
      case 9 :
         PORTD = 0xFC;
         break;
      case 0:
         PORTB = 0x01;
         PORTD = 0xEC;
         break;
      default :
        PORTD = 0xFC;
        PORTB = 0x01;
   }
   delay(1000);
  }
}