#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upper(char* text){
    int i, n = strlen(text);
    for(i=0;i<n ;i++)
        {
           if(*(text+i) >= 'a' && *(text+i)<='z')
           {
               *(text+i)-= 32;

           }
        }
}

char* saisie()
{

    char *ch = (char*) malloc (10001*sizeof(char));
    gets(ch);
    if(strlen(ch) > 10000)
    {
        puts("Votre ligne depasse 10 000 caracteres. Veuillez resaisir!!");
        return saisie();
    }
    return ch;
}
void upperAuc(char* text,char* auc){
    int i,p=0;
    int n = strlen(text), m= 0;
    char *h=NULL;
    char *ch2 = (char*) malloc((n+1)*sizeof(char));
    strcpy(ch2,text); upper(ch2);upper(auc);
    while(strstr(ch2 + p + m,auc)){
    h=strstr(ch2 + p + m,auc);
    p = h - ch2;
    m= strlen(auc);
    if(h)
    {
       int change =0;
        char valide[]=",.;?!  ";
        valide[6]='\0';
        for(int j = 0; j<7;j++){
               if(( *(text + p -1)==valide[j] || *(text +p+ m)== valide[j]) )
               change = 1;
        }
        for(i=p;i<p+m && change==1;i++)
        {
           if(*(text+i) >= 'a' && *(text+i)<='z')
           {
               *(text+i)-= 32;
           }
        }
    }
    }

    free(ch2);

}
void display(char** enr, int i){

for(int j=0;j<i;j++)
    {
        printf("%s\n",enr[j]);
    }
}
int main()
{
    int reboute =1;
    while(reboute=1){
    char **enr = (char**)malloc(30*sizeof(char*));
    int i=0;
    char pre1[]="eric", pre2[]="blow",nom[]="amagbegon";
    char *ch ;
    do
    {

        ch = saisie();
        enr[i] =(char *) malloc((strlen(ch)+1)*sizeof(char));
        upperAuc(ch,pre1);
       upperAuc(ch,pre2);
       upperAuc(ch,nom);

        strcpy(enr[i],ch);
        i++;


    }while(ch[0]!='#');
    display(enr,i);
       do{

            printf("TAPPER 1 POUR REESER OU 0 POUR QUITTER :");
            scanf("%d",&reboute);

       }while(reboute < 0 || reboute >1);
    }
return 0;
}
