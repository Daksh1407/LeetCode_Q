//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        char ch;
        string s;
        for(int i = 0; i < str.length(); i++) {
            s += str[i];
            if(i == 0 and str[i] <= str[i + 1]) 
                break;
            if(i != str.length() - 1 and str[i] < str[i + 1])  
                break;
        }
        for(int i = s.length() - 1; i >= 0; i--) 
            s += s[i];
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends