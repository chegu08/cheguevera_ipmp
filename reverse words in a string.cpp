//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverse(string &s,int left,int right)
    {
        while(left<=right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string S) 
    { 
        reverse(S,0,S.size()-1); 
        int left=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='.')
            {
                reverse(S,left,i-1);
                left=i+1;
            }
        }
        if(S[S.size()-1]!='.')
        reverse(S,left,S.size()-1);
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends