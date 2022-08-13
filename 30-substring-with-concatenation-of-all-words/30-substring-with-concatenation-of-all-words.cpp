class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int tws = words.size() * words[0].size(), ws = words[0].size();
        unordered_map<string, int> mp;
        for(string w: words) {
            mp[w]++;
        }
        vector<int> res;
        string a,b;
        //cout<<(int)s.size()-tws<<endl;
        for(int i=0; i<=(int)s.size()-tws; i++) {
            unordered_map<string, int> temp;
            a = "";
            b = "";
            for(int j=i; j<=i+tws; j++) {
                //cout<<j<<endl;
                b += s[j];
                if((j-i+1)%ws == 0) {
                    //cout<<b<<endl;
                    if(temp[b] < mp[b])
                        a+=b, temp[b]++, b = "";
                    else {
                        b = "";
                        break;
                    }
                }
            }
            //cout<<i<<" "<<a.size()<<endl;
            if(a.size() == tws)
                res.push_back(i);
        }
        return res;
    }
};