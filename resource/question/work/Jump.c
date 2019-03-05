/*
TASK: Jump
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include<stdio.h>

main()
{
    int stp,jump,i,j,to,count,max=0;
    scanf("%d %d",&stp,&jump);
    int line[stp];
    for(i=0;i<stp;i++) scanf("%d",&line[i]);
    for(i=0;i<stp;i++)
    {
        count=0;
        j=i;
        to=jump+line[i];
        while(to>=line[j+1]&&j+1<stp)
        {
             count++;
             j++;
        }
        if(count>max) max=count;
    }
    printf("%d",max);
}
