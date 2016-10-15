/*
SegaRead Arduino Code

This code reads the buttons pressed from the sega megadrive/genesis controller and sends the info to the pc via serial
For more info about how the controller works visit: https://jonthysell.com/2014/07/26/reading-sega-genesis-controllers-with-arduino/ (this was the website i reed the most about the genesis controller)
 */

// Initialize Variables, you can change them the way you connect your controller to arduino 
int up = 2;
int down = 3;
int left = 4;
int right = 5;
int ab = 8;
int select = 7;
int startc = 6;
int sent;
int used;

// the setup routine runs once when you press reset/turn on arduino :
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input and select as output:
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
  //the used variable is used to check if a button was pressed on a loop cycle 
  //(if not it just sends STOP to the computer to release any keys that are pressed)
 used = 0;
    // read the input pins:
  // print out the state of the buttons to serial:
  //Makes the controller to send info for the SELECT high (sega controller uses a multiplexer)
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

if (used == 0 ){
 Serial.print("STOP\n");
}

  delay(10);        // delay in between reads for stability
}



