// Problem:: https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }else if(root->val>=val){
            root->left = insertIntoBST(root->left, val);
        }else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
/*
Time Complexity: O(H) , H is the height of the tree
WOrst case complexity: O(N) , N is the number of nodes
*/
