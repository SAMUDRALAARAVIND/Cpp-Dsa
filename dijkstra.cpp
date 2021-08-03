#include<bits/stdc++.h>
using namespace std;
int getMiniIndex(int* distance, bool* visited, int n){
    int minDistance = INT_MAX;
    int index = -1;
    for(int i=0;i<n;i++){
        if(distance[i] < minDistance && visited[i] == false){
            minDistance = distance[i];
            index = i;
        }
    }
    return index;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> arr[n];
    for(int i=0;i<m;i++){
        int src,dest,w;
        cin>>src>>dest>>w;
        arr[src].push_back({dest, w});
        arr[dest].push_back({src, w});
    }
    bool visited[n];
    int distance[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0 ;
    for(int k=0;k<n-1;k++){
        int currNode = getMiniIndex(distance, visited, n);
        int l = arr[currNode].size();
        for(int i=0;i<l;i++){
            int destination = arr[currNode][i].first;
            int currW = arr[currNode][i].second;
            if(distance[destination] > currW+distance[currNode])
                distance[destination] = currW + distance[currNode];
        }
        visited[currNode] = true ;
    }

    for(int i=0;i<n;i++){
        cout<<distance[i]<<"  ";
    }
    return 0;
}

/*
 Sample input :-
    9 14
    0 1 4
    0 7 8
    1 2 8
    1 7 11
    2 3 7
    2 5 4
    2 8 2
    3 4 9
    3 5 14
    4 5 10
    5 6 2
    6 8 6
    6 7 1
    7 8 7

    Sample Output:-
    0  4  12  19  21  11  9  8  14 
*/
