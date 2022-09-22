int numeros [4] ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
}

int estado = 0;
int v;
float suma;
void loop() {
  // put your main code here, to run repeatedly:
  if(estado == 0) {
    Serial.println("Ingresa el primer numero: ");
    estado = 1;
  }

  if(estado == 2) {
    Serial.println("Ingresa el segundo numero: ");
    estado = 3;  
  }

  if(estado == 4) {
    Serial.println("Ingresa el tercer numero: ");
    estado = 5;  
  }

  if(estado == 6) {
    Serial.println("Ingresa el cuarto numero: ");
    estado = 7;  
  }
  
  if(Serial.available()>0) {
    v = Serial.readString().toInt();
    if(estado == 1) {
      numeros[0] = v;
      Serial.println(v);
      estado = 2;
    }else if(estado == 3) {
      numeros[1] = v;
      Serial.println(v);
      estado = 4;
    }else if(estado == 5) {
      numeros[2] = v;
      Serial.println(v);
      estado = 6;
    }else if(estado == 7) {
      numeros[3] = v;
      Serial.println(v);
      estado = 8;
    }
  }
  //////
  if(estado == 8) {
    for(int i = 0; i<sizeof(numeros)/sizeof(numeros[0]); i++) {
      suma += numeros[i];
    }
    Serial.println("El promedio es:");
    Serial.println(suma / (sizeof(numeros)/sizeof(numeros[0])));
    estado = 0;
    suma = 0;
    }
}
