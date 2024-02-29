//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *slow=head,*fast=head;
        int count=0;
        if(head->next==NULL) return true;
        if(head->next->next==NULL)
        {
            fast=slow->next;
            if(fast->data==slow->data) return true;
            return false;
        }
        while(fast->next!=NULL)
        {
            count++;
            slow=slow->next;
            
            if(fast->next->next==NULL)
            {
                //count++;
                fast=fast->next;
                break;
            }
            fast=fast->next->next;
        }
        //slow=slow->next;
        Node *prev=slow,*cur=slow,*nex=slow->next;
        int c=0;
        while(nex!=NULL)
        {
            cur=nex;
            nex=cur->next;
            cur->next=prev;
            // if(c==0) 
            // {
            //     c++;
            //     prev->next==NULL;
            // }
            prev=cur;
        }
        slow=head;
        for(int i=1;i<=count;i++)
        {
            if(slow->data!=cur->data) return false;
            slow=slow->next;
            cur=cur->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends