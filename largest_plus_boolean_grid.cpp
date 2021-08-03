#include<bits/stdc++.h>
using namespace std;
struct cell {
    int left,right,bottom,top;
};
int main(){
    int n,m;
    cin>>n>>m;
    bool arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cell dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j].left = dp[i][j].right = dp[i][j].bottom = dp[i][j].top = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == false){
                dp[i][j].left = dp[i][j].right = dp[i][j].bottom = dp[i][j].top = 0;
                continue;
            }
            if(i-1 >=0 && arr[i-1][j] == true){
                dp[i][j].top = 1+dp[i-1][j].top;
            }
            if(j-1 >=0 && arr[i][j-1] == true){
                dp[i][j].left = 1+dp[i][j-1].left ;
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(arr[i][j] == false) continue;
            if(i+1 < n && arr[i+1][j] == true){
                dp[i][j].bottom = 1+dp[i+1][j].bottom ;
            }
            if(j+1 < m && arr[i][j+1] == true){
                dp[i][j].right = 1+dp[i][j+1].right ;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           int currMax = min(min(dp[i][j].left, dp[i][j].right), min(dp[i][j].top, dp[i][j].bottom));
           ans = max(1+currMax, ans);
        }
    }
    cout<<ans<<endl;
}
