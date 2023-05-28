//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void reverse(Node* &head) {
        if(head->next == NULL) return;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        head = prev;
    }
    
    struct Node* modifyTheList(struct Node *head) {
        if(head == NULL || head->next == NULL) return head;
        
        // Getting the middle node and reversing the 2nd half
        Node* mid = getMid(head);
        reverse(mid->next);
        
        Node* tmp = mid->next;
        Node* start = head;
        while(tmp != NULL) {
            // Updating the data
            int x = start->data;
            start->data = tmp->data - x;
            tmp->data = x;
            
            // Updating the pointers
            start = start->next;
            tmp = tmp->next;
        }
        
        reverse(mid->next);
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends