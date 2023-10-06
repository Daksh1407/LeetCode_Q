//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = NULL;
        
        while(head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        head = prev;
        return head;
    }
    
    void rearrange(struct Node *head) {
        if(!head) 
            return ;
        Node* p1 = head;
        Node* p2 = head->next;
        Node* temp = p2;
        while(p1->next && p2->next) {
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(p2)
            p1->next = NULL; // Set the next of the last node to NULL

        Node* ptr = reverse(temp);

        // If the original list has an odd number of nodes, we need to append the middle node back
        if(p2)
            p1->next = ptr;
        else
            p1->next = ptr; // Append the reversed list to the end
        //v->next = ptr;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends