#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int time, hour, select;
	char string[100];
	char command[100] = "shutdown -s -t ";
	
	printf("Insira o tempo para desligar o PC (Em horas)\n>> ");
	scanf("%d", &hour);
	
	system("cls");
	
	printf("Selecione uma das opcoes abaixo:\n\na - %d horas\nb - %d minutos\nc - %d segundos\n\n>> ", hour, hour, hour);
	scanf("%c", &select);
	
	// Convertendo horas para segundo
	time = hour * 60 * 60;
	
	// Convertendo o tempo em string
	sprintf(string, "%d", time);
	
	// Concatenando comando com o tempo
	strcat(command, string);
				
	//system(command);
		
	return 0;
}
