/*
TASK: jail
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>

main()
{
    int n,m,sent=0,i=0,j;
    scanf("%d %d",&n,&m);
    int psr[n];
    memset(psr, 0, sizeof(psr));
    while(sent!=n)
    {
        for(j=0;j<m-1;j++)
        {
            while(psr[i]==1)
            {
                i++;
                if(i>=n) i=i-n;
            }
            i++;
            if(i==n) i=0;
            while(psr[i]==1)
            {
                i++;
                if(i>=n) i=i-n;
            }
        }
        psr[i]++;
        sent++;
        printf("%d ",i+1);
    }
}
