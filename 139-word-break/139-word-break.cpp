class Node {
public:
    Node* link[26];
    bool flag = false;
 
    bool containKey(char ch)
    {
        return link[ch-'a'] != NULL;
    }
    void put(char ch, Node* node)
    {
        link[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return link[ch-'a'];
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
 
class Trie {
    Node* root;
    int dp[300];
public:
    Trie()
    {
        root = new Node();
    }
 
    Node* getRoot()
    {
        return root;
    }
    void insert(string word)
    {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->containKey(word[i]))
            {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
 
    // DP Memoization Approach
    int search(string word, int startIdx)
    {
        Node* temp = root;
        bool isFound = 0;
        if (dp[startIdx] != -1)
            return dp[startIdx];
 
        for (int i = startIdx; i < word.size(); i++)
        {
            if (!temp->containKey(word[i]))
            {
                dp[startIdx] = 0;
                return dp[startIdx];
            }
 
            temp = temp->get(word[i]);
            if (temp->isEnd())
            {
                isFound = search(word, i+1);
            }
            if (isFound)
                break;
        }
 
        return dp[startIdx] = (isFound || startIdx == word.size()) ? 1 : 0;
 
    }
 
    void resetMemoization(string s)
    {
        for (int i = 0; i < 300; i++)
            dp[i] = -1;
    }
    void del(Node* cur)
    {
        for (int i = 0; i < 26; i++)
            if (cur->link[i])
                del(cur->link[i]);
        delete (cur);
    }
};
 
class Solution {
 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie sol;
        sol.resetMemoization(s);
        for (int i = 0; i < wordDict.size(); i++)
        {
            sol.insert(wordDict[i]);
        }        
        bool ans = (sol.search(s, 0) == 1);
        sol.del(sol.getRoot());
        return ans;
    }
};
