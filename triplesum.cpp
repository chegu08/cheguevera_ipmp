//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    
    bool find3Numbers(int A[], int n, int X)
    {
       // bubblesort(A,n);
       for(int i=0;i<n-1;i++)
        {
            int swapcount=0;
            for(int j=0;j<n-i-1;j++)
            {
                if(A[j]>A[j+1])
                {
                    swap(A[j],A[j+1]);
                    swapcount++;
                }
            }
            if(swapcount==0)
            break;
        }
        int left,right;
        for(int i=0;i<n;i++)
        {
            left=i+1;
            right=n-1;
            while(left<right&&left<=n-1)
            {
                int sum=A[left]+A[right]+A[i];
                if(sum<X) left++;
                else if(sum>X) right--;
                else return true;
                
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends                                   