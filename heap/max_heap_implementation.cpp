#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>& arr, int node){
    arr.push_back(node);
    int index = arr.size()-1;
    while(index > 1){
        if(arr[index/2] < arr[index]){
             int temp = arr[index];
             arr[index] = arr[index/2];
             arr[index/2] = temp ;
             index = index/2;
        }
        else break;
    }
}
void swap(vector<int>& arr, int i, int j){
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp ;
}
int top(vector<int>& arr){
    if(arr.size() <= 1) return -1;
    int ans = arr[1] ;
    arr[1] = arr[arr.size()-1];
    arr.pop_back();
    int index = 1;
    while(index < arr.size()){
        if(2*index >= arr.size()) return ans ;
        if(2*index+1 >= arr.size()){
            if(arr[index] < arr[2*index]){
              swap(arr, index,2*index);
              index = 2*index+1;
            }
            else return ans ;
        }
        else if(arr[index] >= arr[2*index] && arr[index] >= arr[2*index+1])
            break;
        else if(arr[index] >= arr[2*index+1] && arr[index] < arr[2*index+1]){
            swap(arr, index,2*index+1);
            index = 2*index+1;
        }
        else if(arr[index] < arr[2*index] && arr[index] >= arr[2*index]){
            swap(arr, index, 2*index);
            index = 2*index ;
        }
        else{
            if(arr[2*index] > arr[2*index+1]){
                swap(arr, index,2*index);
                index = 2*index;
            }
            else {
                swap(arr, index,2*index+1);
                index = 2*index+1;
            }
        }
    }
    return ans ;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr; 
    arr.push_back(-1);
    for(int i=0;i<n;i++){
        int node;
        cin>>node; 
        insert(arr, node);
    }
    while(true){
       int ans = top(arr);
       if(ans == -1){
           cout<<ans<<"  ";
           break;
       }
       cout<<ans<<"  ";
    }
    return 0;
}
