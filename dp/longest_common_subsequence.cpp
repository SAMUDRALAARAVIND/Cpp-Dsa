#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
     int n = a.length(), m = b.length();
     vector<vector<int>> dp(n, vector<int>(m, 0));
     dp[0][0] = (a[0] == b[0])?1:0;
     for(int i=1;i<m;i++){
        dp[0][i] = (a[0] == b[0]  || dp[0][i-1] == 1)?1:0 ;
     }
     for(int i=1;i<n;i++){
        dp[i][0] = (a[i] == b[0] || dp[i-1][0] == 1)?1:0;
     }
     for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = (a[i] == b[j])?dp[i-1][j-1]+1:max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
     cout<<dp[n-1][m-1]<<endl;
}
