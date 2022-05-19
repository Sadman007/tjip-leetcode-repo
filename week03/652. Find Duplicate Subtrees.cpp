// TC: O(N), where N = number of nodes in the tree
// MC: O(N) where N = total number of nodes in the tree
class Solution {
public:
    unordered_map<string, int> seen;
    string calculateTreeHash(TreeNode* u, vector<TreeNode*> &dupRoots){
        if(u == NULL) return "#";
        string subTreeHash = to_string(u->val) +
            "," + calculateTreeHash(u->left,dupRoots) +
            "," + calculateTreeHash(u->right,dupRoots);

        seen[subTreeHash]++;

        if(seen[subTreeHash]==2){
            dupRoots.push_back(u);
        }
        return subTreeHash;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dupRoots;
        calculateTreeHash(root,dupRoots);
        return dupRoots;
    }
};
