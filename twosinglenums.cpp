//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        unordered_multiset<int> s;
        for(int i=0;i<nums.size();i++)
        s.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i])==1)
            ans.push_back(nums[i]);
        }
        if(ans[0]>ans[1])
        {
            swap(ans[0],ans[1]);
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends