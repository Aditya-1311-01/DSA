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
        map<int, vector<pair<int,int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int row = pos.first;
            int col = pos.second;

            mp[col].push_back({row, node->val});

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for (auto &[col, nodes] : mp) {
            sort(nodes.begin(), nodes.end());

            vector<int> temp;

            for (auto &[row, value] : nodes)
                temp.push_back(value);

            ans.push_back(temp);
        }

        return ans;
    }
};