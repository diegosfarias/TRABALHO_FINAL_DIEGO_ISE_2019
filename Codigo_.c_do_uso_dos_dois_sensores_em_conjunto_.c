//Projeto final de ISE_2019 da UFRR.
//Sistema contra incendios.
//Autor: Diego souza Farias.
//Email: (diegofarias2222@gmail.com).


//pinos e declaraçoes do sensor de fumaça.
int pinSensor =A0;
int var = 0;

//Variável para selecionar a quantidade de Gás/Fumaça detectada.
int ValDesarm = 30; 
int valor = 0;

//pinos e declaraçoes do sensor de fogo.

int pino_A0 = A1;
int valor_a = 0;


//pinos do alarme/conter incendio.
int Rele = 3; //Pino Relé
int buzzer = 2; //Pino Buzzer

//configuraçoes de entrada e saida de dados.
void setup()
{
  Serial.begin(9600);
  pinMode(pino_A0, INPUT);
  
  pinMode(Rele, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.println("SISTEMA CONTRA INCENDIOS V1.0");
  Serial.println("SISTEMA CONTRA INCENDIOS LIGADO");
}
 
void loop()
{
  
  
  //Faz a leitura da entrada do sensor de fumaça e a transforma para porcentagem.
  valor = analogRead(pinSensor); 
  valor = map(valor, 0, 1023, 0, 100); 
  
  //Faz a leitura da entrada do sensor de fogo.
  valor_a = analogRead(pino_A0);
  
 
  delay(500);
  
  //Verificaçao de possivel incendio.
  if (valor>=ValDesarm){
    Serial.println("posivel incendio detectado!");
    Serial.println(valor); //Escreve o valor na porta Serial
    Serial.println("Verificando a Existencia de Fogo");
    delay(200);
    
    //Dispara alarme de incêndio.
    if (valor_a != 0)
  	{
    	Serial.println("Fogo detectado !!!");
      	
      //Valores do sensor de chamas.
      Serial.print("analogica fogo: ");
  		Serial.print(valor_a);
  		
      
      Serial.println("Alarme disparado!!!");
      Serial.println("Ativando as medidas contra incendios!");
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
      Serial.println("Apenas fumaça detctada");
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
