#include <stdio.h>
#include <stdlib.h>
#include "../Liste_aide_Tableau/Tableau_liste.h"
#define MAX 5
//algo aide tableau


int Echange_Ind_ij(Ma_table *table, int ind1, int ind2){
    if(table->Nb_Elem == 0){
        printf("\nLa table est vide\n");
        return ((int)-1);
    }
    if(!(0 <= ind1 && ind1 < table->Nb_Elem) || 
       !(0 <= ind2 && ind2 < table->Nb_Elem))
    {
        printf("\nles indices ne sont pas bien saisie\n");
        return ((int)-1);
    }
    int aux;
    aux = table->Tab[ind1];
    table->Tab[ind1] = table->Tab[ind2];
    table->Tab[ind2] = aux;

    return ((int)1);
}



int TrierBulle(Ma_table *tableau){
    int i, j;
    for(i = 0; i < tableau->Nb_Elem - 2; i++)
        for(j = tableau->Nb_Elem - 1; j >= i; j--)
            if(tableau->Tab[j] < tableau->Tab[j-1])
                Echange_Ind_ij(tableau, j, j-1);

    return ((int)1);
}

int TrierBulleAmeliore(Ma_table *tableau){
    int On_arrete = 0;
    int i = 0;
    int j = 0;
    while ((i != tableau->Nb_Elem - 1) && !On_arrete)
    {
        On_arrete = 1;
        for (j = tableau->Nb_Elem - 1; j >= i; j--)
            if(tableau->Tab[j] < tableau->Tab[j-1])
            {
                Echange_Ind_ij(tableau, j, j-1);
                On_arrete = 0;
            } 
        i++;
    } 

    return ((int)1);
}

int main(int argc, char const *argv[])
{
    Ma_table *tableau;
    tableau = (Ma_table *)malloc(sizeof(Ma_table));

    int TAB[MAX] = {'I','L','I','S','I'};
    init_liste(tableau);
    int i;

    for(i=0; i < MAX; i++){
        tableau->Tab[i] = TAB[i];
        tableau->Nb_Elem ++;
    }

    
    Afficher_liste(*tableau);
    TrierBulleAmeliore(tableau);

    printf("\n");
    Afficher_liste(*tableau);

    return 0;
}

