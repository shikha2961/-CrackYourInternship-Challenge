Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxi = INT_MIN;
    int maxPath(TreeNode* root) {
        if(root==NULL) return 0;
        int leftSum = max(0, maxPath(root->left));
        int rightSum = max(0, maxPath(root->right));
        maxi = max(maxi, (root->val+leftSum+rightSum));
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        maxPath(root);
        return maxi;
    }
};
