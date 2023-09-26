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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root)   return ans;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();

            mp[col][row].insert(temp->val);

            if(temp->left)  q.push({temp->left, {col-1, row+1}});
            if(temp->right)  q.push({temp->right, {col+1, row+1}});
        }

        for(auto it : mp){
            vector<int> temp;
            for(auto it2 : it.second){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};