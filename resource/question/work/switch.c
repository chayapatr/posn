/*
TASK: switch.c
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>
#include <string.h>
char N[5000001],str[5000001];
main()
{
    int i,t=0;
    long long n;
    scanf("%lld",&n);
    char tmp;
    scanf("%s",N);
    strcpy(str,N);
    do{
        tmp=str[0];
        for(i=0;i<n;i++) str[i]=str[i+1];
        str[n-1]=tmp;
        str[n]='\0';
        t++;
    }while(strcmp(str,N)!=0);
    printf("%d",t);
}
