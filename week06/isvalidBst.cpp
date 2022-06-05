 #include "bits/stdc++.h"
 using namespace std;

 bool validateBST(TreeNode* root,long long L_min, long long R_max)
 {
     if(!root) return true;
     long long int v = root->val;
     if(v > R_max || v < L_min) return false;
     return validateBST(root->left, L_min, v - 1) && validateBST(root->right, v + 1,R_max);
 };
 bool isValidBST(TreeNode* root)
 {
     return validateBST(root, LLONG_MIN, LLONG_MAX);
 }
 