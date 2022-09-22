int num1, num2;

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
    Serial.println("Ingresa el numero 1: ");
    estado = 1;
  }

  if(estado == 2) {
    Serial.println("Ingresa el numero 2: ");
    estado = 3;  
  }
  
  if(Serial.available()>0) {
    v = Serial.readString().toInt();
    if(estado == 1) {
      num1 = v;
      Serial.println(num1);
      estado = 2;
    }else if(estado == 3) {
      num2 = v;
      Serial.println(num2);
      estado = 4;
    }
  }
  //////
  if(estado == 4) {
    Serial.println("El resultado es:");
    Serial.println(num1 + num2);
    estado = 0;
    }
}
