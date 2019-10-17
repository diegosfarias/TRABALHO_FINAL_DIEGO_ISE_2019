//Projeto final de ISI_2019 da UFRR.
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
int pino_D0 = 7;
int pino_A0 = A1;
int valor_a = 0;
int valor_d = 0;

//pinos do alarme/conter incendio.
int Rele = 3; //Pino Relé
int buzzer = 2; //Pino Buzzer

//configuraçoes de entrada e saida de dados.
void setup()
{
  Serial.begin(9600);
  pinMode(pino_A0, INPUT);
  pinMode(pino_D0, INPUT);
  pinMode(Rele, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.println("SISTEMA CONTRA INCENDIOS V1.0");
}
 
void loop()
{
  Serial.println("SISTEMA CONTRA INCENDIOS LIGADO");
  
  //Faz a leitura da entrada do sensor de fumaça e a transforma para porcentagem.
  valor = analogRead(pinSensor); 
  valor = map(valor, 0, 1023, 0, 100); 
  
  //Faz a leitura da entrada do sensor de fogo.
  valor_a = analogRead(pino_A0);
  valor_d = digitalRead(pino_D0);
 
  delay(500);
  
  //Verificaçao de possivel incendio.
  if (valor>=ValDesarm){
    Serial.println("posivel incendio detectado!");
    Serial.println(valor); //Escreve o valor na porta Serial
    Serial.println("Verificando a Existencia de Fogo");
    delay(100);
    
    //Dispara alarme de incêndio.
    if (valor_a != 0)
  	{
    	Serial.println("Fogo detectado !!!");
      digitalWrite(Rele, HIGH); //Liga relé para solenóide
  	  digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
      //Valores do sensor de chamas.
      Serial.print("analogica fogo: ");
  		Serial.print(valor_a);
  		Serial.print(" fogo digital: ");
  		Serial.println(valor_d);
      
      Serial.println("Alarme disparado!!!");
      Serial.println("Ativando as medidas contra incendios!");
    	
  		
  		delay(1000); //Tempo de disparo do alarme
  		digitalWrite(buzzer, LOW); //Desliga o alarme
  		delay(2000); //Aguarda
     
    }else{
      Serial.println("Apenas fumaça detctada");
      delay(100);
  	  digitalWrite(buzzer, HIGH); //Dispara alarme de vazamento ou possível incêndio
    
    }
    
 }else{
 	digitalWrite(Rele, LOW); //Caso contrário permaneça com o relé desligado
 }
 delay(1000);

}
