#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIBRE 0
#define BANQUE 1
#define JOUEUR 2
#define BANQUE_CACHEE 3

#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51

/**
*\file projet.c
*\brief Projet Black Jack
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 17 novembre 2014
*/

short cartes[52];
short nb_as_joueur;
short nb_as_banque;

/**
*\fn tirer_carte(short joueur)
*\brief tire aleatoirement une carte et l'associe au joueur
*/
short tirer_carte(short  joueur){
	srand(time(NULL));
	int num;
	num = rand()%52;
	while(cartes[num] != 0){
		num = rand()%52;
	}
	cartes[num] = joueur;
	return(num);
}

/**
*\fn afficher_carte(short num)
*\brief affiche la carte num lorsqu'elle est donnee
*/
void afficher_carte(short num){
	int valeur_cartes;
	valeur_cartes = num%13;
	if(valeur_cartes == 0){
		printf("As ");
	}else if(valeur_cartes == 10){
		printf("Valet ");
	}else if(valeur_cartes == 11){
		printf("Dame ");
	}else if(valeur_cartes == 12){
		printf("Roi ");
	}else{
		printf("%i ",valeur_cartes++);
	}
	if((num >= DEB_COEURS)&&(num <= FIN_COEURS)){
		printf("de coeur\n");
	}else if((num >= DEB_CARREAUX)&&(num <= FIN_CARREAUX)){
		printf("de carreau\n");
	}else if((num >= DEB_PIQUES)&&(num <= FIN_PIQUES)){
		printf("de pique\n");
	}else{
		printf("de trefle\n");
	}
}
