#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of inputs\n";
    cin>>n;
    int arr[n],*dif= new int[n],max=-1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        dif[i]=arr[i+1]-arr[0];
    }
    dif[n]=0;
    for(int i=n-2;i>=0;i--)
    {
        if(!(dif[i]<=0&&dif[i+1]<=0))
        dif[i]=dif[i+1];
        else dif[i]=0;
        if(dif[i]>max) max=dif[i];
    }
    cout<<max;
    return 0;
}
