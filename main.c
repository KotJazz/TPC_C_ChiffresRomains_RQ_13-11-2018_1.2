#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//SIGNATURES

void choix();
void saisiearabes();
void saisieromains();
void aratorom(int un, int di,int ce,int mi);
void romtoara(char nr[16]);
void affichage(const char *unite,const char *diz,const char *cent,const char *mil);
void affichage2(int res);

//MAIN

int main()
{
    int debut;
    printf("Tapez 1 pour continuer\nTapez n'importe quoi d'autre pour quitter.\n");
    scanf("%d",&debut);
    if (debut==1)
    {
        choix();
    }
    return 0;
}
//CHOIX DE LA CONVERSION

void choix()
{
    int ch;
    do
    {
        printf("Tapez 1 pour convertir des chiffres romains en chiffres arabes\nTapez 2 pour convertir des chiffres arabes en chiffres romains\n");
        scanf("%d",&ch);
        fflush(stdin);
    } while ((ch!=1)&&(ch!=2));
    if (ch==1)
    {
        saisieromains();
    }
    else
    {
        saisiearabes();
    }
}
//SAISIE DES CHIFFRES ROMAINS

void saisieromains()
{
        char nr[16];
        printf("Veuillez saisir un nombre en chiffres romains\n");
        scanf("%s",&nr);
        romtoara(nr);
}
//PROCESSUS DE CONVERSION ROMAIN VERS ARABE

void romtoara(char nr[16])
{
    int i;
    int res=0;
    int lastadd=0;
    int m=strlen(nr);
    //printf("%d\n",res);
    for (i=m-1;i>=0;i--)
    {
        if ((nr[i]=='I')||(nr[i]=='i'))
        {
            //printf("%d\n",res);
            if (lastadd>1)
            {
                res-=1;
            }
            else
            {
                res+=1;
                lastadd=1;
            }
        }
        else if ((nr[i]=='V')||(nr[i]=='v'))
        {
           //printf("%d\n",res);
                res+=5;
                lastadd=5;
        }
        else if ((nr[i]=='X')||(nr[i]=='x'))
        {
            //printf("%d TEN\n",res);
            if ((lastadd==50)||(lastadd==100))
            {
                res-=10;
            }
            else
            {
               res+=10;
                lastadd=10;
            }
        }
        else if ((nr[i]=='L')||(nr[i]=='l'))
        {
            //printf("%d\n",res);
                res+=50;
                lastadd=50;
        }
        else if ((nr[i]=='C')||(nr[i]=='c'))
        {
            //printf("%d\n",res);
            if ((lastadd==500)||(lastadd==1000))
            {
                res-=100;
            }
            else
            {
                res+=100;
                lastadd=100;
            }
        }
        else if ((nr[i]=='D')||(nr[i]=='d'))
        {
            //printf("%d\n",res);
                res+=500;
                lastadd=500;
        }
        else if ((nr[i]=='M')||(nr[i]=='m'))
        {
            //printf("%d\n",res);
                res+=1000;
                lastadd=1000;
        }
    }
    affichage2(res);
}
//SAISIE DE CHIFFRES ARABES

void saisiearabes()
{
    int n;
    //char nbr[3];
    do
    {
        printf("Veuillez saisir un nombre en chiffres arabes\n");
        scanf("%d",&n);
    }while ((n>3999)||(n<0));
    /*tab[0] = nombre / 1000;
    printf("%d",tab[0]);
    tab[1] = (nombre % 1000)/100;
    printf("%d",tab[1]);
    tab[2] = ((nombre % 1000)%100)/10;
    printf("%d",tab[2]);
    tab[3] = (((nombre % 1000)%100)%10)/1;
    printf("%d\n",tab[3]);*/
    int mi=n/1000;
    int ce=(n%1000)/100;
    int di=((n%1000)%100)/10;
    int un=(((n%1000)%100)%10)/1;
    aratorom(un,di,ce,mi);
}
//PROCESSUS DE CONVERSION ARABES VERS ROMAINS

void aratorom(int un, int di,int ce,int mi)
{
    int lg=3;
    const char *unite;
    const char *diz;
    const char *cent;
    const char *mil;
    int cpt;
for (cpt = lg; cpt >= 0; --cpt) {
    if (cpt == lg) {
        switch (un) {
        case 1 :
            unite="I";
            break;
        case 2 :
            unite="II";
            break;
        case 3 :
            unite="III";
            break;
        case 4 :
            unite="IV";
            break;
        case 5 :
            unite="V";
            break;
        case 6 :
            unite="VI";
            break;
        case 7 :
            unite="VII";
            break;
        case 8 :
            unite="VIII";
            break;
        case 9 :
            unite="IX";
            break;
        default:
            unite="";
            break;
        }
    }
    else if (cpt==lg - 1) {
        switch (di) {
        case 1 :
            diz="X";
            break;
        case 2 :
            diz="XX";
            break;
        case 3 :
            diz="XXX";
            break;
        case 4 :
            diz="XL";
            break;
        case 5 :
            diz="L";
            break;
        case 6 :
            diz="LX";
            break;
        case 7 :
            diz="LXX";
            break;
        case 8 :
            diz="LXXX";
            break;
        case 9 :
            diz="XC";
            break;
        default:
            diz="";
            break;
        }
    }
    else if (cpt==lg-2) {
        switch (ce) {
        case 1 :
            cent="C";
            break;
        case 2 :
            cent="CC";
            break;
        case 3 :
            cent="CCC";
            break;
        case 4 :
            cent="CD";
            break;
        case 5 :
            cent="D";
            break;
        case 6 :
            cent="DC";
            break;
        case 7 :
            cent="DCC";
            break;
        case 8 :
            cent="DCCC";
            break;
        case 9 :
            cent="CM";
            break;
        default:
            cent="";
            break;
        }
    }
    else if (cpt==lg - 3) {
        switch (mi) {
        case 1 :
            mil="M";
            break;
        case 2 :
            mil="MM";
            break;
        case 3 :
            mil="MMM";
            break;
        default:
            mil="";
            break;
        }
    }
}
 affichage(unite,diz,cent,mil);
}
//AFFICHAGE ROMAINS

void affichage(const char *unite,const char *diz,const char *cent,const char *mil)
{
        printf("%s%s%s%s\n", mil, cent, diz, unite);
        main();
}
//AFFICHAGE ARABES

void affichage2(int res)
{
    printf("\n%d\n",res);
    main();
}
