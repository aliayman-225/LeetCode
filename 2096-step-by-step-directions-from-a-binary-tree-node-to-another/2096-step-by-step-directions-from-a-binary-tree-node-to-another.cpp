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
    void findPaths(TreeNode* node, int startValue, int destValue, string &currentPath, string &startPath, string &destPath) {
        if (!node) return;

        if (node->val == startValue) startPath = currentPath;
        if (node->val == destValue) destPath = currentPath;

        currentPath.push_back('L');
        findPaths(node->left, startValue, destValue, currentPath, startPath, destPath);
        currentPath.pop_back();

        currentPath.push_back('R');
        findPaths(node->right, startValue, destValue, currentPath, startPath, destPath);
        currentPath.pop_back();
    }
        string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath, path;
        findPaths(root, startValue, destValue, path, startPath, destPath);

        int commonLength = 0;
        while (commonLength < startPath.size() && commonLength < destPath.size() && startPath[commonLength] == destPath[commonLength]) {
            ++commonLength;
        }

        string result;
        for (int i = commonLength; i < startPath.size(); ++i) {
            result.push_back('U');
        }
        result.append(destPath.begin() + commonLength, destPath.end());

        return result;
    }
};