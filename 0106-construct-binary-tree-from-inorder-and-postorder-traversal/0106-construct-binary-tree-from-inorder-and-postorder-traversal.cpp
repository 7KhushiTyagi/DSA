
class Solution {
public:
    unordered_map<int,int> InorderIdx;

    TreeNode* build(vector<int> &postorder,int left,int right,int &idx){
        if(left>right) return nullptr;

        int RootVal= postorder[idx--];
        TreeNode* root= new TreeNode(RootVal);

        int mid= InorderIdx[RootVal];

        root->right= build(postorder,mid+1,right,idx);
        root->left= build(postorder,left,mid-1,idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;

        for(int i=0;i<n;i++){
            InorderIdx[inorder[i]]=i;
        }

        return build(postorder,0,n-1,idx);
        
    }
};