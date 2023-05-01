//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class TrieNode {
public:
    bool isLeaf;
    TrieNode *children[26];

    TrieNode() {
        isLeaf = false;

        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int len = word.length();
        TrieNode* cur = root;
        int index = 0;

        for(int i=0;i<len;i++) {
            index = word[i]-'a';

            if(cur->children[index]==NULL) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isLeaf = true;
    }
    
    bool search(string s) {
        int len = s.size();
        TrieNode* cur = root;
        int index = 0;
        
        for(int i=0;i<len;i++) {
            index = s[i]-'a';
            
            if(cur->children[index]==NULL) return 0;
            cur = cur->children[index];
        }
        return (cur && cur->isLeaf);
    }
};

class Solution{
    private:
    
    bool solve(string a) {
        int n = a.length();
        if(n==0) return true; ////////IMP
        
        for(int i=1;i<=n;i++) {
            if(obj->search(a.substr(0, i))  &&  solve(a.substr(i))) 
                return true;
        }
        return false;
    }
    
    public:
    // A : given string to search
    // B : vector of available strings
    
    Trie* obj = new Trie();
    
    int wordBreak(string a, vector<string> &b) {
        //code here
        
        for(auto it : b) obj->insert(it);
        
        return solve(a);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends