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
    unordered_map<string, int> seen;
    string calcTreeHash(TreeNode *u, vector<TreeNode*> &dup_roots) {
        if(u == NULL) return "#";
        string subtreeHash = to_string(u->val) + "," + calcTreeHash(u->left, dup_roots) + "," + calcTreeHash(u->right, dup_roots);
        seen[subtreeHash]++;
        if(seen[subtreeHash] == 2)
            dup_roots.push_back(u);
        return subtreeHash;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dup_roots;
        calcTreeHash(root, dup_roots);
        return dup_roots;
    }
};
