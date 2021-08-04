#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n  =  s.length();
    vector<vector<bool>> dp(n , vector<bool>(n, false));
    for(int i=0;i<n;i++)
        dp[i][i] = true ;
    int max = 1, x = 0, y = 0;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                dp[i][j] = (j-i == 1)?true:dp[i+1][j-1];
            }
            else dp[i][j] = false;
            if(dp[i][j] == true && max < j-i+1){
                max = j-i+1;
                x= i;y = j;
            }
        }
    }
    cout<<s.substr(x, y-x+1);
    return 0 ;
}
