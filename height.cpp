#include <iostream>

using namespace std;

class Node {
    public:

    Node *left;
    Node *right;
    int data;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
int diameterOfBinaryTree(Node* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(Node* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
};

int main (){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(28);
    root->right->left = new Node(27);
    root->right->right = new Node(50);
    root->right->left->right = new Node(29);
    Solution a;
    cout << a.diameterOfBinaryTree(root) << endl;
    return 0;
}