#include <iostream>
#include <vector>
using namespace std;

struct trieNode 
{ 
    struct trieNode *child[26]; 
    bool isEnding;
}; 
struct trieNode *newTrieNode(void) 
{ 
    struct trieNode *newNode = new trieNode; 
    newNode->isEnding = false;
    for (int i = 0; i<26; i++) 
        newNode->child[i] = NULL; 
    return newNode; 
} 

void insert(struct trieNode *root, string str) 
{ 
    int len = str.length(); 
    struct trieNode *pCrawl = root; 
  
    for (int level = 0; level<len; level++) 
    { 
        int index = str[level]-'a'; 
        if (!pCrawl->child[index]) 
            pCrawl->child[index] = newTrieNode(); 
        pCrawl = pCrawl->child[index]; 
    } 
    pCrawl ->isEnding = true;
}

bool allPrefixed(struct trieNode *root, string word) {
    struct trieNode *pCrawl = root; 
    for (char c: word) {
      int i = c - 'a';
      pCrawl = pCrawl -> child[i];
      if(pCrawl == NULL || pCrawl->isEnding == false){
        return false;
      }
    }
    return true;
}


string completeString(int n, vector<string> &a) {
    string ans = "";

    struct trieNode *root = newTrieNode();

    for (string word: a)
      insert(root, word);

    for (string word: a) {
      if (!allPrefixed(root, word))
        continue;
      if (ans.size() < word.size()) {
        ans = word;
      }
      else if (ans.size() == word.size() && word < ans) {
        ans = word;
      }
    }

    if (ans.size() == 0) {
      ans = "None";
    }

    return ans;
  }

