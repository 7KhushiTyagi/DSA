class Solution {

public:
    int mini=INT_MAX;
    TreeNode* prev=nullptr;

    void helper(TreeNode* &root){
         if(!root) return;

         helper(root->left);
         if(prev!=nullptr){
            mini=min(mini,root->val-prev->val);
         }

         prev=root;

         helper(root->right);


    }

    int minDiffInBST(TreeNode* root) {
        helper(root);
        return mini;
    }
};