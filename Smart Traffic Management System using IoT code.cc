// Pin sensor Pir
int sh = 2;
int sv = 3;

// Valores de los sensores
int valh = 0;
int valv = 0;

// Pin semaforo vertical
int rv = 5;
int av = 6;
int vv = 7;

// Pin semaforo horizontal
int rh = 11;
int ah = 12;
int vh = 13;

void setup()
{
  for (int i = 5; i <= 13; i++) {
  	pinMode(i, OUTPUT);
  }
  pinMode(sh, INPUT);
  pinMode(sv, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valh = digitalRead(sh);
  valv = digitalRead(sv);
  
  Serial.print("Horizontal: ");
  Serial.println(valh);
  Serial.print("Vertical: ");
  Serial.println(valv);
  Serial.println();
  
  int th1 = 3000;
  int th2 = 400;
  
  int tv1 = 3000;
  int tv2 = 400;
  	
  if (valh == HIGH && valv == LOW) {
  	Serial.println("Aumentar Horizontal");
    th1 = th1 * 2;
    th2 = th2 * 2;
  } else if (valh == LOW && valv == HIGH) {
    Serial.println("Aumentar Vertical");
    tv1 = tv1 * 2;
  	tv2 = tv2 * 2;
  }
  
  semaforoHorizontal(th1, th2);
  semaforoVertical(tv1, tv2);
}

void semaforoHorizontal(int t1, int t2) {
  digitalWrite(rv, HIGH);
  digitalWrite(vh, HIGH);
  delay(t1);
  digitalWrite(vh, LOW);
  digitalWrite(ah, HIGH);
  delay(t2);
  digitalWrite(rv, LOW);
  digitalWrite(ah, LOW);
}

void semaforoVertical(int t1, int t2) {
  digitalWrite(rh, HIGH);
  digitalWrite(vv, HIGH);
  delay(t1);
  digitalWrite(vv, LOW);
  digitalWrite(av, HIGH);
  delay(t2);
  digitalWrite(rh, LOW);
  digitalWrite(av, LOW);
}
