//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int row=0,col=0;
        int dir=1,count=0;
        //Right:1 down:2 Left:3 Up:4
        int visited[r][c];
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) visited[i][j]=0;
        while(count<r*c)
        {
            visited[row][col]=1;
                        ans.push_back(matrix[row][col]);
                        count++;
                switch(dir)
                {
                    case 1:
                    {
                        
                        if(col==c-1||visited[row][col+1]==1)
                        {
                            dir=(dir+1)%4;
                            row++;
                            
                        }
                         else col++;
                        break;
                    }
                    case 2:
                    {
                        if(row==r-1||visited[row+1][col]==1)
                        {
                            dir=(dir+1)%4;
                            col--;
                        }
                        else row++;
                        break;
                    }
                    case 3:
                    {
                        if(row==0||visited[row][col-1]==1)
                        {
                            dir=(dir+1)%4;
                            row--;
                        }
                        else col--;
                        break;
                    }
                    case 4:
                    {
                        if(visited[row-1][col]==1)
                        {
                            dir=(dir+1)%4;
                            col++;
                        }
                        else row--;
                        break;
                    }
                }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends