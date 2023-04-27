//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s){
         int n=p.length();
       int m=s.length();
       bool dp[n+1][m+1];
       
       for(int i = 0; i <= n; i++) {
           for(int j = 0; j <= m; j++) {
               if(i == 0 && j == 0)
                  dp[i][j] = true;
               else if(i == 0) 
                  dp[i][j] = false;
               else if(j == 0) {
                   if(p[i - 1] == '*')
                       dp[i][j] = dp[i - 1][j];
                   else
                       dp[i][j] = 0;
               }
               else if(p[i-1]=='?'||p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
               else if(p[i-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
               else dp[i][j]=0;
           }
       }
       return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends