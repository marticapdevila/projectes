#include <Stepper.h>
const int stepsPerRevolution = 2038; //the used stepper has to do 2038 steps for a full revolution.
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5); //stepper connections.

int led = 10;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT); //sets the led as an output.
  myStepper.setSpeed(15); //sets the stepper's speed at 15. Bigger speed will bug it.
  }

void loop() { // the loop routine runs over and over again forever:

int sensorValue = analogRead(A0); //defines the variable sensorValue as the input from the A0 port, to which the pr is connected.

  digitalWrite (led, HIGH); //sets the led always high to always have similar light conditions for the sensor.
  Serial.println(sensorValue); //comproves the value.

if (sensorValue <= 65){ //under 80 the pr is almost completely blocked, so it has to activate the sequence only then.
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution); //the stepper makes 2038 steps to make a full revolution.
  delay(3000); //there is a delay of 2 seconds to not overload the mechanism, avoiding constant rotation.
}
 
  delay(1);        // delay in between reads for stability.
}
