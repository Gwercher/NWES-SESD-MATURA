// LED-Streifen oder 5 LEDs
// Zahleingeben -> so viele LEDs leuchten

// S E N D E R
#define BUTTON 4

int counter = 0;

boolean aktuell = false;
boolean letzte = false;
boolean steigendeF = false;

unsigned long zeit = 0;
unsigned long t = 100;
unsigned long wait2 = 0;

void setup() {
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
}

void loop() {
  aktuell = digitalRead(BUTTON);

  steigendeF = aktuell && !letzte;

  if (steigendeF && millis() >= (zeit + t)) {
    zeit = millis();
    counter = (counter + 1) % 6;
  }

  if (millis() >= (5000 + wait2) ) {
    Serial.print(counter);    // zahl an anderen arduino senden
    counter = 0;
    wait2 = millis();
  }

  letzte = aktuell;
}
