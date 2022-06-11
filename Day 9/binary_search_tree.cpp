#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Default constructor
    Node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    // Parameterized constructor
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    Node* root;
public:

    // Build a binary search tree
    Node *insert(Node *, int);

    // Inorder traversal
    void inorder(Node *);

    // Search in a BST
    bool search(Node *, int );

    // Delete a node from BST
    Node* delete_node(Node* , int );

    // print values in a given range of x and y
    void print_in_range(Node* , int , int);

    // Print root to leaf paths in BST
    void root_to_leaf(Node* , vector<int>&);

};

Node *BST::insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else{
        Node* curr;
        if (root->val >= val)
        {
            // go to the left subtree
            curr = insert(root->left, val);
            root->left = curr;
        }
        else
        {
            // go to the right subtree
            curr = insert(root->right, val);
            root->right = curr;
        }
        return root;
    }
}

void BST::inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
    
}

bool BST:: search(Node* root, int key){
    if(root==NULL) return false;
    if(root->val>key){
        return search(root->left, key);
    }
    else if(root->val==key){ 
        return true;
    }
    else if(root->val<key){
        return search(root->right, key);
    }
    
    return false;
}

Node* InorderSuccessor(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* BST:: delete_node(Node* root, int del){
    if(root->val>del){
       root->left = delete_node(root->left, del);
    }else if(root->val<del){
        root->right = delete_node(root->right, del);
    }else{
        // Case: if leaf node to delete
        if(root->left == NULL && root->right==NULL){
            return NULL;
        }

        // Case: if deleted node has one child
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }

        // Case: if deleted node has both the childrem
        // Inorder successor is the left most node in right subtree
        Node* inorder_successor = InorderSuccessor(root->right);
        root->val = inorder_successor->val;
        root->right = delete_node(root->right, inorder_successor->val);
    }
}

void BST:: print_in_range(Node* root, int x, int y){
    if(root==NULL) return ;
    if(root->val>= x && root->val<=y){
        print_in_range(root->left, x, y);
        cout<<root->val<<" ";
        print_in_range(root->right, x, y);
    }else if(x>root->val){
        print_in_range(root->right, x, y);
    }else{
        print_in_range(root->left, x, y);
    }
}
void print_path(vector<int>& path){
    for(auto it: path){
        cout<<it<<" ";
    }
    cout<<endl;
}
void BST::root_to_leaf(Node* root, vector<int>& path){
    if(root==NULL) return ;
    path.push_back(root->val);
    // leaf node , so we have traversed the whole path now print it.
    if(root->left==NULL && root->right==NULL){
        print_path(path);
    }else{
        root_to_leaf(root->left, path);
        root_to_leaf(root->right, path);
    }
    path.pop_back();
}
int main()
{
    vector<int> values = {5, 1, 2, 4, 3, 8};
    BST myobj;
    Node *ans = NULL;
    
    // Insertion in binary search tree
    for (int i = 0; i < values.size(); i++)
    {   
        ans = myobj.insert(ans, values[i]);
    }

    // Inorder traversal
    myobj.inorder(ans);
    cout<<"\n";
    // search value in BST
    bool answer = myobj.search(ans, 3);
    cout<<"Check if given key is found in BST or not"<<endl;
    if(answer==true) cout<<"Key found"<<endl;
    else cout<<"Not found"<<endl;

    // Delete a node with given value
    myobj.delete_node(ans, 3);
    cout<<"Inorder traversal after deleting a node with a given value"<<endl;
    myobj.inorder(ans);
    cout<<endl;

    // Print values in a given range
    cout<<"values in a given range"<<endl;
    myobj.print_in_range(ans, 1,5);
    cout<<endl;

    // root to leaf path print
    cout<<"Various paths from root to leaf"<<endl;
    vector<int> path;
    myobj.root_to_leaf(ans, path);
    return 0;
}
