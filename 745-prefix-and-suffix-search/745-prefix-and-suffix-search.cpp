class WordFilter {
public:
    map<string, int> mp;
    WordFilter(vector<string>& words) {
        int len = words.size();
        for(int i=0; i<len; i++) {
            string word = words[i];
            int n = word.size();
            for(int j=1; j<=n; j++) {
                for(int k=n-1; k>=0; k--) {
                    string key = word.substr(0, j) + "#";
                    key += word.substr(k, n-k);
                    mp[key] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp.count(prefix + "#" + suffix) ? mp[prefix + "#" + suffix] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */