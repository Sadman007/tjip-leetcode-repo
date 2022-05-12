//TC: O(n * |str|)  -> n := total_nodes
//MC: O(n * |str|)

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
    unordered_map<string, int> mp;

    string findDuplicateTree(TreeNode* u, vector<TreeNode*> &duplicateTree){
        if(u == NULL) return "#";

        string str = to_string(u->val) + ", " +
            findDuplicateTree(u->left, duplicateTree) + ", " +
            findDuplicateTree(u->right, duplicateTree);

        mp[str]++;
        if(mp[str] == 2){
            duplicateTree.push_back(u);
        }
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicateTree;
        findDuplicateTree(root, duplicateTree);

        return duplicateTree;
    }
};
