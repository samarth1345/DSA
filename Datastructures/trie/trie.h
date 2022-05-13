#include <bits/stdc++.h>
using namespace std;
class Trie
{
    Trie *Arr[26];
    bool flag;

public:
    Trie()
    {
        for (int i = 0; i < 26; i++)
            Arr[i] = NULL;
        flag = false;
    }

    void insert(string word)
    {
        Trie *newTrie = Arr[word[0] - 'a'];
        if (newTrie == NULL)
        {
            newTrie = new Trie();
            Arr[word[0] - 'a'] = newTrie;
        }
        if (word.length() > 1)
            newTrie->insert(word.substr(1, word.length() - 1));
        else
            newTrie->flag = true;
    }

    bool search(string word)
    {
        if (Arr[word[0] - 'a'] != NULL)
        {
            if (word.length() > 1)
                return Arr[word[0] - 'a']->search(word.substr(1, word.length() - 1));
            return Arr[word[0] - 'a']->flag;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if (Arr[prefix[0] - 'a'] != NULL)
        {
            if (prefix.length() > 1)
                return Arr[prefix[0] - 'a']->startsWith(prefix.substr(1, prefix.length() - 1));
            else
                return true;
        }
        return false;
    }
};