#include<iostream>
using namespace std;
int main()
{
    int n;
    long int a,sum=0,sum2=0;
    cin>>n;
    //*p=(int*)malloc(n*size of(int));
    for(int i=1;i<=n-1;i++)
    {
        cin>>a;
        sum=sum+a;
    }
    for(int i=1;i<=n;i++)
    {
        sum2=sum2+i;
    }
    int ans=sum2-sum;
    cout<<ans;
    return 0;
}