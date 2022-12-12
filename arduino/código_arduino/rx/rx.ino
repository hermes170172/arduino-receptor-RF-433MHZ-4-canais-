
 
#include <EEPROM.h>
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

#define btn 3
#define ledprog 4
#define l3 5
#define l4 8
#define l1 6
#define l2 7
#define jp1 9 
#define jp2 10
#define jp3 11
#define jp4 12
#define pot A0
#define pot2 A1
//===============Variaveis globais=================
 unsigned long valor;
 unsigned int recebe;
 unsigned int v1;
 boolean executa = false;
 unsigned int tempo = 0;
 unsigned static int cont =0;
 static boolean paraLimpa;
 static boolean controleprog=0;
 static int cont2 =0;
 boolean controle1 = false;
 boolean controle2 = false;
 boolean controle3 = false;
 boolean controle4 = false;
 boolean estadoRele1 = false;
 boolean estadoRele2 = false;
 boolean estadoRele3 = false;
 boolean estadoRele4 = false;
 boolean controleRX = false;
 boolean estadoL1 =false;
 boolean estadoL2 =false;
 boolean maior70 =false;
 boolean maior70_2 = false;
 boolean autentica1 = false;

unsigned  int valorPot = 0;
unsigned  int valorPot2 = 0;

unsigned  long tempoPot =0;
unsigned  long tempoPot2 =0;

unsigned  long inicioPot=0;
unsigned  long inicioPot2=0;

int a = 0;
int b = 0;
//==============Protótipos das funções=============
void escreve(int endereco, int valor);
int le (int endereco, int valor);
void piscaLed(int nVezes, int nDelayHIGH,int nDelayLOW);

void (* resetFunc) (void) = 0; 
//=================================================

void setup() 
 {     
       Serial.begin(9600);
       pinMode(pot,INPUT);
       pinMode(pot2,INPUT);
       pinMode(btn,INPUT_PULLUP);
       pinMode(jp1,INPUT_PULLUP);
       pinMode(jp2,INPUT_PULLUP);
       pinMode(jp3,INPUT_PULLUP);
       pinMode(jp4,INPUT_PULLUP);
       pinMode(ledprog,OUTPUT);
       pinMode(l1,OUTPUT);
       pinMode(l2,OUTPUT);
       pinMode(l3,OUTPUT);
       pinMode(l4,OUTPUT);
       mySwitch.enableReceive(0);
       v1 = le(0,v1);
      
       piscaLed(10,150,100);
 }
//====================================================================
void loop() 
{  
 boolean leJp1 = digitalRead(jp1);
 boolean leJp2 = digitalRead(jp2);
 boolean leJp3 = digitalRead(jp3);
 boolean leJp4 = digitalRead(jp4);
 boolean leBtn = digitalRead(btn);

 if(leBtn == 0 && paraLimpa != 1)
 {
          Serial.println("Botao apertado");
          cont++;
          controleprog = 1;
          cont2=1;
          Serial.println(cont);
          delay(300);
     
  }
//=================================Grava eeprom=============================================  
 if(leBtn == 1  && controleprog == 1)
 {
          digitalWrite(ledprog,HIGH);
          delay(80);
          digitalWrite(ledprog,LOW);
          delay(70);
          cont++;
          Serial.println(cont);
          delay(300);

if(mySwitch.available())
 {
       valor = mySwitch.getReceivedValue();
       recebe = valor/100000+(valor%100000);
       Serial.print("V de recebe: ");
       Serial.println(recebe);
       
if(leJp1 == 0)
 {  
  mySwitch.resetAvailable();
  while(a == 0 && b <= v1){
    b++;
    mySwitch.resetAvailable();
    if(le(b,b) == recebe + 1){
      mySwitch.resetAvailable();
    a=1;
    b++;
  }
}
  if(a==1)
  {
    mySwitch.resetAvailable();
     cont =0;
     controleprog=0;
      a=0;
      resetFunc();
  }
  else{
      v1+=sizeof(int);
      escreve(0,v1);
      escreve(v1,recebe + 1);
      digitalWrite(ledprog,LOW);
      mySwitch.resetAvailable();
      cont =0;
      controleprog=0;
  }
}
 
if(leJp2 == 0)
 {  
  mySwitch.resetAvailable();
  while(a == 0 && b <= v1){
    b++;
    mySwitch.resetAvailable();
    if(le(b,b) == recebe + 2){
      mySwitch.resetAvailable();
    a=1;
    b++;
  }
}
  if(a==1)
  {
    mySwitch.resetAvailable();
    cont =0;
    controleprog=0;
    a=0;
    resetFunc();
  }
  else{
      v1+=sizeof(int);
      escreve(0,v1);
      escreve(v1,recebe + 2);
      digitalWrite(ledprog,LOW);
      mySwitch.resetAvailable();
      cont =0;
      controleprog=0;
  }
}

 if(leJp3 == 0)
 {  
  mySwitch.resetAvailable();
  while(a == 0 && b <= v1){
    b++;
    mySwitch.resetAvailable();
    if(le(b,b) == recebe + 3){
      mySwitch.resetAvailable();
    a=1;
    b++;
  }
}
  if(a==1)
  {
    mySwitch.resetAvailable();
     cont =0;
     controleprog=0;
     a=0;
      resetFunc();
  }
  else{
      v1+=sizeof(int);
      escreve(0,v1);
      escreve(v1,recebe + 3);
      digitalWrite(ledprog,LOW);
      mySwitch.resetAvailable();
      cont =0;
      controleprog=0;
  }
}

 if(leJp4 == 0)
 {  
       mySwitch.resetAvailable();
  while(a == 0 && b <= v1){
       b++;
       mySwitch.resetAvailable();
   if(le(b,b) == recebe + 4){
      mySwitch.resetAvailable();
      a=1;
      b++;
  }
}
  if(a==1)
  {
      mySwitch.resetAvailable();
      cont =0;
      controleprog=0;
      a=0;
      resetFunc();
  }
  else{
      v1+=sizeof(int);
      escreve(0,v1);
      escreve(v1,recebe + 4);
      digitalWrite(ledprog,LOW);
      mySwitch.resetAvailable();
      cont =0;
      controleprog=0;
  }
}
 
   mySwitch.resetAvailable();
   }
        
  if(cont>30 && leBtn == 1)
  {
        cont=0;
        controleprog = 0;
        digitalWrite(ledprog,LOW);
        resetFunc();
  }
 }

 //==============================LIMPA EEPROM=================================================
   if(leBtn == 0 && cont >30 && cont2 == 1)
   {
        for(int i=0;i<=v1;i++)
    {
        EEPROM.write(i,0);
    }
    digitalWrite(ledprog,HIGH);
    delay(3000);
    digitalWrite(ledprog,LOW);
        v1 = 0;
        controleprog=0;
        cont=0;
        paraLimpa = 1;
        cont2 = 0;
        Serial.print("V de v1: ");
        Serial.println(v1);
       resetFunc (); 
   }
//===================================ACIONA SAIDAS TEMPORIZADAS================================================


//==============loop rele 1========================
    if(maior70)
    {
        estadoL1 = true;
        inicioPot = millis();
        maior70 = false;
    }
       if(estadoL1)
       {
         if((millis() - inicioPot) < tempoPot)
         {
            digitalWrite(l1,HIGH);
         }
     
       else
       {
        digitalWrite(l1,LOW);
        estadoL1 = false;
      }
  }
//=============loop rele 2=======================  
     if(maior70_2)
    {
        estadoL2 = true;
        inicioPot2 = millis();
        maior70_2 = false;
    }
       if(estadoL2)
       {
         if((millis() - inicioPot2) < tempoPot2)
         {
            digitalWrite(l2,HIGH);
         }
     
       else
       {
        digitalWrite(l2,LOW);
        estadoL2 = false;
      }
  }
//=====================================================    
        valorPot = analogRead(pot);
        tempoPot =  map(valorPot,0,256,0,150000);

        valorPot2 = analogRead(pot2);
        tempoPot2 =  map(valorPot2,0,256,0,150000);
        

     if(mySwitch.available())
     {
      valor = mySwitch.getReceivedValue();
      recebe = valor/100000+(valor%100000);
      
       Serial.print("V de recebe: ");
       Serial.println(recebe);
       
       Serial.print("valorPot: ");
       Serial.println(valorPot);

       Serial.print("valorPot2: ");
       Serial.println(valorPot2);
       
    for(int i=0;i<=v1; i+=sizeof(int))
      {
       if(recebe + 1 == le(i,i))
      {
         mySwitch.disableReceive();
         mySwitch.resetAvailable(); 
         controle1 = true; 
         controleRX = true;
     }
    else if (recebe + 2 == le(i,i))
      {
          mySwitch.disableReceive();
          mySwitch.resetAvailable(); 
          controle2 = true;
          controleRX = true;
      }
    else if (recebe + 3 == le(i,i))
      {
          mySwitch.disableReceive();
          mySwitch.resetAvailable(); 
          controle3 = true;
          controleRX = true;
      }
    else if (recebe + 4 == le(i,i))
      {
          mySwitch.disableReceive();
          mySwitch.resetAvailable(); 
          controle4 = true;
          controleRX = true;
      }
    }
//===============Rele 1======================== 
   if(controle1 && leJp1 == 1)
      {
           digitalWrite(l1,HIGH);
           delay(500);
           digitalWrite(l1,LOW);
           controle1 = false;
     }
   else if(controle1 && leJp1 == 0 && valorPot < 10)
   {
         estadoRele1 = !estadoRele1;
         digitalWrite(l1,estadoRele1);
         controle1 = false;
   }

   else if(controle1 && leJp1 == 0 && valorPot >= 10)
   {
      maior70 = true;
      controle1 = false;
   }
//===============Rele 2=======================      
    if(controle2 && leJp2 == 1)
      {
           digitalWrite(l2,HIGH);
           delay(500);
           digitalWrite(l2,LOW);
           controle2 = false;
      }
   else if(controle2 && leJp2 == 0 && valorPot2 < 10)
      {
         estadoRele2 = !estadoRele2;
         digitalWrite(l2,estadoRele2);
         controle2 = false;
      }

   else if(controle2 && leJp2 == 0 && valorPot2 >= 10)
   {
      maior70_2 = true;
      controle2 = false;
   }
      
//==============Rele 3========================= 
   if(controle3 && leJp3 == 1)
      {
           digitalWrite(l3,HIGH);
           delay(500);
           digitalWrite(l3,LOW);
           controle3 = false;
      }
    else if(controle3 && leJp3 == 0)
      {
         estadoRele3 = !estadoRele3;
         digitalWrite(l3,estadoRele3);
         controle3 = false;
      }
//==============Rele 4=========================
   if(controle4 && leJp4 == 1)
      {
           digitalWrite(l4,HIGH);
           delay(500);
           digitalWrite(l4,LOW);
           controle4 = false;
      }
    else if(controle4 && leJp4 == 0)
      {
         estadoRele4 = !estadoRele4;
         digitalWrite(l4,estadoRele4);
         controle4 = false;
      }    
//=========================================    
mySwitch.resetAvailable();
     }
      if(controleRX){
        cont++;
        Serial.println(cont);
      if(cont>100){
        mySwitch.enableReceive(0);
        cont = 0;
        controleRX = false;
     }
   }  
 }
void piscaLed(int nVezes, int nDelayHIGH,int nDelayLOW){
  for(int i=0;i<nVezes;i++){
    digitalWrite(ledprog,HIGH);
    delay(nDelayHIGH);
    digitalWrite(ledprog,LOW);
    delay(nDelayLOW);
    }
  }

//===================================================================
void escreve(int endereco, int valor)
{
      EEPROM.put(endereco,valor);
}
//=====================================================================
int le(int endereco, int valor )
{
    EEPROM.get(endereco,valor);
    return valor;
}
