//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int subwithk(string s,int k)
    {
        int arr[26]={0};
        long long int count=0;
        int distinct=0;
        int i,left=0;
        for(i=0;i<s.length();i++)
        {
            if(arr[s[i]-'a'] == 0)
                distinct++;
            arr[s[i]-'a']++;
            while(distinct>k)
            {
                arr[s[left]-'a']--;
                if(arr[s[left]-'a'] == 0)
                    distinct--;
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    long long int substrCount (string s, int k) {
        //code here.
        return subwithk(s,k) - subwithk(s,k-1);
    }


};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends