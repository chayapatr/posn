/*
TASK: goschool.c
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>
#include <math.h>

int count=0,row,col;
int junc[50][50];

void move(int x,int y)
{
    if(x == col-1 && y == 0) count++;
    if(x!=col-1 && junc[y][x+1]!=1) move(x+1,y);
    if(y!=0 && junc[y-1][x]!=1) move(x,y-1);
}

main()
{
    int dog,rodo,codo;
    scanf("%d %d",&col,&row);
    memset(junc, 0, sizeof junc);
    scanf("%d",&dog);
    while(dog!=0)
    {
        scanf("%d %d",&codo,&rodo);
        junc[row-rodo][codo-1]=1;
        dog--;
    }
    if (junc[row-1][0]!=1) move(0,row-1);
    printf("%d",count);
}
