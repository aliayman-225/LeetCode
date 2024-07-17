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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
        // Helper function to process the tree
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;
            
            node->left = dfs(node->left);
            node->right = dfs(node->right);
            
            if (to_delete_set.count(node->val)) {
                if (node->left) forest.push_back(node->left);
                if (node->right) forest.push_back(node->right);
                return nullptr;
            }
            
            return node;
        };
        
        if (dfs(root)) forest.push_back(root);
        
        return forest;
    }
};
