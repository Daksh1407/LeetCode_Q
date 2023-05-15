//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long res = 0;
        long long one = 0,l_bit = (long long)log2(N);
        for(int i = l_bit; i >= 0; i--) {
            if(N & (1 << i)) {
                res += i * ((long long)pow(2, i - 1));
                res += pow(2, i) * one;
                one++;
            }
        }
        return res + one;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends