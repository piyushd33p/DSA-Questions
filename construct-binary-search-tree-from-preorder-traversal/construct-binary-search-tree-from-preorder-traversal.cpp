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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curr = root;

        for(int i = 1; i< preorder.size(); i++){
            bool insert = false;
            curr = root;

            while(insert == false){
                if(preorder[i] < curr->val){
                    if(!curr->left){
                        curr->left = new TreeNode(preorder[i]);
                        insert = true;
                    }
                    else    curr  = curr->left;
                }
                else{

                    if(!curr->right){
                        curr->right = new TreeNode(preorder[i]);
                        insert = true;
                    }
                    else    curr = curr->right;
                }
            }
        }
        return root;
    }
};