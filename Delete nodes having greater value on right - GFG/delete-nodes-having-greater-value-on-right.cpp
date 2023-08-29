//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
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
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        head = prev;
        return head;
    }
    Node *compute(Node *head) {
        Node* head1 = reverse(head);
        Node* ptr = head1;
        Node* ptr2 = head1->next;
        int val = ptr->data;
        
        while(ptr->next != NULL) {
            if(ptr2->data < val) {
                ptr->next = ptr2->next;
                ptr2 = ptr2->next;
            }
            else {
                val = ptr2->data;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }
        
        return reverse(head1);
        // your code goes here
    }
    
};

// 3->6->5->11->10->15->12
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends