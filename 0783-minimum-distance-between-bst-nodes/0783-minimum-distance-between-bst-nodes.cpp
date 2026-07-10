class Solution {
public:
    
    int mini = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        
        inorder(root->left);

        
        if (prev != nullptr) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root; 

       
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mini;
    }
};