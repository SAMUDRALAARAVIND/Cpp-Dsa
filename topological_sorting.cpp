#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> *arr, int n, vector<bool>& v, stack<int>& s){
    v[node] = true ;// visit the currentNode
    int k = arr[node].size(); // number of nodes connected to currentNode
    for(int i=0;i<k;i++){
        if(v[arr[node][i]] == false){
            dfs(arr[node][i], arr, n, v, s);
        }
    }
  s.push(node);
}
int main(){
    int n;// nodes in the graph numbered fron 0 - n-1
    cin>>n;
    int k ; // number of edges 
    cin>>k;
    vector<int> graph[n];
    while(k--){
        int src, dest;
        cin>>src>>dest;
        graph[src].push_back(dest);
    }
    stack<int> s;// stores topological sorting in reverse order
    vector<bool> v(n, false); // visisted array 
    for(int i=0;i<n;i++){
        if(v[i] == false){
            //explore unvisited node
            dfs(i, graph, n , v, s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<"  ";
        s.pop();
    }

}
/*
    IMP: Topological sorting exists only for Directed Acyclic graph .

*/
