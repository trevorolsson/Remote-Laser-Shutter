#include <IRremote.h> // Package for IR remote detection
#include <Servo.h> // Servo package

#define on 0xE318261B
#define off 0x52A3D41F

Servo servo;         // Making my servo an object
const int IR_IN = 2; // Initializing pin 3 for IR detection
int angle;           // Initializing the angle
bool cw, ccw;        //, swon, swoff; // Creating boolean variables (for remote IR, for buttons)

IRrecv irrecv(IR_IN);   // Creates a receiver object
decode_results results; // Assigns a variable to decoded results

void setup() {

  Serial.begin(9600);  // Prints to Serial monitor
  irrecv.enableIRIn(); // Enables the IR receiver
  servo.attach(4);     // Assigns a PIN to the IR receiver
  servo.write(10);
  cw = !ccw;
}

void loop() {
  IR_Switch(); // Calls the IR detection function 

}

void IR_Switch() {  // Creates a function that activates servo through IR detection
  if (irrecv.decode(&results)){         // If the IR receiver detects a signal and its results:
    Serial.println(results.value, HEX); // Print the results in hexidecimal form
    irrecv.resume();                    // Resume monitoring for a signal

    if (results.value == off){ // If the results received are the defined "off" hex code:
      cw = !cw;    // Toggles the boolean cw to true
      ccw = false; // Toggles the boolean ccw to false
    }

    if (results.value == on){ // If the results received are the defined "off" hex code:
      ccw = !ccw; // Toggles the boolean ccw to true
      cw = false; // Toggles the boolean cw to false
    }
  
  
  if (cw && (angle != 100)){ // If cw is true and the angle of the servo =/= 90 degrees:
    while(angle != 100){
    angle++; // Increase the angle until angle = 90 (default start from zero)
      }
    }
  if (ccw && angle != 10){ // If ccw is true and the angle of the servo =/= 0 degrees:
    while(angle != 10){
    angle--; // Decrease the angle until the angle = 0 (will not move if started from zero)
      }
    }
    servo.write(angle); // Writes the result to the servo, causing it to move
    //delay(1);         // Delays any command for 1ms
  }
}
