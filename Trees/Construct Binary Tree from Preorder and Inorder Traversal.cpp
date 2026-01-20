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
    unordered_map<int, int> mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if(prel > prer || inl > inr) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prel]);

        int elIn = mp[root -> val];
        int elementOnLeft = elIn - inl + 1;

        root -> left = solve(preorder, inorder, prel + 1, prel + elementOnLeft, inl, elIn - 1);
        root -> right = solve(preorder, inorder, prel + elementOnLeft, prer, elIn + 1, inr);

        return root;
    }

};