#include<stdio.h>
int main()
{
    int n;
    int a[10000],b[10000];
    scanf("%d",&n);
    int suma=0,sumb=0;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&b[i]);
        sumb=sumb+b[i];
    }
    for(int i=0;i<n;i++)
    {
        suma=suma+i;
    }
    printf("%d",sumb-suma);

    return 0;
}