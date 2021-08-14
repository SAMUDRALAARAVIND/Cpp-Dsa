/*
  given a string and a number k we need to delete all k length substring with same charecters so that we minimize the length of final string
  Ex: s = qddmmxxxmdm & k = 3
  so as k = 3 we need to delete all three length substrings whose charecters are equal
  intially s = qddmmxxxmdm
  after removing "xxx" s = qddmmmdm
  now remove "mmm" then s = qdddm
  now remove "ddd" then s = qm
  therefore the final answer is "qm" 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
      string s;
      cin>>s;
      int k; cin>>k;
      stack<pair<char, int>> st;
      for(int i=0;i<s.length();i++){
            if(st.empty() == false && st.top().first == s[i]){
                  if(st.top().second == k-1){
                        while(st.empty()!=true && st.top().first == s[i]){
                              st.pop();
                        }
                  }else{
                        st.push({s[i], st.top().second+1});
                  }
            }
            else{
                  st.push({s[i], 1});
            }
      }
      while(st.empty()!=true){
            cout<<st.top().first;
            st.pop();
      }
      return 0;
}
