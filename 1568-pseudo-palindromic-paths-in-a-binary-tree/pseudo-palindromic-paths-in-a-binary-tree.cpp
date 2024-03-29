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
/*class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return countPalindromicPaths(root, 0);
    }

private:
    int countPalindromicPaths(TreeNode* node, int path) {
        if (node == nullptr) {
            return 0;
        }

        path = path ^ (1 << node->val);

        if (node->left == nullptr && node->right == nullptr) {
            // Leaf node
            return (path & (path - 1)) == 0 ? 1 : 0;
        }

        int leftCount = countPalindromicPaths(node->left, path);
        int rightCount = countPalindromicPaths(node->right, path);

        return leftCount + rightCount;
    }
};
*/
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return countPseudoPalindromes(root, 0);
    }

private:
    int countPseudoPalindromes(TreeNode* node, int path) {
        if (node == nullptr) {
            return 0;
        }

        path ^= (1 << node->val);

        if (node->left == nullptr && node->right == nullptr) {
            // Leaf node
            return (path & (path - 1)) == 0 ? 1 : 0;
        }

        int leftCount = countPseudoPalindromes(node->left, path);
        int rightCount = countPseudoPalindromes(node->right, path);

        return leftCount + rightCount;
    }
};
