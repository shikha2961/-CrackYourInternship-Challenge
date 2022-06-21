Problem: 


// Recursive:
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL){
            return root2;
        }
        
        if(root2==NULL){
            return root1;
        }
        root1->val += root2->val;
        
        root1->left = mergeTrees(root1->left,  root2->left);
        
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// Iterative:
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root1,root2});
        while(!st.empty()){
            pair<TreeNode*,TreeNode*> t = st.top();
            st.pop();
            if(!t.first || !t.second){
                continue;
            }
            t.first->val += t.second->val;
            if(!t.first->left){
                t.first->left = t.second->left;
            }else{
                st.push({t.first->left,t.second->left});
            }
            if(!t.first->right){
                t.first->right = t.second->right;
            }else{
                st.push({t.first->right,t.second->right});
            }
        }
        return root1;
    }
};
