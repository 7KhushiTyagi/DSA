class BSTIterator{
    stack<TreeNode*> st;
    bool forward;

    void pushIntoStack(TreeNode* root){

        while(root){
            st.push(root);
            root = forward ? root->left : root->right;
        }

    }

    public:

    BSTIterator(TreeNode* root,bool condition){
        forward=condition;
        pushIntoStack(root);
    }

    int next(){
        TreeNode* curr= st.top();
        st.pop();

        if(forward==true){
            if(curr->right) pushIntoStack(curr->right);
        }else{
            if(curr->left) pushIntoStack(curr->left);
        }

        return curr->val;
    }
    bool hasNext(){
        return (!st.empty());
    }

};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator leftIterator(root,true); //inorder
        BSTIterator rightIterator(root,false); //postorder

        int left=leftIterator.next();
        int right=rightIterator.next();

        while(left<right){
            int sum= left+right;

            if(sum==k) return true;
            else if(sum<k){
                if(leftIterator.hasNext()){
                    left= leftIterator.next();
                }else{
                    break;
                }
            }else{
                if(rightIterator.hasNext()){
                    right= rightIterator.next();
                }else{
                    break;
                }
            }
        }
        return false;


        
    }
};