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

class BSTIterator{
    stack<TreeNode*> st;
    bool reverse = true;
    // true means before
    // false means next

    private:
    void pushInStk(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse == false)    root = root->left;
            else    root = root->right;
        }
    }

    public:

    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushInStk(root);
    }

    int next(){
        TreeNode* ans = st.top();
        st.pop();

        if(!reverse)    pushInStk(ans->right);
        else    pushInStk(ans->left);

        return ans->val;
    }

    bool hasNext(){
        return !st.empty();
    }


};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(!root)   return false;

        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while(i < j){
            if(i + j == k)  return 1;
            else if( i+j < k)   i = left.next();
            else    j = right.next();
        }
        return 0;
        
    }
};