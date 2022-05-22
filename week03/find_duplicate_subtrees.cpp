/**
Time: O(N), where N = number of nodes in the tree
Memory: O(N) where N = total number o nodes in the tree
**/

class Solution {
public:
    unordered_map<string, int> seen;
    
    string calculateTreeHash(TreeNode* u, vector<TreeNode*>&dup_roots) {
		if (u == NULL) return "#";
        
		string subtreeHash = to_string(u->val) +
            "," + calculateTreeHash(u->left, dup_roots) + 
            "," + calculateTreeHash(u->right, dup_roots);
        
        seen[subtreeHash]++;
        
		if (seen[subtreeHash] == 2) {
			dup_roots.push_back(u);
		}
        
		return subtreeHash;
	}
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dup_roots;
        calculateTreeHash(root, dup_roots);
        return dup_roots;
    }
};