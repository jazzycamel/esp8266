#define ESP8266_LED 5

void setup() {
  Serial.begin(115200);
  while(!Serial) continue;
  delay(200);
  Serial.println("Starting...");
  pinMode(ESP8266_LED, OUTPUT);
}

void loop() {
  digitalWrite(ESP8266_LED, HIGH);
  delay(250);
  digitalWrite(ESP8266_LED, LOW);
  delay(250);
  digitalWrite(ESP8266_LED, HIGH);
  delay(250);  
  digitalWrite(ESP8266_LED, LOW);
  delay(500);
}
