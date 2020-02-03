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


int deplacement(int pos,lieux liste[],int stamina){
    int posD;
    char choix[50];

    if (stamina <=0)
    {
        printf("vous n'avez plus de stamina,vous etes teleporte a Route_de_depart\n");
        return 0;
    }
    
    printf("Vous avez %d Stamina\n",stamina);
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
    lieux VillageA = {"VillageA","Premier village que vous croisez!",2,1,{0,1,2}};
    lieux VillageB = {"VillageB","Un peu plus grand que le VillageA",3,2,{0,1,2}};

    lieux liste_lieux[3] = {Route_de_depart,VillageA,VillageB};

    
    int pos = 0;
    int stamina = 100;
    int debutL,finL,choixS;

    while (1)
    {
        pos = deplacement(pos,liste_lieux,stamina);
        stamina = stamina - liste_lieux[pos].diff;

        if (liste_lieux[pos].diff<5)
        {
            printf("Vous pouvez vous reposez et restaurez 50 de stamina\n");
            scanf("%s",&choixS);
            printf("\n\n");
            if (choixS == 1)
            {
                printf("Vous vous restaurez 50 de Stamina\n");
                stamina+=50;
                if (stamina>100)
                {
                    stamina = 100;
                }
                
            }
            
        }
        
    }
    

    return 0;
}