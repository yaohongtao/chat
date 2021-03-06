/*
Classe:		chaine.c

Description:	Structure objet pour definir une chaine de caracteres et ses attributs

Auteurs:	Alain Sirois     SIRA15068305
		Philippe Mercure MERP27078708
Date:		18 juin 2011
Cours:		yyyyyyyyyy
Groupe:		30
Travail:	TP2
Professeur:	xxxxxxxxxx
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "chaine.h"




struct chaine {
	int taille;
	char* cars;
	int totalAlloc;
};



/*
Creer une chaine vide
*/
Chaine chaineCreerVide( int longueur ){

	Chaine maChaine = (Chaine) malloc (sizeof(struct chaine));
       	if ( maChaine == NULL )
     		return NULL;
     		 
	maChaine->cars = (char*) malloc (longueur * sizeof(unsigned char));
	if ( maChaine->cars == NULL )
		return NULL;

	// Paramétrage de la Chaine
	maChaine->taille = 0;
	maChaine->cars[0] = '\0';
	maChaine->totalAlloc = longueur;
	return maChaine;
}



/*
Ajouter un caractere a la fin d'une chaine
*/
int chaineAjouter( Chaine ch, unsigned char carac ){

	assert (ch != NULL && "ch doit être un pointeur non NULL");
	
	int longueur = chaineLongueur(ch);
	
	/*** Ajout d'un caractère SANS réallocation ***/
	if ( longueur < (ch->totalAlloc - 1) ) {
		ch->cars[longueur] = carac;
		ch->cars[longueur + 1] = '\0';
		ch->taille++;
		return 0;
	}
	
	/*** Ajout d'un caractère AVEC réallocation ***/
	ch->cars = (char*) realloc (ch->cars, ((ch->totalAlloc * sizeof(unsigned char)) + (50 * sizeof(unsigned char))));
	if ( ch->cars == NULL )
		return 1;

	ch->cars[longueur] = carac;
	ch->totalAlloc = ch->totalAlloc + 50;
	ch->cars[longueur + 1] = '\0';
	ch->taille++;
	return 0;
}



/*
Enlever le dernier caractere d'une chaine
*/
int chaineEnlever( Chaine ch ) {

	assert (ch != NULL && "ch doit être un pointeur non NULL");
	
	int longueur = chaineLongueur(ch);

	if ( longueur == 0 )
		return 0;

	ch->cars[longueur-1] = '\0';
	ch->taille--;
	return 0;
}



/*
Retourne la valeur d'une chaine
*/
char* chaineValeur( Chaine ch ){

	assert (ch != NULL && "ch doit être un pointeur non NULL" );
	
	return ch->cars;
}



/*
Retourne la longueur d'une chaine
*/
int chaineLongueur( Chaine ch ){

	assert (ch != NULL && "ch doit être un pointeur non NULL" );
	
	return ch->taille;
}



/*
Supprimer une chaine
*/
void chaineSupprime( Chaine ch ){

	assert (ch != NULL && "ch doit être un pointeur non NULL vers une chaine créé par ChaineCree");
	
	free (ch->cars);
	free (ch);
}
