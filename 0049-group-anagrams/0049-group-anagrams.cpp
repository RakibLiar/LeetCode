class Solution {
public:
    struct Trie {
        vector<string> v;
        Trie *next[26];
        Trie() {
            for(int i=0; i<26; i++) {
                next[i] = nullptr;
            }
        }
    } *root;
    
    void insert(string str, string s) {
        Trie *curr = root;
        for (int i = 0; i < str.size(); i++) {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
                curr->next[id] = new Trie();
            curr = curr->next[id];
        }
        curr->v.push_back(s);
    }
    
    void addAll(Trie *curr, vector<vector<string>> &res) {
        if(curr->v.size()) {
            res.push_back(curr->v);
        }
        for(int i=0; i<26; i++) {
            if(curr->next[i] != nullptr) {
                addAll(curr->next[i], res);
            }
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        root = new Trie();
        for(string s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            insert(temp, s);
        }
        vector<vector<string>> res;
        addAll(root, res);
        return res;
    }
};