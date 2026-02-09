/**
 * Definition for a binary tree node.  */
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void countElements(struct TreeNode* tree_node, int* count_variable) {
    if (tree_node != NULL) {
        (*count_variable)++;
        countElements(tree_node->left, count_variable);
        countElements(tree_node->right, count_variable);
    }
}

void inorderTraversal(struct TreeNode* tree_node, int* num_array, int* num_array_index) {
    if (tree_node != NULL) {
        inorderTraversal(tree_node->left, num_array, num_array_index);
        num_array[(*num_array_index)++] = tree_node->val;
        inorderTraversal(tree_node->right, num_array, num_array_index);
    }
}

struct TreeNode* createBalancedBST(int* num_array, int start_index, int end_index) {
    struct TreeNode* result = NULL;

    if (start_index <= end_index) {
        int mid_index = start_index + (end_index-start_index)/2;
        result = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (result != NULL) {
            result->val = num_array[mid_index];
            result->left = createBalancedBST(num_array, start_index, mid_index-1);
            result->right = createBalancedBST(num_array, mid_index+1, end_index);
        }
    }

    return result;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    struct TreeNode* result = NULL;
    int total_elements = 0;
    countElements(root, &total_elements);

    int* num_array = (int*)malloc(total_elements*sizeof(int));
    if (num_array != NULL) {
        int num_array_index = 0;
        inorderTraversal(root, num_array, &num_array_index);
        result = createBalancedBST(num_array, 0, total_elements-1);
    }

    free(num_array);
    return result;
}