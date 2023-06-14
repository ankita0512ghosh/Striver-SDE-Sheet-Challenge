#include <iostream>
#include <vector>
using namespace std;


struct TrieNode
{
	TrieNode *childern[26];
	int wordCount;
	int prefixCount;

	TrieNode()
	{
		for (int i = 0; i < 26; i++)
		{
			childern[i] = NULL;
		}
		wordCount = 0;
		prefixCount = 0;
	}
	~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (childern[i] != NULL)
            {
                delete childern[i];
            }
        }
    }
};

class Trie{
	public:
	TrieNode *root;

	Trie()
	{
		root = new TrieNode();
	}
	~Trie()
	{
		delete root;
	}

	void insert(string &word)
	{
		TrieNode *curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';

			if (curr->childern[index] == NULL)
			{
				curr->childern[index] = new TrieNode();
			}
			curr = curr->childern[index];
			curr->prefixCount++;
		}
		curr->wordCount++;
	}

	int countWordsEqualTo(string &word)
	{
		TrieNode *curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';

			if (curr->childern[index] == NULL)
			{
				return 0;
			}
			curr = curr->childern[index];
		}
		return curr->wordCount;
	}

	int countWordsStartingWith(string &word)
	{
		TrieNode *curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';

			if (curr->childern[index] == NULL)
			{
				return 0;
			}
			curr = curr->childern[index];
		}
		return curr->prefixCount;
	}

	void erase(string &word)
	{
		TrieNode *curr = root;
		TrieNode *toBeDeleted = NULL;

		for (int i = 0; i < word.length(); i++)
		{
			int index = word[i] - 'a';

			TrieNode *parent = curr;
			curr = curr->childern[index];

			curr->prefixCount--;

			if (toBeDeleted != NULL)
			{
				toBeDeleted = NULL;
			}

			if (curr->prefixCount == 0)
			{
				if (toBeDeleted == NULL)
				{
					parent->childern[index] = NULL;
				}
				toBeDeleted = curr;
			}
		}

		curr->wordCount--;
		if (toBeDeleted != NULL)
		{
			toBeDeleted = NULL;
		}
	}
};
