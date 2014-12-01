//// Fichier projet_test
//// Created by Pagis Etienne, Fouquet Stevy and Grudé Victorien
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
//#include "CUnit/Automated.h"
//#include "CUnit/Console.h"
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




int main(){
	int numj,numb,numbc,score;
	
	CU_ASSERT_TRUE(tirer_carte(JOUEUR)) ;
	CU_ASSERT_TRUE(tirer_carte(BANQUE)) ;
	CU_ASSERT_TRUE(tirer_carte(BANQUE_CACHEE)) ;
	CU_ASSERT((tirer_carte(JOUEUR) >= DEB_COEURS)&&(tirer_carte(JOUEUR) <= FIN_TREFLES);
	CU_ASSERT((tirer_carte(BANQUE) >= DEB_COEURS)&&(tirer_carte(BANQUE) <= FIN_TREFLES);
	CU_ASSERT((tirer_carte(BANQUE_CACHEE) >= DEB_COEURS)&&(tirer_carte(BANQUE_CACHEE) <= FIN_TREFLES);
	
	numj = tirer_carte(JOUEUR);
	numb = tirer_carte(BANQUE);
	numbc = tirer_carte(BANQUE_CACHEE);
	
 	CU_ASSERT_TRUE(donner_valeur_carte(JOUEUR,numj)) ;
	CU_ASSERT_TRUE(donner_valeur_carte(BANQUE,numb)) ;
	CU_ASSERT_TRUE(donner_valeur_carte(BANQUE_CACHEE,numbc)) ;
	CU_ASSERT((donner_valeur_carte(JOUEUR,numj) >= DEB_COEURS)&&(donner_valeur_carte(JOUEUR,numj) <= FIN_TREFLES);
	CU_ASSERT((donner_valeur_carte(BANQUE,numb) >= DEB_COEURS)&&(donner_valeur_carte(BANQUE,numb) <= FIN_TREFLES);
	CU_ASSERT((donner_valeur_carte(BANQUE_CACHEE,numbc) >= DEB_COEURS)&&(donner_valeur_carte(BANQUE_CACHEE,numbc) <= FIN_TREFLES);

	score = 0;
	
	CU_ASSERT_TRUE(evaluer_score(JOUEUR,numj,score));
	CU_ASSERT_TRUE(evaluer_score(BANQUE,numb,score));
	CU_ASSERT_TRUE(evaluer_score(BANQUE_CACHEE,numbc,score));

	CU_PASS(Le test a reussi) ;
	CU_FAIL(Le test a rater) ;
}
