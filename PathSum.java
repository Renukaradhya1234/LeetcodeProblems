/**
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * Explanation: The root-to-leaf path with the target sum is shown.
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * Explanation: There are two root-to-leaf paths in the tree:
 * (1 --> 2): The sum is 3.
 * (1 --> 3): The sum is 4.
 * There is no root-to-leaf path with sum = 5.
 * Example 3:
 * 
 * Input: root = [], targetSum = 0
 * Output: false
 * Explanation: Since the tree is empty, there are no root-to-leaf paths.
 */

import packages.TreeNode;

public class PathSum {
    private boolean hasPathSum(TreeNode tree_node, int target_sum, int current_sum) {
        boolean result = false;
        current_sum += tree_node.val;
        if (tree_node.left == null && tree_node.right == null) {
            if (current_sum == target_sum) {
                result = true;
            }
        } else {
            if (tree_node.left != null) {
                result = this.hasPathSum(tree_node.left, target_sum, current_sum);
            }
            if (result == false && tree_node.right != null) {
                result = this.hasPathSum(tree_node.right, target_sum, current_sum);
            }
        }
        return result;
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        boolean result = false;
        if (root != null) {
            result = this.hasPathSum(root, targetSum, 0);
        } 

        return result;
    }
}
