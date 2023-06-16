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
    Node* reverse(Node* head) {
        if(!head)
            return NULL;
        Node* curr = NULL;
        Node* prev = NULL;
        while(head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        head = prev;
        return head;
    }
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        bool flag = true;
        Node* h1 = reverse(slow);

        while(head != slow) {
            if(head->data == h1->data) {
                head = head->next;
                h1 = h1->next;
            }
            else {
                flag = false;
                break;
            }
        }
        return flag;
        
        //Your code here
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