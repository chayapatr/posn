/*
TASK: pair
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>

main()
{
    int i,j,n;
    scanf("%d",&n);
    double a[n],b[n],sum = 0;
    for(i=0;i<n;i++) scanf("%lf %lf",&a[i],&b[i]);
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if((a[i]>a[j] && b[i]<b[j]) || (a[j]>a[i] && b[j]<b[i]))
                sum = sum + a[i] + a[j] ;
    printf("%.0lf",sum);
}
