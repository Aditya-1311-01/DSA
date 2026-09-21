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
    void f(TreeNode *root,int targetSum, vector<vector<int>>&ans ,vector<int>&temp,int sum){

        if(!root) return;

        sum+=root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right){
            if(sum==targetSum){
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }

        f(root->left,targetSum,ans,temp,sum);
        f(root->right,targetSum,ans,temp,sum);
        temp.pop_back();
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(root,targetSum,ans,temp,0);

        return ans;
        
    }
};