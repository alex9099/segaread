/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int up = 2;
int down = 3;
int left = 4;
int right = 5;
int ab = 8;
int select = 7;
int startc = 6;
int sent;
int used;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  pinMode(ab, INPUT);
  pinMode(select, OUTPUT);
  pinMode(startc, INPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  // prin,t out the state of the button:
 used = 0;
  digitalWrite(select, HIGH);

if (digitalRead(up) == LOW){
  //0
  used = 1;
 Serial.print("UP\n");
  delay(20);


}
if (digitalRead(down) == LOW){
    used = 1;
  //1

 Serial.print("DOWN\n");
  delay(20);

 
}
if (digitalRead(left) == LOW){
     //2

  used = 1;
 Serial.print("LEFT\n");
  delay(20);
}


if (digitalRead(right) == LOW){
  //3

  used = 1;
 Serial.print("RIGHT\n"); 
  delay(20);


}
if (digitalRead(startc) == LOW){
    //4

  used = 1;
 Serial.print("C\n");
  delay(20);


}
if (digitalRead(ab) == LOW){
    //5

  used = 1;
 Serial.print("B\n");
  delay(20);


}

digitalWrite(select, LOW);

if (digitalRead(startc) == LOW){
    //6

  used = 1;
 Serial.print("START\n"); 
  delay(20);


}
if(digitalRead(ab) == LOW){
    //7
    used = 1;
 Serial.print("A\n");

 delay(20);
}
//if (used = 1){
//   Serial.print("DO\n");
//}

if (used == 0 ){
 Serial.print("STOP\n");
}

  delay(10);        // delay in between reads for stability
}



