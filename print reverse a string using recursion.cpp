#include<iostream>
using namespace std;
void reverse(string &a,int ind)
{
    if(in.size()) return;
    reverse(a,ind+1);
    cout<<a[ind];
}
int main()
{
    string a;
    cin>>a;
    reverse(a,0);
    return 0;
}