#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *left, *right ;
    Node(int key){
        this->data = key ;
        this->left = this->right = NULL;
    }
};
bool ans = true ;
int  checkIfBst(Node* root, bool direction){
    if(ans == false) return -1;
    if(root->left == NULL && root->right == NULL) return root->data ;
    if(root->left == NULL){
        int rightMin = checkIfBst(root->right , true);
        if(root->data >= rightMin){
            ans = false;
            return -1;
        }
        return (direction == true)?(min(root->data, rightMin)):max(root->data, rightMin);
    }
    if(root->right == NULL){
        int leftMax = checkIfBst(root->left, false);
        if(root->data < leftMax){
            ans = false;
            return -1;
        }
        return (direction == true)?min(root->data, leftMax):max(root->data, leftMax);
    }
    int l = checkIfBst(root->left , false);
    int r = checkIfBst(root->right , true);
    if(root->data < l || root->data >= r){
        ans = false;
        return -1;
    }
    return (direction == true)?min(root->data, min(l,r)):max(root->data, max(l,r));

}
int main(){
    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);
    root->right = new Node(8);
    root->right->right = new Node(9);
    root->right->right->right = new Node(10);
    root->right->left = new Node(7);
    int leftMax = checkIfBst(root->left, false);
    int rightMin = checkIfBst(root->right, true);
    // assume tree has atleast 3 nodes
    if(ans==true && root->data >= leftMax && root->data < rightMin ){
        cout<<"Yes given tree is a bst";
    }
    else cout<<"Not a bst";
    cout<<ans<<endl;
}
