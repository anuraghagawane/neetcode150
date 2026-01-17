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
    bool ans = false;;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverse(root, subRoot);
        return ans;
    }

private:
    void traverse(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return;

        if(root -> val == subRoot -> val) {
            if(isSameTree(root, subRoot)) {
                ans = true;
            }
        }

        traverse(root -> left, subRoot);
        traverse(root -> right, subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        else if((p != NULL && q == NULL) || (p == NULL && q != NULL)) {
            return false;
        }
        if(p -> val != q -> val) {
            return false;
        }

        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};