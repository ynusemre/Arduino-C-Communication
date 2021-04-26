
void setup() 
{
  pinMode(LED_BUILTIN,OUTPUT);  // ledi OUTPUT olarak tanımladık
  Serial.begin(9600);           //seri portumuzun baud Rate'inin 9600 olarak başlattık

}
void loop() 
{
  char msj;   // seri mesaji msj değişkenine aktarmak için olana değşken

  
  msj = Serial.read();   // seri mesaji msj değişkenine aktardık
   
  if(msj == '1')           // gelen veri 1 ise ledi i yak
  {
    digitalWrite(LED_BUILTIN,HIGH); 
  }
  if(msj == '2')          // gelen veri 2 ise ledi i kapat
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
  if(msj == '3')        // gelen veri 3 ise ledi 3 kez yanıp söndür  
  
  {
    for(int i=1;i<4;i++)
    {
      digitalWrite(LED_BUILTIN, HIGH);  //ledi yak 
      delay(518);                       //ledi belirlenen süre kadar beklet  
      digitalWrite(LED_BUILTIN, LOW);   //ledi kapat
      delay(518);                       //ledi belirlenen süre kadar beklet 
    }
  }
  if(msj == '4')  {
  int num1=Serial.parseInt();
  int result=num1*num1;
 
  Serial.println(result);  
  
char end='f';
Serial.println(end); 
  }
  
}
