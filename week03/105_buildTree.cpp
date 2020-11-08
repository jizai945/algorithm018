// ------------------------------------ leetcode 105 ------------------------- 

//**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> map;

    TreeNode* GetTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {

        if (preorder_left > preorder_right || inorder_left > inorder_right) return NULL;

        // 前序根值索引
        int preorder_root = preorder_left;
        // 中序根值索引
        int inorder_root = map[preorder[preorder_left]];

        TreeNode* root = new(TreeNode(preorder[preorder_root]));
        int left_tree_size = inorder_root-inorder_left;

        root->left = GetTree(preorder, inorder, preorder_root+1, preorder_root+1+left_tree_size-1, inorder_left, inorder_root - 1);
        root->right = GetTree(preorder, inorder, preorder_root+left_tree_size+1, preorder_right, inorder_root+1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() != inorder.size()) return NULL;

        for (int i=0; i<inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return GetTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

    }
};