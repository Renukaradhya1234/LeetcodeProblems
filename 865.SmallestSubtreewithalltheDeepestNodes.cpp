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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    private :
        TreeNode* lowest_common_parent = nullptr;
        int deepest_count = 0;
        int subtreeWithAllDeepestHelper(TreeNode* current_node, int depth) {
            depth++;
            if (current_node->left == nullptr && current_node->right == nullptr) {
                /// if leap node, update with deepest count...
                if (depth > deepest_count) {
                    deepest_count = depth;
                    lowest_common_parent = current_node;
                }
            } else {
                int left_depth = -1;
                int right_depth = -1;
                if (current_node->left != nullptr) {
                    left_depth = this->subtreeWithAllDeepestHelper(current_node->left, depth);
                } 
                if (current_node->right != nullptr) {
                    right_depth = this->subtreeWithAllDeepestHelper(current_node->right, depth);
                }

                if (left_depth == deepest_count && right_depth == deepest_count) {
                    lowest_common_parent = current_node;
                    depth = left_depth;
                } else if (left_depth >= right_depth) {
                    depth = left_depth;
                } else {
                    depth = right_depth;
                }
            }
            return depth;
        }
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            this->subtreeWithAllDeepestHelper(root, 0);
            return lowest_common_parent;
        }
};