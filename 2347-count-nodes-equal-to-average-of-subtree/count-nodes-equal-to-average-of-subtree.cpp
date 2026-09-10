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
    pair<int,int> postorder(TreeNode *root,int &ans){
        if(!root){
            return {0,0};
        }

        pair<int,int> left=postorder(root->left,ans);
        pair<int,int> right=postorder(root->right,ans);

        int sum=left.first+right.first+ root->val;
        int count=left.second + right.second +1;

        int avg=sum/count;
        if(avg==root->val) ans++;

        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        postorder(root,ans);
        return  ans;
        
    }
};