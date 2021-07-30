#include<bits/stdc++.h>
using namespace std;
void buildTree(int* arr, int left, int right , int* tree,int index){
    if(left == right){
        tree[index] = arr[left];
        return ;
    }
    int mid = left+(right - left)/2;
    buildTree(arr, left , mid, tree, 2*index+1);
    buildTree(arr, mid+1, right, tree,2*index+2);
    tree[index] = tree[2*index+1]+tree[2*index+2];
}
int processQuery(int* tree, int l, int r, int left, int right,int index){
    if(l == left && r == right) return tree[index];
    int mid = left+(right - left)/2;
    if(mid >= r){
        return processQuery(tree, l, r, left, mid, 2*index+1);
    }
    if(l > mid){
        return processQuery(tree, l, r, mid+1, right, 2*index+2);
    }
    return processQuery(tree,l,mid,left,mid,2*index+1)+processQuery(tree, mid+1, r, mid+1, right, 2*index+2);
}
void processUpdate(int* tree, int pos, int val,int left, int right,int index){
    int mid = left+(right-left)/2;
    if(left == right){
         tree[index] = val;
         return ;
     }
     if(mid >= pos){
        processUpdate(tree, pos,val, left, mid, 2*index+1);
    }
    else  processUpdate(tree, pos,val , mid+1, right, 2*index+2);

    tree[index] = tree[2*index+1]+tree[2*index+2];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int tree[2*n] ;
   
    for(int i=0;i<2*n;i++)
        tree[i] = -1;
     buildTree(arr,0, n-1,tree,0);
     int q;
     cin>>q;
     for(int i=0;i<2*n;i++)
        cout<<tree[i]<<"  ";
     while(q--){
        int pos, val;
        cin>>pos>>val;
        processUpdate(tree,pos, val, 0,n-1,0);
        for(int i=0;i<2*n;i++)
            cout<<tree[i]<<"  ";
     }

}
