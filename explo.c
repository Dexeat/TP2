#include <stdio.h>
#include <string.h>

struct Lieux
{
    char nom[50];
    char desc[50];
    int diff;
    int link[5];
};

typedef struct Lieux lieux;

int deplacement(int pos,lieux liste[]){
    int posD;
    char choix[50];
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
    
    lieux Route_de_depart = {"Route_de_depart","Le lieux ou vous debutez",0,{1,2}};
    lieux VillageA = {"VillageA","Premier village que vous croisez!",1,{0,2,3}};
    lieux VillageB = {"VillageB","Un peu plus grand que le VillageA",1,{0,1,3}};

    lieux liste_lieux[3] = {Route_de_depart,VillageA,VillageB};

    int pos = 0;

    while (1)
    {
        pos = deplacement(pos,liste_lieux);
    }
    

    return 0;
}