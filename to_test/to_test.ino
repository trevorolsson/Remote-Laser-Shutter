#include <IRremote.h> // Package for IR remote detection
#include <Servo.h> // Servo package

#define on 0xE318261B // Put the signals for on and off here
#define off 0x52A3D41F

Servo servo;         // Making my servo an object
const int IR_IN = 2; // Initializing pin 3 for IR detection
int angle = 10;      // Initializing the angle
int direction = 0;   // Creating variable for direction

IRrecv irrecv(IR_IN);   // Creates a receiver object
decode_results results; // Assigns a variable to decoded results

void setup() {

  Serial.begin(9600);  // Prints to Serial monitor
  irrecv.enableIRIn(); // Enables the IR receiver
  servo.attach(4);     // Assigns a PIN to the IR receiver
  servo.writeMicroseconds(1500);
}

void loop() {
  IR_Switch(); // Calls the IR detection function 

}

void IR_Switch() {  // Creates a function that activates servo through IR detection
  if (irrecv.decode(&results)){         // If the IR receiver detects a signal and its results:
    Serial.println(results.value, HEX); // Print the results in hexidecimal form
    irrecv.resume();                    // Resume monitoring for a signal

    if (results.value == off){ // If the results received are the defined "off" hex code:
      direction = 1;    // Toggles the variable direction to 1
    }

    if (results.value == on){ // If the results received are the defined "off" hex code:
      direction = -1; // Toggles the variable direction to -1
    }
  
  
  if (direction == 1 && (angle != 100)){ // If direction is 1 and the angle of the servo =/= 90 degrees:
    angle += 1; // Increase the angle until angle = 90 (default start from zero)
    }
  if (direction == -1 && angle != 10){ // If direction is -1 and the angle of the servo =/= 0 degrees:
    angle -= 1; // Decrease the angle until the angle = 0 (will not move if started from zero)
    }
    servo.writeMicroseconds(map(angle, 0, 180, 1000, 2000)); // Writes the result to the servo, causing it to move
    delay(15);  // Give some delay so that the servo can move to the desired angle
  }
}
