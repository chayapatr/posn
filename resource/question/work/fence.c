/*
TASK: fence.c
LANG: C
COMPILER: WCB
AUTHOR: Chirapot Vuthipraphan
ID: Samsen
*/

#include <stdio.h>

int m[2],n[2],l[2],go=0;

void fence(int array[m[go]][n[go]])
{
    int i,j,k,x=m[go],y,yes;
    if (m[go]>n[go]) x=n[go];
    for(k=x;k>=1;k--)
        for(i=0;i<=m[go]-k;i++)
            for(j=0;j<=n[go]-k;j++)
            {
                yes=0;
                for(y=i;y<k+i;y++)
                {
                    if(array[y][j]==1 || array[y][j+k-1]==1) break;
                    yes++;
                }
                if (yes==k)
                {
                    for(y=j;y<k+j;y++)
                    {
                        if(array[i][y]==1 || array[i+k-1][y]==1) break;
                        yes++;
                    }
                    if(yes==2*k)
                    {
                        l[go]=k;
                        go++;
                        return 0;
                    }
                }
            }
    go++;
}

main()
{
    int i,t,r,c;
    scanf("%d %d",&m[0],&n[0]);
    scanf("%d",&t);
    int p0[m[0]][n[0]];
    memset(p0, 0, sizeof p0);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&r,&c);
        p0[r][c]=1;
    }
    fence(p0);
    scanf("%d %d",&m[1],&n[1]);
    scanf("%d",&t);
    int p1[m[1]][n[1]];
    memset(p1, 0, sizeof p1);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&r,&c);
        p1[r][c]=1;
    }
    fence(p1);
    printf("%d\n%d",l[0],l[1]);
}
