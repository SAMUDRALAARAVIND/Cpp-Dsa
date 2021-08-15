#include<bits/stdc++.h>
using namespace std;
class ListNode{
   public:
      int data;
      ListNode* next;
      ListNode(int key){
            this->data = key;
            this->next = NULL;
      }

};
class hashSet {
  public:
      int n;
      vector<ListNode*> arr;
      hashSet(int size){      
            this->n = size ;
            for(int i=0;i<this->n;i++){
                 this->arr.push_back(NULL);
            }
      }
      void insert(int key){
            int pos = key%this->n ;
            ListNode* node = new ListNode(key);
            node->next = this->arr[pos];
            this->arr[pos] = node ;
      }
      bool search(int key){
            int pos = key%n;
            ListNode* head = this->arr[pos];
            while(head!=NULL){
                  if(head->data == key) return true;
                  head = head->next;
            }
            return false;
      }
      bool remove(int key){
            if(!this->search(key)) return false;
            int pos = key%this->n ;
            ListNode* head = this->arr[pos];
            if(head->data == key){
                  this->arr[pos] = head->next ;
                  return true;
            }
            while(head->next != NULL) {
                  if(head->next->data == key){
                        head->next = head->next->next ;
                        return true;
                  }
                  head = head->next;
            }
            return false;
      }

};
int main(){
      int n;
      cin>>n;
      hashSet* s = new hashSet(n);
      int k;
      cin>>k;
      while(k--){
            int type ;
            cin>>type;
            if(type == 1){
                  int key ;
                  cin>>key ;
                  s->insert(key);
                  cout<<key<<"Inserted"<<endl;
            }
            else if(type == 2){
                  int key;
                  cin>>key ;
                  if(s->search(key)){
                        cout<<key<<"  found in the set"<<endl;
                  }
                  else cout<<key<<" NOt found in the set"<<endl;
            }
            else{
                  int key ;
                  cin>>key ;
                  if(s->remove(key)){
                        cout<<key<<" deleted successfully"<<endl;
                  }else{
                        cout<<key<<" Not found can't be removed"<<endl;
                  }
            }
      }
      return 0 ;
}
