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

/**
*\fn afficher_mains(short joueur)
*\brief affiche la main d'un joueur en utilisant la fonction afficher_carte
*/
void afficher_mains(short joueur){
	int num;
	for(num=0;num<52;num++){
		if(cartes[num]==joueur){
			afficher_carte(num);
		}
	}
}

/**
*\fn afficher_mains_cachee(void)
*\brief affiche la main de la banque carte cachee incluse
*/
void afficher_mains_cachee(void){
	int num;
	for(num = 0 ; num < 52 ; num++){
		if((cartes[num]==1)||(cartes[num]==3)){
			afficher_carte(num);
		}
	}
}
