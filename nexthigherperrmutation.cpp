#include<bits/stdc++.h>
using namespace std;
int numberofdigits(int val)
{
    int digits=0;
    while(val!=0)
    {
        digits++;
        val/=10;
    }
    return digits;
}
int highpermutation(int val)
{
    int nextP=0;
    int digits=numberofdigits(val),a=val;
    int arrofval[digits];
    for(int i=digits-1;i>=0;i--)
    {
        arrofval[i]=a%10;
        a/=10;
    }
    for(int i=digits-1;i>0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arrofval[i]>arrofval[j])
            {
                swap(arrofval[i],arrofval[j]);
                for(int k=0;k<digits;k++)
                nextP=10*nextP+arrofval[k];
            return nextP;
            }
        }
    }
    return -1;
}
int main()
{
    int input,answer;
    cout<<"Enter the number\n";
    cin>>input;
    answer=highpermutation(input);
    cout<<answer;
    return answer;
}