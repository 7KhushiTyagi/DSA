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
    void recoverTree(TreeNode* root) {

        TreeNode* prev=nullptr;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;

        TreeNode* curr=root;
        while(curr){
            if(curr->left==nullptr){
                if(prev && prev->val>curr->val){
                    if(first==nullptr){
                        first=prev;
                    }
                        second=curr;
                    
                }
                prev=curr;
                curr=curr->right;
            }else{
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr){
                    pred=pred->right;
                }

                if(pred->right==nullptr){
                    pred->right=curr;
                    curr=curr->left;
                }else{
                    pred->right=nullptr;

                    if(prev && prev->val>curr->val){
                    if(first==nullptr){
                        first=prev;
                    }
                        second=curr;
                    
                }
                prev=curr;
                curr=curr->right;

                }
            }
        }
        if(first && second){
            swap(first->val,second->val);
        }
        
    }
};