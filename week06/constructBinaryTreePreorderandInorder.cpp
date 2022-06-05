#include "bits/stdc++.h"
using namespace std;
TreeNode* generateTree(vector<int>& preorder, vector<int>& inorder, int L, int R, int &pos, unordered_map<int, int>&map)
{
    if(L > R) return NULL;
    auto currRoot = new TreeNode(preorder[pos++]);
    int M = map[currRoot->val];
    currRoot->left = generateTree(preorder, inorder, L, M - 1, pos, map);
    currRoot->right = generateTree(preorder, inorder,R, M + 1, pos, map); 
    return currRoot;
};
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int pos = 0;
    unorder_map<int, int> map;
    for(int i = 0; i < inorder.size(); i++)
    {
        map[inorder[i]] = i;
    }
    return generateTree(preorder,inorder,0,preorder.size() - 1,pos, map);
}