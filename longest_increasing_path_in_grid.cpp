#include<bits/stdc++.h>
using namespace std;
 int n,m;
int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int left = 0,right = 0,bottom = 0, top = 0;
    if(j-1 >=0 && arr[i][j-1] < arr[i][j]){
        dp[i][j-1] = solve(arr, dp, i, j-1);
        left = dp[i][j-1];
    }
    if(j+1 < m && arr[i][j+1] < arr[i][j]){
        dp[i][j+1] =solve(arr, dp, i, j+1);
        right = dp[i][j+1];
    }
    if(i+1 < n && arr[i+1][j] < arr[i][j]){
        dp[i+1][j] = solve(arr, dp, i+1, j);
        bottom = dp[i+1][j] ;
    }
    if(i-1 >=0  && arr[i-1][j] < arr[i][j]){
        dp[i-1][j] = solve(arr,dp,i-1,j);
        top = dp[i-1][j];
    }
    dp[i][j] = 1+max(max(left, right), max(bottom,top));
    return dp[i][j];
}
int main(){
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j] == -1){
                solve(arr, dp, i, j);
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout<<ans<<endl;
}
