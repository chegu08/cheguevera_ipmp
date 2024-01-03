//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int insertion(int val,int unioncount,unordered_map<int,int>& hash)
    {
        if(hash.empty())
        {
            hash[val]=1;
            unioncount++;
            return unioncount;
        }
        else
        {
            auto it=hash.find(val);
            if(it==hash.end())
            {
                hash[val]=1;
                unioncount++;
                return unioncount;
            }
            return unioncount;
        }
    }
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int,int> hash;
        int unioncount=0;
        for(int i=0;i<n;i++)
        unioncount=insertion(a[i],unioncount,hash);
        for(int i=0;i<m;i++)
        unioncount=insertion(b[i],unioncount,hash);
        return unioncount;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends