#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr[n];
    for(int i=0;i<m;i++){
        int src,dest;
        cin>>src>>dest;
        arr[src].push_back(dest);
        arr[dest].push_back(src);
    }
    queue<pair<int,int>> q;
    vector<int> ans ;
    int k ;
    cin>>k;
    q.push({0, 0});
    vector<bool> v(n, false);
    v[0] = true ;
    while(!q.empty()){
        int currNode = q.front().first, level = q.front().second ;
        q.pop();
        if(level == k) ans.push_back(currNode);
        if(level+1 > k) continue;
        for(int i=0;i<arr[currNode].size();i++){
            if(v[arr[currNode][i]] == false){
                q.push({arr[currNode][i], level+1});
                v[arr[currNode][i]] = true ;
            }
        }
    }
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<"  ";
    }

}
