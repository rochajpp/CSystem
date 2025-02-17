#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int time, hour, select;
	char string[100], timeName[100] = "segundos";
	char command[100] = "shutdown -s -t ";

	printf("Selecione uma das opcoes abaixo:\n\n1.Horas\n2.Minutos\n3.Segundos\n4.Cancelar agendamento\n\n>> ");
	scanf("%d", &select);

	switch(select){
		// Em Horas
		case 1:
			strcpy(timeName, "horas");
			break;

		case 2:
			strcpy(timeName, "minutos");
			break;
	}
	
	if(select == 4){
		strcpy(command, "shutdown -a");
		system(command);
		return 0;
	}
	
	system("cls");

	if(select == 1){
		printf("Insira quantas %s para desligar o PC\n>> ", timeName);
	}else{
		printf("Insira quantos %s para desligar o PC\n>> ", timeName);
	}
	scanf("%d", &time);
	
	
	
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

