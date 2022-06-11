Problem: https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> ans;
    void func(TreeNode* root, string s){
        if(root==NULL) return;
        s += to_string(root->val)+"->";
        if(root->left==NULL && root->right==NULL){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
        }else{
            func(root->left,s);
            func(root->right,s);
        }
        s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        func(root,s);
        return ans;
    }
};
