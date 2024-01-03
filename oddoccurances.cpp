//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void insertion(unordered_set<long long int>& hash,long long int val)
    {
        if(hash.find(val)==hash.end())
        {
            hash.insert(val);
        }
        else hash.erase(val);
    }
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        unordered_set<long long int > hash;
        vector<long long int> ans;
        
        for(long long int i=0;i<N;i++)
        insertion(hash,Arr[i]);
        // ans.push_back(*hash.begin());
        // ans.push_back(*hash.end());
        for(auto it=hash.begin();it!=hash.end();it++)
        {
            ans.push_back(*it);
        }
        if(ans[0]<ans[1])
        swap(ans[0],ans[1]);
        
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends