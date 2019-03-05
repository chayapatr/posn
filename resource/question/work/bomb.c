/*
TASK: bomb
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>

struct cord {
    int x,y,real;
}bomb[1000000];

main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d",&bomb[i].x,&bomb[i].y);
    for(i=0;i<n-1;i++)
    {
        while(bomb[i].real==1337) i++;
        if(i==n) break;
        for(j=0;j<n;j++)
        {
            while(bomb[j].real==1337 || i==j) j++;
            if(j==n) break;
            if(bomb[i].x>bomb[j].x && bomb[i].y>bomb[j].y)
                bomb[j].real=1337;
        }
    }
    for(i=0;i<n;i++)
    {
        while(bomb[i].real==1337) i++;
        if(i==n) break;
        printf("%d %d\n",bomb[i].x,bomb[i].y);
    }
}
