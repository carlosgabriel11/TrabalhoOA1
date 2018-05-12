#include "indices.h"

//function that creates the primary indexes
void criarPrimario(){
	//opening the two main files
	FILE *lista1 = fopen("lista1.txt", "r");
	FILE *lista2 = fopen("lista2.txt", "r");

	//opening the two files of primary indexes
	FILE *indice1 = fopen("indicelista1.ind", "w");
	FILE *indice2 = fopen("indicelista2.ind", "w");

	//a variable to get the elements of each string on then files
	char ch;

	//a state to check if the previous character is an space
	short int state = 0;

	//a counter to check how many characters have been put on the string of the indexes files
	short int counter = 0;

	//a variable to get the relative position of each string 
	long int pos;

	//creating the primary index file of the first main file
	while(1){
		if (counter == 0){
			pos = ftell(lista1);
		}

		if(counter == 30){
			counter = 0;

			//put the relative position of the register of the main file on the 
			//primary index file
			fprintf(indice1, "%ld", pos);

			//jump a line
			fputc('\n',indice1);

			//jump to the next register
			while(ch != '\n'){
				ch = fgetc(lista1);
			}


			continue;
		}

		//read the character
		ch = fgetc(lista1);

		if (ch == EOF){
			break;
		}


		//cheching if it is a space
		if(ch == ' '){
			if(state == 1){
				//fill with spaces until reach 30 characters
				for(;counter < 30;counter++){
					fputc(' ',indice1);
				}

				counter = 0;
				state = 0;

				//put the relative position of the register of the main file on the 
				//primary index file
				fprintf(indice1, "%ld", pos);

				//jump a line
				fputc('\n',indice1);

				//jump to the next register
				while(ch != '\n'){
					ch = fgetc(lista1);
				}

				continue;
			}
			if(state == 0){
				state = 1;
				continue;
			}
		}

		//write the character on the primary index file
		fputc(ch,indice1);

		counter++;

		if(state == 1){
			state = 0;
		}
	}

	fclose(lista1);
	fclose(indice1);

	//creating the primary index file of the second main file
	while(1){
		if (counter == 0){
			pos = ftell(lista2);
		}

		if(counter == 30){
			counter = 0;

			//put the relative position of the register of the main file on the 
			//primary index file
			fprintf(indice2, "%ld", pos);

			//jump a line
			fputc('\n',indice2);

			//jump to the next register
			while(ch != '\n'){
				ch = fgetc(lista2);
			}


			continue;
		}

		//read the character
		ch = fgetc(lista2);

		if (ch == EOF){
			break;
		}


		//cheching if it is a space
		if(ch == ' '){
			if(state == 1){
				//fill with spaces until reach 30 characters
				for(;counter < 30;counter++){
					fputc(' ',indice2);
				}

				counter = 0;
				state = 0;

				//put the relative position of the register of the main file on the 
				//primary index file
				fprintf(indice2, "%ld", pos);

				//jump a line
				fputc('\n',indice2);

				//jump to the next register
				while(ch != '\n'){
					ch = fgetc(lista2);
				}

				continue;
			}
			if(state == 0){
				state = 1;
				continue;
			}
		}

		//write the character on the primary index file
		fputc(ch,indice2);

		counter++;

		if(state == 1){
			state = 0;
		}
	}

	fclose(lista2);
	fclose(indice2);
}