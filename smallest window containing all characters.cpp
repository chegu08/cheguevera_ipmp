//this code shows time limit exceeded
//optimise it further
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int> hash,check;
        string ans;
        int min=INT_MAX,count=0;
        for(int i=0;i<p.size();i++)
        {
            if(hash.find(p[i])==hash.end()) hash[p[i]]=1;
            else hash[p[i]]++;
        }
        int left=0,right=0;
        while(right<s.size())
        {
            if(hash.find(s[right])==hash.end())
            {
                if(left==right) left++;
                right++;
            }
            else
            {
                if(check.find(s[right])==check.end()) check[s[right]]=1;
                else check[s[right]]++;
                if(check[s[right]]==hash[s[right]]) count++;
                right++;
            }
            if(count==hash.size())
            {
                while(hash.find(s[left])==hash.end()||hash[s[left]]!=check[s[left]])
                {
                    if(check.find(s[left])!=check.end())
                    check[s[left]]--;
                    left++;
                }
                if(right-left+1<min)
                {
                    ans.clear();
                    ans="";
                    for(int i=left;i<right;i++)
                    ans+=s[i];
                    min=right-left+1;
                }
               left=right;
               count=0;
               for(auto it=check.begin();it!=check.end();it++)
               {
                   it->second=0;
               }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends