//TC: O(N)
//MC: O(1)

class Solution {
public:
    void populate(Node* curRoot, Node* parent = NULL, int isLeft = 0){
        if(curRoot == NULL) return;

        if(!isLeft && (parent == NULL || parent->next == NULL)){
            curRoot->next = NULL;
        }

        else if(isLeft){
            curRoot->next = parent->right;
        }

        else {
            curRoot->next = parent->next->left;
        }

        populate(curRoot->left, curRoot, 1);
        populate(curRoot->right, curRoot, 0);

    }

    Node* connect(Node* root) {
        populate(root);

        return root;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
