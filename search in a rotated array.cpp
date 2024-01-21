//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        if(l<=h)
        {
            if(A[l]>A[h])
            {
                int mid=(l+h)/2;
                if(A[mid]>A[l])
                {
                    int mid=(l+h)/2;
                    if(A[mid]<key)
                    return search(A,mid+1,h,key);
                    else if(A[mid]>key)
                    return search(A,l,mid-1,key);
                    else if(a[mid]==key)
                    return mid;
                    else return -1;
                }
                else if(A[mid]<A[l])
                {
                    if(key>A[mid])
                    {
                        int mid=(l+h)/2;
                        if(A[mid]<key)
                        return search(A,mid+1,h,key);
                        else if(A[mid]>key)
                        return search(A,l,mid-1,key);
                        else if(a[mid]==key)
                        return mid;
                        else return -1;
                    }
                    else
                    {
                        return search(A,l,mid-1,key);
                    }
                }
            }
            else if(A[l]<A[h])
            {
                int mid=(l+h)/2;
                if(A[mid]<key)
                return search(A,mid+1,h,key);
                else if(A[mid]>key)
                return search(A,l,mid-1,key);
                else if(a[mid]==key)
                return mid;
                else return -1;
            }
        }
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends