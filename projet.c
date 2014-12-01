#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mains.h"
#include "carte.h"
#include "score.h"

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
*\fn init(short *score_joueur,short* score_banque)
*\brief Initialise les mains du joueur et de la banque
*/
void init(short *score_joueur,short* score_banque){
	int num;
	
	num = tirer_carte(JOUEUR);
	evaluer_score(JOUEUR, num, score_joueur);
	printf("Votre carte a %i points \n",donner_valeur_carte(JOUEUR,num));
	num = tirer_carte(JOUEUR);
	evaluer_score(JOUEUR, num, score_joueur);
    printf("Votre carte a %i points \n",donner_valeur_carte(JOUEUR,num));
    
    printf("Votre score est de %i \n", *score_joueur);
    
	num = tirer_carte(BANQUE);
	evaluer_score(BANQUE, num, score_banque);
    printf("La carte de la banque a %i points \n",donner_valeur_carte(BANQUE,num));
	num = tirer_carte(BANQUE_CACHEE);
	evaluer_score(BANQUE, num, score_banque);
   // printf("La carte a %i points \n",donner_valeur_carte(BANQUE,num));
	printf("Mains du joueur : \n");
	afficher_mains(JOUEUR);
	printf("Mains de la banque : \n");
	afficher_mains(BANQUE);
	
}	


/**
*\fn main(void)
*\brief fonction principale
*/
int main (){
	int num;
	char choix[50]; 
	short score_joueur = 0, score_banque = 0;
	choix[0] = 'y';
	
	init(&score_joueur,&score_banque);
	
	while((choix[0] != 'n')&&(score_joueur < 21 )){
		
		printf("Voulez-vous piocher une carte ? (y/n) : ");
		scanf("%s", choix);
		
		while((choix[0] != 'y') && (choix[0] != 'n')){
				
			printf("\nErreur de saisie.\n Voulez-vous piocher une carte ? (y/n) : ");
			scanf("%s", choix);
		}	
		if( choix[0] == 'y'){ 
	
			num = tirer_carte(JOUEUR);
			printf("Vous avez pioché la carte : ");
			afficher_carte(num);
			evaluer_score(JOUEUR, num, &score_joueur);
			if(score_joueur > 21){
				score_joueur = score_joueur -10*nb_as_joueur;
				nb_as_joueur = 0;
			}
			printf("Votre score est de %i \n", score_joueur);
		}
		if(score_joueur > 21){
			score_joueur = score_joueur -10*nb_as_joueur;
			nb_as_joueur = 0;
		}	
	}
	
	if ( score_joueur == 21 ) {
		printf("You rock WOOHOO !\n");
		return(0); 
	}
	if ( score_joueur > 21 ) { 
		printf("You'll win the next time...\n");
		return(0);
	}
	while(score_banque < score_joueur){
			
		num = tirer_carte(BANQUE);
		evaluer_score(BANQUE, num, &score_banque);
		afficher_carte(num);
		
	}	
	
	if(score_banque > 21){
		printf("Vous avez gagné !\n");
		printf("Le score de la banque était de %i \n",score_banque);
		return(0);
	}else{
		printf("Vous avez perdu.\n");
		printf("Le score de la banque était de %i \n",score_banque);
		return(0);
	}
	
}






