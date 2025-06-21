class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char c: word) {
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        int mindel = INT_MAX;

        for(int i=0; i<freq.size(); i++) {
            if(freq[i] == 0) continue;
            int totdel = 0;
            int base = freq[i];

            for(int j=0; j<i; j++) totdel+=freq[j];

            for(int j=i; j<freq.size(); j++) {
                if(freq[j] > base + k) {
                    totdel += (freq[j] - (base+k));
                }
            }

            mindel = min(mindel, totdel);
        }
        return mindel;
    }
};