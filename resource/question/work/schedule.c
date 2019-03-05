/*
TASK: schedule
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>

int n,k,m;

struct call
{
    int s, f, checked;
    char get;
}c[500000];

void BubbleSort(int num)
{
    int i,j,temps,tempf,tempc;
    for(i=0;i<num-1;++i)
    {
        for(j=0;j<num-1-i;++j)
        {
            if(c[j].s>c[j+1].s)
            {
                temps=c[j+1].s;
                tempf=c[j+1].f;
                tempc=c[j+1].checked;
                c[j+1].s=c[j].s;
                c[j+1].f=c[j].f;
                c[j+1].checked=c[j].checked;
                c[j].s=temps;
                c[j].f=tempf;
                c[j].checked=tempc;
            }
        }
    }
}

main()
{
    scanf("%d %d %d",&n,&k,&m);
    int i,j,check,opr[k],run=1;
    memset(opr,0,sizeof(opr));
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&c[i].s,&c[i].f);
        c[i].checked=0;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&check);
        c[check-1].checked=i;
    }
    BubbleSort(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            c[i].get='N';
            if(opr[j]<c[i].s)
            {
                opr[j]=c[i].f;
                c[i].get='Y';
                break;
            }
        }
    }
    do
    {
        for(i=0;i<n;i++)
            if(c[i].checked==run)
            {
                printf("%c ",c[i].get);
                break;
            }
        run++;
    }while(run!=m+1);
}
