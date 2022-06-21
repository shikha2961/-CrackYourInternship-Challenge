Problem: https://practice.geeksforgeeks.org/problems/check-if-subtree/1/#

class Solution
{
  bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 && !r2) return true;
        if((r1  && !r2) || (!r1 && r2)) return false;
        if(r1->data != r2->data) return false;
        bool l =  isIdentical(r1->left, r2->left);
        bool r =  isIdentical(r1->right, r2->right);
        return l && r;
        
    }  
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        if(S==NULL) return true;
        if(T==NULL) return false;
        
           if(isIdentical(T,S)) return true;
        bool l = isSubTree(T->left, S);
        bool r = isSubTree(T->right, S);
        return l||r;
    }
};

Time Complexity: O(mn)
Auxillary Space: O(n)
  
  
class Solution {
public:
    void func(TreeNode* node, string& s){
        if(!node){
            s.append("#");
            return;
        }
        s.append('*' + to_string(node->val) + '*');
        func(node->left, s);
        func(node->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, s2;
        func(root,s1);
        func(subRoot,s2);
        return s1.find(s2)!=string::npos;
    }
};
Time Complexity: O(N)
Space Complexity: O(N)
