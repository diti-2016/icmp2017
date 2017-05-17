#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* email()
{
 char *ch=(char *) malloc (256*sizeof(char));
  int i=0,l=0,n;
  char *p;
  char *ch2;
  char ema[] = "@mapcom-group.com";


  gets(ch);
  ch = strlwr(ch);
  p=ch;
  while(p[i]!=32)
  {
      i++;

  }
   ch2=(char *) malloc (256*sizeof(char));
   ch2[l] = ch[0];
  i++;
  l++;
  while(p[i]!='\0')
  {
      ch2[l] = p[i];
      i++;
      l++;

  }
  i=0;
  while(ema[i]!='\0')
  {
      ch2[l] = ema[i];
      i++;
      l++;
  }
  ch2[l] = '\0';

  return ch2;

}
main()
{
  char **res ;
  int n,cpt=0,i=0,test;
  do
  {
       printf("Entrer le nombre de noms: ");
        test =scanf("%d",&n);
        fflush(stdin);
  }while(test!=1);

  fflush(stdin);
  res =(char**)malloc(n*sizeof(char*));
  do
  {
       res[i] =email();
       cpt++;
       i++;
  }while(cpt<n);
  puts("\n\n");
  puts("OUTPUT:");

  for(i=0;i<n;i++)
    puts(res[i]);
    return 0;
}
