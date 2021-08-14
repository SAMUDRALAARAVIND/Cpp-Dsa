/*
  given an unsorted array of size n and an integer k
  we need to find Kth smallest and largest numbers in that array 
  expected time complexity: nlog(k)  [bruteforce will be sort the entire array which takes nlog(n) complexity]
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
      int n, k ;
      cin>>n>>k;
      int arr[n];
      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      priority_queue<int> q;
      for(int i=0;i<n;i++){
            if(q.size() == k){
                  q.push(arr[i]); q.pop();
                  continue;
            }
            q.push(arr[i]);
      }
      cout<<"Kth smallest number is: "<<q.top()<<endl;
      priority_queue<int, vector<int>, greater<int>> q1;
      for(int i=0;i<n;i++){
            if(q1.size() == k){
                  q1.push(arr[i]);
                  q1.pop();
                  continue;
            }
            q1.push(arr[i]);
      }
      cout<<"Kth largest element is: "<<q1.top()<<endl;
      return 0;
}
