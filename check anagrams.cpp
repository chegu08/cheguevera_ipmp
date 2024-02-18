//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
       if(a.size()!=b.size())return false;
       unordered_map<char,int> s1,s2;
       for(int i=0;i<a.size();i++)
       {
           if(s1.find(a[i])==s1.end()) s1[a[i]]=1;
           else s1[a[i]]++;
           if(s2.find(b[i])==s2.end()) s2[b[i]]=1;
           else s2[b[i]]++;
       }
        for(auto i=s1.begin();i!=s1.end();i++)
        {
            if(s2.find(i->first)==s2.end()) return false;
            auto it=s2.find(i->first);
            if(i->second!=it->second) return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends