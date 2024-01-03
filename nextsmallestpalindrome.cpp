//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int numofdigits(int val)
    {
        int digits=0;
        while(val!=0)
        {
            digits++;
            val/=10;
        }
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    vector<int> output;
	    int mid=(n-1)/2;
	    int right=mid+1,left;
	    if(n%2!=0)
	    {
	        left=mid-1;
	       
	            
	        }
	        if(n%2==0)
	          left=mid;
	           if(num[right]<num[left])
	        {
	            while(left>=0)
	            {
	                num[right]=num[left];
	                right++;
	                left--;
	            }
	        }
	    
	        else
	        {
	            if(num[mid]!=9)
	            {
    	            num[mid]++;
    	            while(left>=0)
    	            {
    	                num[right]=num[left];
    	                right++;
    	                left--;
    	            }
	            }
	            else
	            {
    	                int half=0;
    	            for(int i=0;i<+mid;i++)
    	            half=10*half+num[i];
    	            int dhalf=numofdigits(half);
    	            if(numofdigits(half+1)==numofdigits(half))
    	            {
    	                num[mid]=0;
    	                num[mid-1]++;
    	                while(left>=0)
        	            {
        	                num[right]=num[left];
        	                right++;
        	                left--;
        	            }
    	            
    	            }
    	            else
    	            {
    	               // vector<int> output;
    	               for(int i=0;i<=n;i++)
    	               {
    	                   if(i==0||i==n)
    	                   output.push_back(1);
    	                   else output.push_back(0);
    	               }
    	               return output;
    	            }
    	        }
    	        for(int i=0;i<n;i++)
    	        output.push_back(num[i]);
    	        return output;
	    } 
}
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends