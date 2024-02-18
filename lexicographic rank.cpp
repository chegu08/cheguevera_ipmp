/*this code uses mathematical concept of finding
rank rather than finding all permutations;
yet this operates in n squared time,there is an approach 
to find in linear time*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fact(long long n)
    {
        long long ans=1;
        for(long long i=1;i<=n;i++) ans*=i;
        return ans;
    }
    long long findRank(string str) {
        long long rank=1;
        unordered_map<char,int> freq;
        for(int i=0;i<str.size();i++)
        {
            if(freq.find(str[i])==freq.end()) freq[str[i]]=0;
            else freq[str[i]]++;
        }
        for(int i=0;i<str.size();i++)
        {
            int count=0;
            for(int j=i+1;j<str.size();j++)
            {
                if(str[j]<=str[i]) count++;
            }
            rank+=fact(str.size()-1-i)*count;
        }
        for(auto i=freq.begin();i!=freq.end();i++)
        {
            rank/=(fact(i->second));
        }
        return rank;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends