//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int search(int in[], int s, int e, int key) {
        for(int i = s; i <= e; i++)
            if(in[i] == key)
                return i;
        
        return -1;
    }
    int idx = 0;
    Node* build(int in[], int pre[], int s, int e) {
        if(s > e)
            return NULL;
        
        int curr = pre[idx++];
        Node* node = new Node(curr);
        if(s == e)
            return  node;
        int pos = search(in, s, e, node->data);
        
        node->left = build(in, pre, s, pos - 1);
        node->right = build(in, pre, pos + 1, e);
        
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        return build(in, pre, 0, n - 1);
        
        // Code here
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends