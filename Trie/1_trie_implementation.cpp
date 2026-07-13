// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main()
{
    Trie *tr = new Trie();

    tr->insert("apple");
    tr->insert("app");
    tr->insert("bat");
    tr->insert("ball");
    /* resulting trie (* marks end of a word):
       root
        ├─ a ─ p ─ p* ─ l ─ e*     ("app", "apple")
        └─ b ─ a ─┬─ t*             ("bat")
                   └─ l ─ l*        ("ball")
    */

    cout << tr->startsWith("app") << endl;
    cout << tr->search("apps") << endl;
    cout << tr->search("bat") << endl;
    cout << tr->startsWith("ba") << endl;

    return 0;
}