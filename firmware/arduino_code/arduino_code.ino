// HC-SR04 PIN Configuration
const int trigPin = D2;
const int echoPin = D3;

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send 10us HIGH pulse to trigger sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pin duration (in microseconds)
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (Speed of Sound = 34300 cm/s)
  distance = (duration * 0.0343) / 2;

  // Send data via Serial to host computer
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(200);  // Adjust for sampling rate
}
