// LED-Streifen oder 5 LEDs
// Zahleingeben -> so viele LEDs leuchten

// R E C E I V E R
#define BUTTON 2

int counter = 0;

boolean aktuell = false;
boolean letzte = false;
boolean steigendeF = false;

unsigned long zeit = 0;
unsigned long t = 100;
unsigned long wait2 = 0;
unsigned long printWait = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    counter = Serial.read() - 48;   // zahl von anderen arduino auslesen

    Serial.println(counter);
    LEDS(counter);
  }
}

void LEDS(int x) {
  x = x + 4;
  for (int i = 5; i <= 9; i++) {
    digitalWrite(i, LOW);
  }

  for (int i = 5; i <= x; i++) {
    digitalWrite(i, HIGH);
  }
}
