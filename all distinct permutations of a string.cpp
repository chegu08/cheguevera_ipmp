//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void findallper(string &s, int ind, vector<string> &ans)
    {
        if (ind == s.size())
        {
            ans.push_back(s);
            return;
        }
        unordered_set<char> hashset;
        for (int i = ind; i < s.size(); i++)
        {
            if (hashset.find(s[i]) == hashset.end()) {
                hashset.insert(s[i]);
                swap(s[i], s[ind]);
                findallper(s, ind + 1, ans);
                swap(s[i], s[ind]);
            }
        }
    }
		vector<string> find_permutation(string S)
		{
		    vector<string> ans;
		    
		    findallper(S,0,ans);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends