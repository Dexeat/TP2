#include <stdio.h>
#include <string.h>

struct Lieux
{
    char nom[50];
    char desc[50];
    int diff;
    int num;
    int link[3];
};

typedef struct Lieux lieux;


int deplacement(int pos,lieux liste[]){
    int posD;
    char choix[50];

    printf("Liste des lieux Accecible: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%s ",liste[liste[pos].link[i]].nom /**/);
    }

    printf("\n");
    printf("Choisisez votre lieux:\n"); 
    scanf("%s",&choix);

    for (int i = 0; i < 3; i++)
    {
        if(strcmp(choix,liste[i].nom)==0){
            posD = i;
            break;
        }
    }
    

    printf("Vous vous deplacez de %s a %s\n\n",liste[pos].nom,liste[posD].nom);

    return(posD);
}



int main(){
    
    lieux Route_de_depart = {"Route_de_depart","Le lieux ou vous debutez",0,0,{0,1,2}};
    lieux VillageA = {"VillageA","Premier village que vous croisez!",1,1,{0,1,2}};
    lieux VillageB = {"VillageB","Un peu plus grand que le VillageA",1,2,{0,1,2}};

    lieux liste_lieux[3] = {Route_de_depart,VillageA,VillageB};

    int pos = 0;

    while (1)
    {
        pos = deplacement(pos,liste_lieux);
    }
    

    return 0;
}