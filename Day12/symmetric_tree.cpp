Problem: https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool func(TreeNode* p, TreeNode* q){
        if((p==NULL && q!=NULL) || (q==NULL && p!=NULL)) return false;
        if(p==NULL && q==NULL) return true;
        if(p->val!=q->val){
            return false;
        }
        return func(p->left,q->right) && func(p->right,q->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return func(root->left,root->right);
    }
};
