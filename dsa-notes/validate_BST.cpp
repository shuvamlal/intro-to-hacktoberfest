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
    TreeNode* prev;
    bool dfsTree(TreeNode* root) {
        if(!root)
            return true;
        if(!dfsTree(root->left))
            return false;
        if(prev!=NULL and prev->val >= root->val)
            return false;
        prev = root;
        if(!dfsTree(root->right))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return dfsTree(root);
    }
};
