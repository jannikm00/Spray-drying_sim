int K1 = 2; //B10 Milch
int K2 = 3; //B11 und B15 Füllstand
int K3 = 4; //B12 Druck
int K4 = 5; //B13 Temperatur
int K5 = 6; //B14 Gebläse
int K6 = 7; //B16 Abluft
void setup() {
  Serial.begin(9600);
  int Pin = 2;
  while (Pin <= 6) {
    pinMode(Pin, OUTPUT);
    Pin++;
  }
  digitalWrite(K1, LOW); //Keine Milch vorhanden
  digitalWrite(K2, LOW); //Füllstand: leer
  digitalWrite(K3, LOW); //Druck nicht vorhanden
  digitalWrite(K4, LOW); //Temperatur nicht erreicht
  digitalWrite(K5, LOW); //Gebläse aus
  digitalWrite(K6, LOW); //Abluft nicht vorhanden
}
void loop() {
  delay(1000);
  digitalWrite(K1, HIGH); //Milch vorhanden
  delay(1000);
  digitalWrite(K3, HIGH); //Druck vorhanden
  delay(1000);
  digitalWrite(K2, HIGH); //Füllstand: voll
  delay(1000);
  digitalWrite(K5, HIGH); //Gebläse an
  int temp = 0;
  if (temp < 127) //Temperatur erhöhen durch Gebläse
  {
    temp++;
    delay(100);
    Serial.println(temp);
  }
  else if (temp = 127) {
    digitalWrite(K4, HIGH); //Temperatur erreicht
    delay(1000);
    digitalWrite(K6, HIGH); //Abluft an
  }
  delay(1000);
  digitalWrite(K2, LOW);
  delay(1000);
  digitalWrite(K1, LOW); //Keine Milch vorhanden
  digitalWrite(K3, LOW); //Druck nicht vorhanden
  digitalWrite(K4, LOW); //Temperatur nicht erreicht
  digitalWrite(K5, LOW); //Gebläse aus
  digitalWrite(K6, LOW); //Abluft nicht vorhanden
}


