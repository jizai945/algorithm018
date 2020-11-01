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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;

        findson(root, res);
        return res;
    }

    void findson(TreeNode* node, vector<int>& res) {

        if (node==NULL) {
            return;
        }

        // 左根右
        findson(node->left, res);
        res.emplace_back(node->val);
        findson(node->right, res);
        
    }
};