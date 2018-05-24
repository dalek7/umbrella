void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  //delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    //char inChar = (char)Serial.read();
    int v = Serial.read();
    //v = v+1; 
    char vChar = (char) v;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Serial.println(vChar);
  }

}

