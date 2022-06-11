Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int func(TreeNode* root){
        if(root==NULL) return 0;
        int left = func(root->left)+1;
        int right = func(root->right)+1;
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return func(root);
    }
};
// TC-> O(N) and SC-> O(N)
