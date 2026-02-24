/**
 * Definition for a binary tree node.  */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 
 void sumRootToLeafHelper(struct TreeNode* node, int* result, int current_value) {
    if (node == NULL) return;

    // shift left (multiply by 2) and add current bit
    current_value = (current_value << 1) | node->val;

    if (node->left == NULL && node->right == NULL) {
        *result += current_value;
        return;
    }

    sumRootToLeafHelper(node->left, result, current_value);
    sumRootToLeafHelper(node->right, result, current_value);
}

int sumRootToLeaf(struct TreeNode* root) {
    int result = 0;
    sumRootToLeafHelper(root, &result, 0);
    return result;
}