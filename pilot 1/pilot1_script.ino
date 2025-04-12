// Define the pins connected to the A4988
const int dirPin = 8;  // DIR pin
const int stepPin = 10; // STEP pin
const int enablePin = 12;
const int delay_speed = 600; // Delay between steps in microseconds

void setup() {
  // Set the pins as output
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // Motor is enabled
}

void loop() {
  // Set the direction to clockwise
  digitalWrite(dirPin, HIGH);

  // Calculate the number of steps to run in 3 seconds
  unsigned long startTime = millis(); // Get the current time
  while (millis() - startTime < 3000) { // Run for 3 seconds (3000 milliseconds)
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay_speed); // Delay between steps
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay_speed); // Delay between steps
  }
  digitalWrite(enablePin, HIGH); // Motor is disabled

  // Wait for 1 second before changing direction
  delay(10000);

 
}