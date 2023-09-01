// defines pins numbers 
const int readPin = 9;
int Value = 0;
const int led = 10;

void setup() { 
pinMode(readPin, INPUT); // Sets the echoPin as an Input 
Serial.begin(9600); // Starts the serial communication
}

void loop() { 
// Clears the trigPin 
Value = digitalRead(readPin); 

delayMicroseconds(10); 
delayMicroseconds(10); 
delayMicroseconds(10); 
delayMicroseconds(10); 

if (Value == 1 )
{
  Serial.print("No Object Detected!!!");
  Serial.print(Value);
  Serial.print("\n");
  digitalWrite(led, LOW);

}

else {
  Serial.print("Object Detected!!! ");
  Serial.print(Value);
  Serial.print("\n");
  digitalWrite(led, HIGH);

}

} 