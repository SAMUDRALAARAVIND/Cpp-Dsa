#include<bits/stdc++.h>
using namespace std;
// struct pair {
//     int first, second ;
// };
void solve(int n, int k, vector<int>& p, vector<int>& a){
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        arr[i].first = p[i];
        arr[i].second = a[i];
    }
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            dp[i][j].first = -1;


    dp[0][0].first = arr[0].first ;
    dp[0][0].second = arr[0].second ;
    for(int i=1;i<n;i++){
        double prevPair = double(dp[i-1][0].first)/double(dp[i-1][0].second);
        double currPair = double(arr[i].first)/double(arr[i].second);
        dp[i][0] = prevPair > currPair ? dp[i-1][0]: arr[i];
        for(int j=1;j<k;j++){
            if(dp[i-1][j-1].first != -1){
                //valid case 
                double exclude = double(dp[i-1][j].first)/double(dp[i-1][j].second);
                double include = double(arr[i].first+dp[i-1][j-1].first)/double(arr[i].second+dp[i-1][j-1].second);
                dp[i][j].first = (include > exclude)?(arr[i].first+dp[i-1][j-1].first):dp[i-1][j].first;
                dp[i][j].second = (include > exclude)?(arr[i].second+dp[i-1][j-1].second):dp[i-1][j].second;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0 ;j<k;j++){
            cout<<dp[i][j].first<<"  "<<dp[i][j].second <<" ---  ";
        }
        cout<<endl;
    }
    cout<<dp[n-1][k-1].first<<" "<<dp[n-1][k-1].second<<endl;
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> p(n), a(n);
    for(int i=0;i<n;i++){
        cin>>p[i]>>a[i];
    }
     solve(n , k, p, a);
}
