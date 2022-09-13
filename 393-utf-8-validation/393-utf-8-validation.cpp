class Solution {
public:
    string common(int n) {
        string s;
        for(int i=0; i<8; i++) {
            s += (n%2 + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    bool isValid(int n) {
        string s = common(n);
        return s[0] == '1' && s[1] == '0';
    }
    
    int utfBit(int n) {
        string s = common(n);
        int cnt = 0, i;
        for(i=0; i<8 && s[i] == '1'; i++) {
            if(s[i] == '1')
                cnt++;
        }
        return (i != 8 && s[i] == '0') ? i : -1;
    }
    
    bool validUtf8(vector<int>& data) {
        int i;
        for(i=0; i<data.size(); i++) {
            int bit = utfBit(data[i]);
            if(bit == 1 || bit == -1 || bit > 4) return false;
            for(int j=1; j+i<data.size() && j < bit; j++) {
                if(!isValid(data[i+j])) {
                    return false;
                }
            }
            if(bit != 0)
                i += (bit-1);
        }
        return i == data.size();
    }
};