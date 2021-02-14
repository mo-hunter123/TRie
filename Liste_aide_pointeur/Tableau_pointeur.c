#include<stdio.h>
#include<stdlib.h>

typedef struct Cel{
    int val;
    struct Cel *next;
}Node;

int Existe_liste(Node *liste){
    if(!liste)
        return ((int)0);
    
    return ((int)1);
}


int TTaille_liste(Node *liste){
    Node *pt;
    int indice = 0;

    if(!Existe_liste(liste))
        return ((int)-1);
    
    pt = liste;
    while (pt)
    {
        indice ++;
        pt = pt->next;
    }
    return ((int)indice);    
}

Node* Creer_Cellule(int valeur){
    Node *NE = NULL;
    NE = (Node* )malloc(sizeof(Node));
    if(!NE){
        printf("\nErreur de l'allocation\n");
        exit(-1);
    }

    NE->val = valeur;
    NE->next = NULL;

    return ((Node*)NE); 
}



Node *Insertion_tete(Node *liste, int val){
    
    Node *NE = Creer_Cellule(val);
    NE->next = liste;
    return ((Node* )NE);

}


Node* Insertion_fin(Node* liste, int val){

    Node *NE = Creer_Cellule(val);

    Node *temp = liste;

    if(liste == NULL)
        return NE;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = NE;

    return ((Node *)liste);
}

Node* Insertion_pos(Node *liste, int pos, int val){
    if(!Existe_liste(liste)){
        printf("\nListe n'existe pas\n");
        exit(-1);
    } 

    Node *NE; 
    int compt = 1;
    Node *p = liste;

    NE = Creer_Cellule(val);

    if(pos < 1 || TTaille_liste(liste) + 1 < pos){
        printf("\n Position est invalide ");
        return ((Node*)liste);
    }

    if(pos == 1){
        NE->next = liste;
        return ((Node*)NE);
    }

    while ((compt != (pos-1)) && p)
    {
        p = p->next;
        compt++;
    }  
    
    if(!p){
        printf("message d'erreur");
        exit(-1);
    }
    else{
        NE->next = p->next;
        p->next = NE;
    }
    return ((Node*)liste);
}


int pos_elem(Node* liste, int val){
    int compt = 1;
    Node *p = liste;
    while (p)
    {
        //si la valeur est trouvee 
        if(val == p->val)
            return ((int)compt);
        
        p = p->next;
        compt ++;
    }
    //si la valeur n'existe pas
    return ((int)-1);
    
}

Node* Suppr_element_pos(Node* liste, int pos){
    if(!Existe_liste(liste)){
        printf("\nListe n'existe pas\n");
        exit(-1);
    } 

    int compt = 1;
    Node *p = liste;
    Node *tmp;

    if(pos < 1 || TTaille_liste(liste) + 1 < pos){
        printf("\n Position est invalide ");
        return ((Node*)liste);
    }

    if(pos == 1){
        tmp = liste;
        liste = liste->next;
        free(tmp);
        return ((Node*)liste);
    }

    while ((compt != (pos-1)) && p)
    {
        p = p->next;
        compt++;
    }  
    
    if(!p){
        printf("message d'erreur");
        exit(-1);
    }
    else{
        tmp = p->next;
        p->next = p->next->next;
        free(tmp);
        return ((Node*)liste);
    }
    return ((Node*)liste);
}

void Affichage_liste(Node *liste){
    if(!liste){
        printf("\npas de liste a affichee");
        return;
    }
    Node *p = liste;
    while (p)
    {
        printf("%d, ", p->val);
        p = p->next;
    }   
}

