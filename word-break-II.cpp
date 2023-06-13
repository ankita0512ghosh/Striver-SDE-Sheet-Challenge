#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{

public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insert(TrieNode *root, string word)
{
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (curr->children[word[i] - 'a'] == NULL)
        {
            curr->children[word[i] - 'a'] = new TrieNode();
        }
        curr = curr->children[word[i] - 'a'];
    }
    curr->isTerminal = true;
}

void search(TrieNode *root, string &s, vector<string> &res, string temp, int pos)
{
    TrieNode *curr = root;

    for (int i = pos; i < s.size(); i++)
    {
        if (curr->children[s[i] - 'a'] == NULL)
        {
            return;
        }
        if (curr->children[s[i] - 'a']->isTerminal == true)
        {
            string lastWord = temp;
            lastWord.append(s.substr(pos, i - pos + 1));

            if (i == s.size() - 1)
            {
                res.push_back(lastWord);
            }
            else
            {
                search(root, s, res, lastWord + " ", i + 1);
            }
        }
        curr = curr->children[s[i] - 'a'];
    }
    return;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    TrieNode *root = new TrieNode();

    for (int i = 0; i < dictionary.size(); i++)
    {
        insert(root, dictionary[i]);
    }

    vector<string> res;
    search(root, s, res, "", 0);

    return res;
}