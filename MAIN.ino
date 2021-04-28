const int trigPin =      7;
const int echoPin =      6;
int ENA =               11; //Represents Enable 1
int IN1 =               13; //Represents Input 1
int IN2 =               12; //Represents Input 2
int ENA2 =              10; //Represents Enable 2
int IN3 =                8; //Represents Input 3
int IN4 =                9; //Represents Input 4
float distance =         0; //The float command allows the distance to be measured by the distance sensor with accuracy.
/*Motor Driver Values for input and enable. */
void setup() {
  pinMode(trigPin, OUTPUT); // set the trigger pin as an output: it will output pulses of electricity
  pinMode(echoPin, INPUT); // set the echo pin as an input: it will measure the duration of pulses coming back from the distance sensor
  /* Establishing every pin as an output */
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  /* motors are off when the simulation starts */
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENA2, HIGH);
}
 
void loop() {
  //measure the distance from the sensor using getDistance() and store in your distance variable
  distance = getDistance();
  if (distance < 10) { //if an object / obstacle is close
    delay(5000);
    turn();
    delay(100);
    move();
  }
  else if (distance > 10) { //if the object is far away
    move(); // The function for moving the robot accordinly to it's servo motors.
  }
}
 
 
//------------------FUNCTIONS-------------------------------
 
// simply TURNING.
void turn() {
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
  delay(5000);
  //Stops all movement
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA2, 0);
}
// simply moving forward
void move() {
  // Moves forward for 5 secconds.
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA2, 200);
 
  delay(5000);
  //Stops all movement.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA2, 0);
}
 
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time
  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor
  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  return calculatedDistance;              //send back the distance that was calculated
}
