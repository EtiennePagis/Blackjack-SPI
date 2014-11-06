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

short donner_valeur_carte(short joueur,short carte){
	if (carte%13 == 0){
		if (joueur == 2){
			nb_as_joueur++;
		}else{
			nb_as_banque++;
		}
		return(11);
	}
	switch(carte%13){
		case 1: return(2);
		case 2: return(3);
		case 3: return(4);
		case 4: return(5);
		case 5: return(6);
		case 6: return(7);
		case 7: return(8);
		case 8: return(9);
		default : return(10);
	}
}

/**
*\fn evaluer_score(short joueur,short carte_recue,short *score)
*\brief met a jour le score en fonction de la carte recus
*/
short evaluer_score(short joueur,short carte_recue,short *score){
}
