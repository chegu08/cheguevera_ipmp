//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int *finarr=new int[r-l+1];
         int p1=l,p2=m+1,pf=0;
         while(p1<=m&&p2<=r)
         {
             if(arr[p1]<arr[p2])
             {
                 finarr[pf]=arr[p1];
                 p1++;
                 pf++;
             }
             else if(arr[p2]<arr[p1])
             {
                 finarr[pf]=arr[p2];
                 pf++;
                 p2++;
             }
                
            else if(arr[p1]==arr[p2])
            {
                finarr[pf]=arr[p1];
                finarr[pf+1]=arr[p2];
                p2++;
                p1++;
                pf+=2;
            }
         }
         if(p1>m&&p2<=r)
         {
             while(p2<=r){
                 finarr[pf]=arr[p2];
                 pf++;
                 p2++;
             }
         }
         else if(p2>r&&p1<=m)
            while(p1<=m){
                finarr[pf]=arr[p1];
                p1++;
                pf++;
            }
                
         for(int i=0;i<r-l+1;i++)
         arr[l+i]=finarr[i];
         //delete[] finarr;
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends