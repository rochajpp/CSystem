#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int time, hour, select;
	char string[100];
	char command[100] = "shutdown -s -t ";
	
	printf("Insira o tempo para desligar o PC\n>> ");
	scanf("%d", &select);

	time = select;
	
	system("cls");
	
	printf("Selecione uma das opcoes abaixo:\n\n1.Horas\n2.Minutos\n3.Segundos\n\n>> ");
	scanf("%d", &select);


	// Convertendo a hora para segundos
	switch(select){
		// Em Horas
		case 1:
			time = time * 60 * 60;
			break;
		// Em minutos
		case 2:
			time = time * 60;
			break;
	}
	
	
	// Convertendo o tempo em string
	sprintf(string, "%d", time);
	
	// Concatenando comando com o tempo
	strcat(command, string);
		
	// printf("%s\n", command);
	// system("pause");

	system(command);
		
	return 0;
}

