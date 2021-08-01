#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int startX, startY,endX, endY;
    cin>>startX>>startY>>endX>>endY; 
    queue<pair<pair<int,int>,int>> q;
    q.push({{startX, startY}, 0});
    map<pair<int,int>, bool> hash;
    hash[{startX, startY}] = 1 ;
    while(!q.empty()){
        int i = q.front().first.first , j = q.front().first.second , level = q.front().second  ;
        q.pop();
        if(i == endX && j == endY){
            cout<<"found answer: "<<level<<endl;
            break;
        }
        if(i+1 < n && j+2 < n && hash[{i+1,j+2}] == false) { q.push({{i+1, j+2}, level+1}); hash[{i+1,j+2}] = true ;}
        if(i+1 < n && j-2 >=0 && hash[{i+1, j-2}] == false) {q.push({{i+1, j-2}, level+1}); hash[{i+1, j-2}] = true ;}
        if(i-1 >=0 && j+2 < n && hash[{i-1, j+2}] == false) {q.push({{i-1, j+2}, level+1});  hash[{i-1, j+2}] = true ;}
        if(i-1 >=0 && j-2 >=0 && hash[{i-1 , j-2}] == false) {q.push({{i-1, j-2}, level+1});  hash[{i-1 , j-2}] = true ; }

        if(j+1 < n && i+2 < n && hash[{j+1,i+2}] == false) { q.push({{j+1, i+2}, level+1});  hash[{j+1,i+2}] = true; }
        if(j+1 < n && i-2 >=0 && hash[{j+1, i-2}] == false){ q.push({{j+1, i-2}, level+1}); hash[{j+1, i-2}] = true ;}
        if(j-1 >=0 && i+2 < n && hash[{j-1, i+2}] == false){ q.push({{j-1, i+2}, level+1}); hash[{j-1, i+2}] = true ;}
        if(j-1 >=0 && i-2 >=0 && hash[{j-1 , i-2}] == false) {q.push({{j-1, i-2}, level+1}); hash[{j-1 , i-2}] = true ; }
    }
    if(q.empty() == true){
        cout<<"No path exists"<<endl; 
    }
}
