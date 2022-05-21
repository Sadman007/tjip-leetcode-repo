#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isWord;
    TrieNode *next[26];
    TrieNode()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string str)
    {
        TrieNode *currNode = root;
        for (auto c : str)
        {
            int order = c - 'a';
            if (currNode->next[order] == NULL)
            {
                currNode->next[order] = new TrieNode();
            }
            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }

    bool search(string str, bool isPrefixSearch = false)
    {
        TrieNode *currNode = root;
        for (auto c : str)
        {
            int order = c - 'a';
            if (currNode->next[order] == NULL)
            {
                return false;
            }
            currNode = currNode->next[order];
        }
        return currNode && (currNode->isWord || isPrefixSearch);
    }

    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};
