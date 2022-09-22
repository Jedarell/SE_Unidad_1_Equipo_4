int base, altura ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
}

int estado = 0;
int v;
void loop() {
  // put your main code here, to run repeatedly:
  if(estado == 0) {
    Serial.println("Ingresa la base del rectangulo: ");
    estado = 1;
  }

  if(estado == 2) {
    Serial.println("Ingresa la altura del rectangulo: ");
    estado = 3;  
  }
  
  if(Serial.available()>0) {
    v = Serial.readString().toInt();
    if(estado == 1) {
      base = v;
      Serial.println(base);
      estado = 2;
    }else if(estado == 3) {
      altura = v;
      Serial.println(altura);
      estado = 4;
    }
  }
  //////
  if(estado == 4) {
    Serial.println("El area del rectangulo es:");
    Serial.println(base * altura);
    estado = 0;
    }
}
