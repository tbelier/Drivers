#define triggerPin 4      // Pin de trigger
#define echoPin 2         // Pin de echo
#define soundSpeed 343.0  // Vitesse du son (m/s)

// Init variables
long echoTime = 0;
float distance = 0;


void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
  Serial.println("--- Starting serial communciation ---");
  pinMode(triggerPin, OUTPUT);  
  pinMode(echoPin, INPUT);    
}


void loop()
{
  // Mandatory to make the sensor works
  digitalWrite(triggerPin, LOW);    // Make sure trigger pin is low
  delayMicroseconds(2);             // for at least 2µs
  digitalWrite(triggerPin, HIGH);   // Set trigger pin HIGH
  delayMicroseconds(10);            // for at least 10µs
  digitalWrite(triggerPin, LOW);    // Set LOW again

  echoTime = pulseInLong(echoPin, HIGH);
  distance = float(echoTime) / 2 * (soundSpeed / 10000.0);
  // Display :
  Serial.print("Distance = ");
  Serial.print((String)distance);
  Serial.println(" cm");
  // And wacht 500ms
  delay(500);
}
