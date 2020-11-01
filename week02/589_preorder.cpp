// ----------------------- leetcode589------------------------------

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector<int> res;

        if (root == NULL) {
            return res;
        }

        findson(root, res);
        return res;
    }

    void findson(Node* node, vector<int>& res) {
        if (node == NULL) return;

        res.emplace_back(node->val); 

        for (int i=0; i<node->children.size(); i++) {
            if (node->children[i] != NULL) {
                findson(node->children[i], res);
            }
        }
    }

};