//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        long long int mid,low=0,high=n-1;
        while(low<=high)
        {
            mid= (high+low)/2;
            if(x<v[low]) return -1;
            else if(x>v[high]) return high;
            else 
            {
                if(x==v[mid]) return mid;
                else if(x<v[mid]) 
                {
                    if(v[mid-1]<=x) return mid-1;
                    else high=mid-1;
                }
                else 
                {
                    if(v[mid+1]>x) return mid;
                    else if(v[mid+1]==x) return mid+1;
                    else low=mid+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends