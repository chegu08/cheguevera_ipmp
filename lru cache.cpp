//logically correct but time limit reached
//optimize further
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    vector<int> priority;
    unordered_map<int,pair<int,int>> LRU_map;
    int size;
    LRUCache(int cap)
    {
        size=cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(LRU_map.find(key)==LRU_map.end()) return -1;
        for(int i=LRU_map[key].second;i<priority.size()-1;i++)
       {
           priority[i]=priority[i+1];
           LRU_map[priority[i]].second=i;
       }
        priority[priority.size()-1]=key;
        LRU_map[key].second=priority.size()-1;
        return LRU_map[key].first;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
           if(LRU_map.find(key)==LRU_map.end())
           {
               
               if(LRU_map.size()==size)
               {
                   int temp=priority[0];
                   for(int i=LRU_map[temp].second;i<priority.size()-1;i++)
                   {
                       priority[i]=priority[i+1];
                       LRU_map[priority[i]].second=i;
                   }
                   LRU_map.erase(temp);
                   priority.pop_back();
               }
               LRU_map[key].first=value;
               priority.push_back(key);
               LRU_map[key].second=priority.size()-1;
           }
           else
           {
               LRU_map[key].first=value;
               for(int i=LRU_map[key].second;i<priority.size()-1;i++)
               {
                   priority[i]=priority[i+1];
                   LRU_map[priority[i]].second=i;
               }
                    
                priority[priority.size()-1]=key;    
                LRU_map[key].second=priority.size()-1;
               
           }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends