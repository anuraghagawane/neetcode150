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
    bool ans = true;
public:
    int traverse(TreeNode* root) {
        if(!ans) return 0;
        if(root == NULL) return 0;
        int left = traverse(root -> left);
        int right = traverse(root -> right);

        if(abs(left - right) > 1) {
            ans = false;
            return 0;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        traverse(root);

        return ans;
    }
};