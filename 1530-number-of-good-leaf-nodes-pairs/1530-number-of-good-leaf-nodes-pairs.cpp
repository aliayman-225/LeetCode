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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};

        // If it's a leaf node
        if (!node->left && !node->right) return {1};

        vector<int> leftDists = dfs(node->left, distance, count);
        vector<int> rightDists = dfs(node->right, distance, count);

        // Count pairs
        for (int l : leftDists) {
            for (int r : rightDists) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }

        // Collect distances to return
        vector<int> newDists;
        for (int l : leftDists) {
            if (l + 1 <= distance) newDists.push_back(l + 1);
        }
        for (int r : rightDists) {
            if (r + 1 <= distance) newDists.push_back(r + 1);
        }

        return newDists;
    }
};