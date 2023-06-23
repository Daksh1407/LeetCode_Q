//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
void reverse(int i, int j, vector<int>& temp) {
        while(i<j) {
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
    }

    int isSuperSimilar(int n, int m, vector<vector<int>>& mat, int x)
    {
        int r = mat.size(), c= mat[0].size();
        if(x>c) {
            x = x%c;
        }
        
        vector<vector<int> > temp(r, vector<int>(c));
        
        temp = mat;

        for(int i=0; i<r; i++) {
            if(i%2 == 0) {
                vector<int> p = temp[i];
                reverse(0, x-1, p);
                reverse(x, c-1, p);
                reverse(0, c-1, p);
                temp[i] = p;
            }
            else {
                vector<int> p = temp[i];
                reverse(0, c-1, p);
                reverse(x, c-1, p);
                reverse(0, x-1, p);
                temp[i] = p;
            }
        }
        
        if(mat == temp)
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        int x;
        cin >> x;
        
        Solution ob;
        cout<<ob.isSuperSimilar(n,m,mat,x)<<endl;
    }
    return 0;
}
// } Driver Code Ends