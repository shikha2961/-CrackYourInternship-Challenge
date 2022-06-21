Problem:https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

Time Complexity: O(n)
  
  
  Iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* temp = qu.front();
            swap(temp->left, temp->right);
            if(temp->left) qu.push(temp->left);
            if(temp->right) qu.push(temp->right);
            qu.pop();
        }
        return root;
    }
};
