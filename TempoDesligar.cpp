#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<locale.h>


int menu(char options[5][100]){
	int ch;
	int select = 0;
	int size = 5;

	while(true){
		printf("Selecione uma das opcoes a seguir:\n");
		for(int i = 0; i < size; i++){
			if(select == i){
				printf("> %s\n", options[i]);
				continue;
			}
			printf("%s\n", options[i]);
		}
		
		ch = _getch();

		switch(ch){
			case 27:
				// Tecla ESC
				return -1;
				break;

			case 224: //Prefixo de tecla de setas
				ch = _getch();

				switch(ch){
					case 72:
						if(select > 0){
							select -= 1;
						} 
						break;

					case 80:
						if(select < size - 1){
							select += 1;
						}
						break;
				}
			break;
			

			case 13:
				return select;
				break;
		}
		system("cls");
	}
}

int main(){
	char options[5][100] = {"Horas", "Minutos", "Segundos", "Cancelar agendamento", "Fechar"};
	
	int time, hour, select;
	char string[100], timeName[100] = "segundos";
	char command[100] = "shutdown -s -t ";


	select = menu(options);

	switch(select){
		// Em Horas
		case 0:
			strcpy(timeName, "horas");
			break;

		case 1:
			strcpy(timeName, "minutos");
			break;
		case 3:
			strcpy(command, "shutdown -a");
			system(command);
			system("pause");
			return 0;
			break;
		case 4:
			return 0;
			break;
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
		case 0:
			time = time * 60 * 60;
			break;
		// Em minutos
		case 1:
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

