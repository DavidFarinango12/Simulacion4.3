/*
 *CAPITULO IV: PERIFERICOS ESPECIALES
 *CODIGO 15: MANEJ DE INTERRUPCIONES
 *OBJETIVO: ACTIVAR JUEGO DE LEDS POR MEDIO DE LA INTERRUPCION 0 Y LA SELECCION DEL NUMERO DE VECES QUE QUERRAMOS JUGAR SE HARA CON LA OTRA INTERRUPCION 1
 *NOMBRE: RAFAEL FARINANGO
 *FUNCONES:   interrupt 0: Inicio del sistema e ingreso de veces de juego
 *            interrupt 1: contador
 *            attachInterrupt(Interrupt,rutina,modo)
 */

const int leds[6] = {13,12,11,10,9,8};
int on = 0;
int cont;
int i;
int j = 0;


void setup() {
  Serial.begin(9600);
  for(i=0; i<6 ;i++){
    pinMode(leds[i],OUTPUT);
  }
  i = 0;
  attachInterrupt(0,activacion,LOW);    //interupcion 0 se habilita
  attachInterrupt(1,contador,LOW);
}


void loop() {
  if(on == 2){
    for(i=0; i<cont; i++){
      for(j=0; j<6; j++){
        digitalWrite(leds[j],HIGH);
        delay(200);
        digitalWrite(leds[j],LOW);
        delay(200);
      }
    }
  }

}


void activacion(){
  switch(on){
    case 0:
      Serial.println("Inicio del Sistema");
      Serial.println("Igrese el numero de veces que desea jugar");
      on++;
    break;
    case 1:
      Serial.println("Inicio de Juego");
      on++;
    break;
    case 2:
      Serial.println("Fin de Juego");
      cont = 0;
      on = 0;
      i = 0;
    break;
  }
}


void contador(){
  if(on == 1){
    cont++;
    Serial.println(String("Juega ")+String(cont)+String(" veces"));
  }
}
