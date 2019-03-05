/*
TASK: SCHOOL
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>
#include <string.h>

int m,n,yes=0,p=0;
char area[65][65];

void clean(int y,int z)
{
    area[y][z]='N';
    if(area[y-1][z]!='P'&&area[y+1][z]!='P'&&area[y][z-1]!='P'&&area[y][z+1]!='P') return 0;
    if(area[y-1][z]=='P'&&y-1>0) clean(y-1,z);
    if(area[y+1][z]=='P'&&y+1<n) clean(y+1,z);
    if(area[y][z-1]=='P'&&z-1>0) clean(y,z-1);
    if(area[y][z+1]=='P'&&z+1<m) clean(y,z+1);
    if(area[n-1][z]=='P'&&y==0) clean(n-1,z);
    if(area[0][z]=='P'&&y==n-1) clean(0,z);
    if(area[y][m-1]=='P'&&z==0) clean(y,m-1);
    if(area[y][0]=='P'&&z==m-1) clean(y,0);
}

void building()
{
    char tmp[65][65];
    int i,j,k,x=m,y,z,u;
    if (m>n) x=n;
    for(u=0;u<n;u++) strcpy(tmp[u], area[u]);
    for(k=x;k>=1;k--)
        for(i=0;i<=n-k;i++)
            for(j=0;j<=m-k;j++)
            {
                for(y=i;y<k+i;y++)
                {
                    if(yes!=k*y) break;
                    for(z=j;z<k+j;z++)
                    {
                        if(area[y][z]=='T') break;
                        if(area[y][z]=='P'&&area[y-1][z]!='N'&&area[y+1][z]!='N'&&area[y][z-1]!='N'&&area[y][z+1]!='N')
                        {
                            p++;
                            clean(y,z);
                        }
                        yes++;
                    }
                }
                if(yes==k*k) return 0;
                yes=0;
                p=0;
                for(u=0;u<n;u++) strcpy(area[u], tmp[u]);
            }
}

main()
{
    int i,r,c;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",area[i]);
    }
    building();
    printf("%d %d",yes,p);
}
