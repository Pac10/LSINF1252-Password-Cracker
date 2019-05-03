#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "sha256.h"
#include "reverse.h"

char* tableauHash;
//tableau global où seront copiés tous les mots de passe à hasher 

int main(int argc, char * argv[]){
	tableauHash = malloc(sizeof(char)*320);
	if(tableauHash == NULL){
		return EXIT_FAILURE;
	}	
	//création des fonctions des threads avant la main
	return 0;
}
//Méthode qui va lire les mots de passe du fichier "filename" et qui les copiera dans le tableau "tableauHash"
int readAndWrite(char* filename){
	int fichier = open(filename,O_RDONLY);
	if (fichier == -1){
		return -1;
	}

	int lecture = 0;
	char* lu = (char*) malloc(sizeof(char)*32);
	if(lu == NULL){
		return -1;
	}
	//lecture des 32 bytes qui constituent le mot de passe
	for(int i=0;i<32;i++){
		lecture = read(fichier,(void*) (lu+i),sizeof(char));
		if(lecture == -1){
			return -1;
		}
	}
	//copie des bytes qui viennent d'être lus sur le tableau
	strncpy(tableauHash,lu,32);
	tableauHash = tableauHash+1;
	close(fichier);
	return 1;
}

