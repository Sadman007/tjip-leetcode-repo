#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    bool isWord;
    TrieNode* next[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
            isWord = false;
        }
    }
    void printNode(){
        cout<<"STATUS : "<<isWord<<endl;
        for(int i = 0; i < 26; i++){
            if(next[i]){
                cout<< (char)('a' + i) <<endl;
            }
        }
        cout<<endl;
    }
};

void insertString(TrieNode *root, string str){// word insert(str = rat)
    TrieNode* currNode = root;
    for(auto c:str){
        int order = c - 'a';
        if(currNode->next[order]==NULL){
            currNode->next[order] = new TrieNode();
        }
        currNode = currNode->next[order];
    }
    currNode->isWord = true;
}

bool exists(TrieNode* root, string str, bool isPrefixSearch = false){// word search
    TrieNode* currNode = root;
    for(auto c: str){
        int order = c - 'a';
        if(currNode->next[order]==NULL){
            return false;
        }
        currNode = currNode->next[order];
    }
    return currNode && (currNode->isWord || isPrefixSearch);
}

bool existsAsPrefix(TrieNode* root, string str){
    return exists(root,str,true);
}

int main()
{
    TrieNode* root = new TrieNode();
    insertString(root,"rat");// sorasori string pass korle func() e &str dewa jabe na..just str dewa lgbe
    insertString(root,"rab");
    cout<<exists(root,"rab")<<endl;
    cout<<exists(root,"ra")<<endl;
    cout<<existsAsPrefix(root,"ra")<<endl;
    cout<<existsAsPrefix(root,"rx")<<endl;
    root->printNode();
    root->next['r' - 'a']->printNode();
    root->next['r' - 'a']->next['a' - 'a']->printNode();
    root->next['r' - 'a']->next['a' - 'a']->next['t' - 'a']->printNode();
    return 0;
}

