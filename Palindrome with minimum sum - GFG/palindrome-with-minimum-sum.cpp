//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPalindrom(string &str){
        int i=0,j=str.size()-1;
        while(i <= j){
            if((str[i] == '?' && str[j] == '?') || (str[i] == str[j])){
                i++;j--;
            }
            else if(str[i] == '?'){
                str[i] = str[j];
                i++;j--;
            }
            else if(str[j] == '?'){
                str[j] = str[i];
                i++;j--;
            }
            else return 1;   
        }
        return 0;
    }
    
    int minimumSum(string str) {
        if(isPalindrom(str))
            return -1;
            
        int ans = 0;
        for(int i=1;i<(str.size()+1)/2;i++){
            if(str[i-1] == '?')
                continue;
            else if(str[i] == '?')
                str[i] = str[i-1];
            else
                ans +=  abs(str[i]-str[i-1]);
        }
        return 2*ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends