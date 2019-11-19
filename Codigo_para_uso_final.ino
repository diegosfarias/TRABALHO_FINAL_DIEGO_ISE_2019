//Projeto final de ISE_2019 da UFRR.
//Sistema contra incendios.
//Autor: Diego souza Farias.
//Email: (diegofarias2222@gmail.com).


//pinos e declaraçoes do sensor de fumaça.
int pinSensor =A0;


//Variável para selecionar a quantidade de Gás/Fumaça detectada.
int ValDesarm = 16; 
int valor = 0;

//pinos e declaraçoes do sensor de fogo.

int valor_d = 0;
int pino_D0 = 7;

//pinos do alarme/conter incendio.
int Rele = 3; //Pino Relé
int buzzer = 2; //Pino Buzzer

//configuraçoes de entrada e saida de dados.
void setup()
{
  Serial.begin(9600);
  pinMode(pino_D0, INPUT);
  pinMode(pinSensor, INPUT);
  
  pinMode(Rele, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
}
 
void loop()
{
  
  
  //Faz a leitura da entrada do sensor de fumaça e a transforma para porcentagem.
  valor = analogRead(pinSensor); 
  valor = map(valor, 0, 1023, 0, 100); 
  
  //Faz a leitura da entrada do sensor de fogo.
int valor_d = digitalRead (pino_D0);
 
  
  
  //Verificaçao de possivel incendio.
  if (valor>=ValDesarm){
    
    
    
    //Dispara alarme de incêndio.
    if (valor_d != 1)
    {
     
      
      //Ativa as medidas contra incendios.
      digitalWrite(Rele, HIGH);
      
      //Dispara alarme de incêndio.
       
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
     
    }else{
      
      delay(100);
      //Dispara alarme de incêndio.
       
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    
    }
    
 }else{
  digitalWrite(Rele, LOW); //Caso contrário permaneça com o relé desligado
 }
  delay(1000);
  Serial.println("SISTEMA CONTRA INCENDIOS LIGADO");

}
