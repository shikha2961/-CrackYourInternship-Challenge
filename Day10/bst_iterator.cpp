// Problem: https://leetcode.com/problems/binary-search-tree-iterator/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> ans;
    int i=0;
    BSTIterator(TreeNode* root) {
        // Iterative Inorder Traversal
        stack<TreeNode*> s;
        while(root!=NULL || s.empty()==false){
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root=root->right;
        }
    }
    
    int next() {
        int ind = i;
        i++;
        return ans[ind];
    }
    
    bool hasNext() {
        if(i<ans.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
