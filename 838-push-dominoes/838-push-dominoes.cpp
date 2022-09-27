class Solution {
public:
    void setLeft(vector<int> &v, vector<int> &right, string s, int pos) {
        v[pos--] = 0;
        while(pos>=0 && s[pos] == '.' && right[pos] >= v[pos+1] + 1) {
            v[pos] = v[pos+1] + 1;
            pos--;
        }
    }
    
    void setRight(vector<int> &v, vector<int> left, string s, int pos) {
        v[pos++] = 0;
        while(pos<s.size() && s[pos] == '.' && left[pos] >= v[pos-1] + 1) {
            v[pos] = v[pos-1] + 1;
            pos++;
        }
    }
    
    string pushDominoes(string s) {
        vector<int> left(s.size(), INT_MAX), right(s.size(), INT_MAX);
        //cout<<s.size()<<endl;
        int k = 0, sz = s.size();
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'L') {
                k = 0;
            }
            if(s[i] == 'R') {
                k = sz;
            }
            right[i] = k;
            k--;
            if(k<0) k = 0;
        }
        k = 0;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == 'R') {
                k = 0;
            }
            if(s[i] == 'L') {
                k = -sz;
            }
            left[i] = k;
            k++;
            if(k > 0) k = 0;
        }
        for(int i=0; i<s.size(); i++) {
            if(left[i] + right[i] > 0)
                s[i] = 'R';
            else if(left[i] + right[i] < 0)
                s[i] = 'L';
        }
        return s;
    }
};