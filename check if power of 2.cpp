#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    in count=0;
    cout<<"Enter the number n";
    cin>>n;
    while(n>1)
    {
        if(n&1==1)
        {
            count++;
             
        }
        n=n>>1;
    }
    return 0;
}