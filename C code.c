#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "arduino-serial-lib.c"
#include "arduino-serial-lib.h"


int main()
{
	char opr[3];        //Menüdeki işlemler için kullanıcıdan alınıcak olan değişkeni belirle
	char Port_Name = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);  //Arduino ile iletişimi aç
	
	printf("## WELCOME TO GTU ARDUINO LAB          ##\n");
	printf("## STUDENT NAME :YUNUS EMRE GEYIK      ##\n");
	printf("## PLEASE SELECT FROM THE FOLLOWING    ##\n");
	
	int i=1;
	
	while (i)    //Menü'nün tekrar tekrar gelmesini sağla
	{	
		printf("## MENU :                              ##\n");
	
		printf("(1)	TURN ON LED ON ARDUINO \n");      	
		printf("(2)	TURN OFF LED ON ARDUINO \n");		
		printf("(3)	FLASH ARDUINO LED 3 TIMES\n");		
		printf("(4)	SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO \n");
		printf("(5)	BUTTON PRESS COUNTER \n");
		printf("(0)	EXIT \n");

		printf("PLEASE SELECT A OPERATOR= \n");
		scanf(" %c",&opr[0]);      //kullanıcıdan operatör al

		switch(opr[0])    //Değişkeni belirle
		{


		case '1':    // opr 1 ise Arduinodaki msj=1'deki işlemi gerçekleştirir
		{
			write(Port_Name,opr,1 ); // Arduinoda portu belirle
			break;
		}
		case '2':  //opr 2 ise Arduinodaki msj=2'deki işlemi gerçekleştirir
		{
			write (Port_Name,opr,1); // Arduinoda portu belirle
			break;
		}
		case '3':  //opr 3 ise Arduinodaki msj=3'deki işlemi gerçekleştirir
		{
			write (Port_Name,opr,1); // Arduinoda portu belirle
			break;
		}
		case '4':  
		{	
			
			char result[20]; 
    		char inputNUM[10]; 
    		inputNUM[0]='4'; 
    		scanf("%s",inputNUM+1);  
    		char end='f';  
    		int dev = serialport_init("/dev/ttyUSB0", 9600);
    		serialport_write(dev, inputNUM); 
    		
    		serialport_read_until(dev,result,end,2000,3000);
    		printf("Square of number=");
    		printf("%s\n",result );    
			break;
		}
		case '5':
		{
			write (Port_Name,opr,1);
			break;
		}
		case '0' :     //kullanıcı 0'a basıp menüden çıkmak isterse çık  
		{
			printf("Finish\n");     
			i=0;
			break;
		}
		default: //kullanıcı geçersiz işlem değişkeni girdi
		{
			printf("INVALID OPERATOR OPTION \n");
			break;
		}
		
	}
	}
	return 0;
}

	

	
