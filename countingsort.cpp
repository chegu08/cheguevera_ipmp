//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        
        int i=0;
        multiset<char> a;
        while(arr[i]!='\0')
        {
            a.insert(arr[i]);
            i++;
        }
        arr.clear();
        for(auto it=a.begin();it!=a.end();it++)
        {
           arr.push_back(*it); 
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends