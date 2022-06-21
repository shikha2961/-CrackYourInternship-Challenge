Problem: https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val>=low && root->val<=high){
            sum = sum + root->val;
        }
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
        return sum;
    }
};
