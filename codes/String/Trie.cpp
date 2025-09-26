#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        bool endofWord;
        vector<int> children;
        Node() : endofWord(false), children(26, -1) {}
    };

    vector<Node> trie; 

public:
    Trie() {
        trie.emplace_back(); 
    }

    void insert(const string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (trie[cur].children[idx] == -1) {
                trie[cur].children[idx] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].children[idx];
        }
        trie[cur].endofWord = true;
    }

    bool search(const string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (trie[cur].children[idx] == -1) return false;
            cur = trie[cur].children[idx];
        }
        return trie[cur].endofWord;
    }

    bool startsWith(const string& prefix) {
        int cur = 0;
        for (char c : prefix) {
            int idx = c - 'a';
            if (trie[cur].children[idx] == -1) return false;
            cur = trie[cur].children[idx];
        }
        return true;
    }

    void deleteWord(const string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (trie[cur].children[idx] == -1) return;
            cur = trie[cur].children[idx];
        }
        trie[cur].endofWord = false;
    }

    void print(int node, string prefix) const {
        if (trie[node].endofWord) {
            cout << prefix << "\n";
        }
        for (int i = 0; i < 26; i++) {
            int nxt = trie[node].children[i];
            if (nxt != -1) {
                print(nxt, prefix + char('a' + i));
            }
        }
    }

    void print() const { print(0, ""); }
};

int main() {
    Trie trie;

    trie.insert("geek");
    trie.insert("geeks");
    trie.insert("code");
    trie.insert("coder");
    trie.insert("coding");

    cout << "Trie contents:\n";
    trie.print();

    cout << "\nSearch results:\n";
    cout << "geek: " << trie.search("geek") << "\n";
    cout << "geeks: " << trie.search("geeks") << "\n";
    cout << "code: " << trie.search("code") << "\n";
    cout << "coder: " << trie.search("coder") << "\n";
    cout << "coding: " << trie.search("coding") << "\n";
    cout << "codex: " << trie.search("codex") << "\n";

    cout << "\nPrefix results:\n";
    cout << "ge: " << trie.startsWith("ge") << "\n";
    cout << "cod: " << trie.startsWith("cod") << "\n";
    cout << "coz: " << trie.startsWith("coz") << "\n";

    trie.deleteWord("coding");
    trie.deleteWord("geek");

    cout << "\nTrie contents after deletions:\n";
    trie.print();

    cout << "\nSearch results after deletions:\n";
    cout << "coding: " << trie.search("coding") << "\n";
    cout << "geek: " << trie.search("geek") << "\n";

    return 0;
}
