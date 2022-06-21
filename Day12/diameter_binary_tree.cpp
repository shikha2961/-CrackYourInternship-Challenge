Problem: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int maxi = 0;
    int height(Node* root){
        if(root==NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return 1+max(left,right);
    }
    int diameter(Node* root) {
        if(root==NULL) return 0;
        left_height = height(root->left);
        right_height = height(root->right);
        maxi = max(maxi,left_height+right_height);
        diameter(root->left);
        diameter(root->right);
        return maxi;
    }
};

Time Complexity = O(N^2)
  
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int d = 0;
    int height(Node* root){
        if(root==NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        d = max(d,left+right);
        return 1+max(left,right);
    }
    int diameter(Node* root) {
        height(root);
        return d+1;
    }
};

Time Complexity: O(N)
  
