//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    
	    unordered_map<int,int> s;
	    for(int i=0;i<n;i++)
	    {
	        
	        {
	            if(s.find(arr[i])!=s.end())
	            {
	                s[arr[i]]++;
	            }
	            else
	            {
	                s[arr[i]]=1;
	            }
	        }
	    }
	        
	    for(int i=0;i<n;i++)
	    {
	        if(s.find(x-arr[i])!=s.end())
	        {
	            if(x-arr[i]==arr[i]&&s[arr[i]]!=1)
	            {
	                return true;
	            }
	            else if(x-arr[i]!=arr[i])
	            return true;
	            
	        }
	        
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends