int ledPin = 9;      // LED connected to digital pin 9
int analogPin = A3;   // potentiometer connected to analog pin 3 (A3)
int val = 0;         // variable to store the read value


void setup() {
  pinMode(ledPin, OUTPUT);  // sets the pin as output
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.print("read from A3=");
  Serial.println(val);
  delay(1);
  if(val<650) val=650;
  if(val>850) val=850;
  int ledDimming=map(val, 650, 850, 0, 255);
  Serial.print("send to PWM LED=");
  Serial.println(ledDimming);
  delay(1);
  analogWrite(ledPin, ledDimming); 
  delay(1);
}