
#include "Tableau_pointeur.c"

int Existe_liste(Node *liste);
int TTaille_liste(Node *liste);
Node* Creer_Cellule(int valeur);
Node *Insertion_tete(Node *liste, int val);
Node* Insertion_fin(Node* liste, int val);
Node* Insertion_pos(Node *liste, int pos, int val);
int pos_elem(Node* liste, int val);
void Affichage_liste(Node *liste);
Node* Suppr_element_pos(Node* liste, int pos);