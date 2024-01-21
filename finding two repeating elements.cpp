//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    void insertion(vector<int>& hash,int num,vector<int>& ans,int& check)
    {
        if(hash[num-1]==0)
        {
            
            hash[num-1]++;
        }
        else
        {
            check++;
            ans.push_back(num);
        }
    }
    vector<int> twoRepeated (int arr[], int N) {
        vector<int> hash(N,0),ans;
        int check=0;
        for(int i=0;i<N+2;i++)
        {
            insertion(hash,arr[i],ans,check);
            if(check==2) return ans;
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends