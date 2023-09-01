int ledpin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i<=255; i++){
  Serial.print("\n i = ");
  Serial.print(i);
  analogWrite(ledpin, i);
}
for(int i=255; i>=0; i--){
  Serial.print("\n i = ");
  Serial.print(i);
  analogWrite(ledpin, i);
}
}
