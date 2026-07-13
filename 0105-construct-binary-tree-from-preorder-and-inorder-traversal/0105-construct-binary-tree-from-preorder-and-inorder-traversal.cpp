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
class Solution {
public:
    unordered_map<int,int> InorderIdx;
    int idx=0;
    TreeNode* helper(vector<int>& preorder,int left,int right){
        if(left>right) return nullptr;

        int RootVal= preorder[idx++];
        TreeNode* root= new TreeNode(RootVal);

        int mid= InorderIdx[RootVal];

        root->left= helper(preorder,left,mid-1);
        root->right= helper(preorder,mid+1,right);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        

        for(int i=0;i<n;i++){
            InorderIdx[inorder[i]]=i;
        }

        return helper(preorder,0,n-1);
        
    }
};