#include <iostream>

using namespace std;

class BST
{
public:
    Node *headBST;
    BST()
    {
        headBST = nullptr;
    }

private:
    int find(int data);
    void insert(int data);
    void remove(int data);
};

class Node
{
private:
    Node *left;
    Node *right;
    int data;
    Node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int BST::find(int data)
{
}

int main()
{
}