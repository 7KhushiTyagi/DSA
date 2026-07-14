class Solution {
public:
    TreeNode* build(vector<int>& preorder, int left, int right) {

        if(left > right)
            return nullptr;

        int rootVal = preorder[left];

        int mid = left + 1;

        while(mid <= right && preorder[mid] < rootVal)
            mid++;

        TreeNode* root = new TreeNode(rootVal);

        root->left = build(preorder, left + 1, mid - 1);
        root->right = build(preorder, mid, right);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};