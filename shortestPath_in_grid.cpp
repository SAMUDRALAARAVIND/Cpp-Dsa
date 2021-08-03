#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int srcX,srcY,destX,destY;
    cin>>srcX>>srcY>>destX>>destY;
    queue<pair<pair<int,int>, int>> q;
    q.push({{srcX, srcY}, 0});
    while(!q.empty()){
        int currX = q.front().first.first, currY  = q.front().first.second, level = q.front().second;
        q.pop();
        if(currX == destX && currY == destY){
            cout<<"found : ans is: "<<level<<endl;
            break ;
        }
        if(currX+1 < n && arr[currX+1][currY] == '*'){
            q.push({{currX+1, currY}, level+1});
        }
        if(currX-1 >=0 && arr[currX-1][currY] == '*'){
            q.push({{currX-1, currY}, level+1});
        }
        if(currY+1 < m && arr[currX][currY+1] == '*'){
            q.push({{currX, currY+1}, level+1});
        }
        if(currY-1 >= 0 && arr[currX][currY-1] == '*'){
            q.push({{currX, currY-1}, level+1});
        }
    }
    if(q.empty() == true){
        cout<<"No path exists"<<endl;
    }
    return 0;
}
