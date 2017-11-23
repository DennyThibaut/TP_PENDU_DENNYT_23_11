#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 10
void RemplirMot(char MotCherche[]);
void InitMotATrouver(char MotCherche[],char MotTrouve[]);
void LetreCherchee(char MotCherche[],char Lettre,char MotTrouve[],int vie);
void CondiFin(int vie);

// Fonction demandant le mot cherché
void RemplirMot(char MotCherche[]){
    do{
        printf("Entrer votre mot: ");
        scanf("%s",MotCherche);
    }
    while (strlen(MotCherche) > TAILLE);
}
// Fonction cachant le mot cherché en remplissant de tiret un tableau de même longueur
void InitMotATrouver(char MotCherche[],char MotTrouve[]){
    int i;
    for(i=0;i<strlen(MotCherche);i++)
        MotTrouve[i] = '-';
        MotTrouve[i]='\0';
}
// Demande la lettre cherchée
void LetreCherchee(char MotCherche[],char Lettre,char MotTrouve[],int vie){
    int estPareil=0,aTrouverUneLettre;
    int cpt=0;
    Lettre=' ';
    vie=5;
    while(estPareil != 1 && vie != 0){
        fflush(stdin);
        printf("Vous avez %i vie\n",vie);
        printf("Mot a trouver :\n%s\n", MotTrouve);

        printf("Entrer une lettre: ");
        scanf("%c",&Lettre);
        int i=0;
        cpt=0;
        //Boucle vérifiant si la lettre est égale a l'une du mot cherchée
        for(i = 0; i < strlen(MotCherche); i++){
            if(Lettre == MotCherche[i]){
                MotTrouve[i] = Lettre;
                cpt++;
                aTrouverUneLettre = 1;
            }
        }
        //Affiche si la lettre a été trouvée ou non
        if (cpt>0){
        printf("La lettre %c est bien presente !\n", Lettre);
        }
        else{ printf("La lettre %c n\' est pas presente dans le mot\n", Lettre);
        }
        if(aTrouverUneLettre != 1)
            vie -= 1;
        else
            aTrouverUneLettre = 0;

        i = 0;
        // On verifie que chaque lettre du "mot cache" est egale a celle du mot cherché si c'est le cas, on incrémente i
        while(i < strlen(MotCherche) && MotTrouve[i] == MotCherche[i]){
            i++;
        }
        // si i est égal à la taille du mot le joueur a trouve le mot
        if(i == strlen(MotCherche))
            estPareil = 1;
        else
            estPareil = 0;

        }

}
//Si la vie tombe a 0 le joueur a perdu, sinon il  gagne
void CondiFin(int vie){
    if(vie != 0){
        printf("Il est facile ce jeu hein ? Bien joue!\n");
    }
    else{
        printf("Reflechis mieux la prochaine fois \n");
    }
}





int main ()
{
    char MotCherche[TAILLE];
    char MotTrouve[TAILLE];
    char Lettre=' ';
    int vie=5;
    int replay;
    do{
        RemplirMot(MotCherche);
        InitMotATrouver(MotCherche,MotTrouve);
        LetreCherchee(MotCherche,Lettre,MotTrouve,vie);
        CondiFin(vie);
        printf("T'as envie de rejouer ? (1 Oui, 0 Non)");
        scanf("%d",&replay);
        if (replay==0){
        system("cls");
        }
    }
    while (replay != 0);
    system("pause");
    return 0;
}
