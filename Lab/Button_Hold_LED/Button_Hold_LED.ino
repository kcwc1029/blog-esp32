byte LED_PIN = 5;
byte BUTTON_PIN = 15;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    Serial.begin(115200);
}

void loop() {
    bool val = digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN, !val);
    Serial.print("Button State: ");
    Serial.println(val);
    delay(10);
}
