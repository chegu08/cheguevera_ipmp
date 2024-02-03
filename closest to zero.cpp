//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void merge(int arr[],int left,int mid,int right)
        {
           // int *leftarr=new int[left-mid+1],*rightarr=new int[right-mid];
            int lindex=left,rindex=mid+1;
            int *newarr=new int[right-left+1];
            int newindex=0;
            while(lindex<=mid&&rindex<=right)
            {
                if(arr[lindex]<arr[rindex]) newarr[newindex++]=arr[lindex++];
                else if(arr[rindex]<arr[lindex]) newarr[newindex++]=arr[rindex++];
                else 
                {
                    newarr[newindex++]=arr[lindex++];
                    newarr[newindex++]=arr[rindex++];
                }
                
            }
            if(rindex>right)
            {
                while(lindex<=mid) newarr[newindex++]=arr[lindex++];
            }
            else if(lindex>mid)
                while(rindex<=right) newarr[newindex++]==arr[rindex++];
            for(int i=0;i<=right-left;i++)
            {
                arr[i+left]=newarr[i];
            }
            delete[] newarr;
        }
        void mergesort(int arr[],int left,int right)
        {
            if(left<right)
            {
                int mid=(left+right)/2;
                mergesort(arr,left,mid);
                mergesort(arr,mid+1,right);
                merge(arr,left,mid,right);
            }
        }
        int closestToZero(int arr[], int n)
        {
             mergesort(arr,0,n-1);
             int ans=10000000;
             
             for(int i=0;i<n;i++)
             {
                 int closestfori;
                 int left=i+1,right=n-1;
                 int mid=(left+right)/2;
                 while(left<=right)
                 {
                     if(arr[mid]==-arr[i]) return 0;
                     else if(left==right)
                     {
                         closestfori=arr[mid];
                         break;
                     }
                     else if(arr[mid]<-arr[i]) right=mid-1;
                     else if(arr[mid]>-arr[i]) left=mid+1;
                 }
                 if(closestfori+arr[i]<ans) ans=closestfori+arr[i];
             }
             return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends