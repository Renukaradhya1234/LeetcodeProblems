#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


enum node_identity {
    left,
    right
};

int sumOfLeftLeavesHelper(struct TreeNode* tree_node, enum node_identity node_side) {
    int result = 0;
    if (tree_node->left == NULL && tree_node->right == NULL) {
        if (node_side == left) {
            result = tree_node->val;
        }
    }
    if (tree_node->left != NULL) {
        result += sumOfLeftLeavesHelper(tree_node->left, left);
    } 
    if (tree_node->right != NULL) {
        result += sumOfLeftLeavesHelper(tree_node->right, right);
    }
    return result;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int result = 0;
    if (root->left != NULL) {
        result += sumOfLeftLeavesHelper(root->left, left);
    }
    if (root->right != NULL) {
        result += sumOfLeftLeavesHelper(root->right, right);
    }
    return result;
}