


// Ajouter un groupe dans la liste
void	listeGroupeAjouter (void* elem);



// Donner le nombre de groupe dans la liste
int	listeGroupeTaille ();



// Verifier si un groupe est dans la liste
int	listeGroupeContient (char* nom);



// Donner la position d'un groupe dans la liste
int	listeGroupePosition (char* nom);



// Retourner le groupe a une certaine position
void*	listeGroupeObtenir (int position);



// Retourne le groupe portant un certain nom
void*	listeGroupeElement (char* nom);



// Enlever un groupe de la liste
void*	listeGroupeEnlever (char *nom);



// Verifier si un usager est responsable d'au moins un groupe
int	listeGroupeEstResponsable (char* nom);



// Verifier si un usager est au moins dans un groupe prive
int	listeGroupeEstMembrePrive (char* nom);



// ToString de la liste des groupes
char*	listeGroupeToString ();
