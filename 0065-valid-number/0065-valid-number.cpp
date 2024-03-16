class Solution {
public:
    bool hasInvalidCharacter(string s) {
        int dot = 0, e = 0, d = 0;
        for(char c: s) {
            if(c == '+' || c == '-')
                continue;
            else if((c >= '0' && c<='9'))
                d++;
            else if(c == '.')
                dot++;
            else if(c == 'e' || c == 'E')
                e++;
            else
                return true;
        }
        return (dot > 1 || e > 1 || d == 0);
    }
    
    bool hasInvalidPlusMinus(string s) {
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '-' || s[i] == '+') {
                if(i == 0 || s[i-1] == 'e' || s[i-1] == 'E') continue;
                return true;
            }
        }
        return false;
    }
    
    bool isInvalidDecimal(string s) {
        if(s.size() == 0) return false;
        bool hasDotFound = false;
        int digit = 0, start = (s[0] == '-' || s[0] == '+') ? 1: 0;
        for(int i=start; i < s.size(); i++) {
            char c = s[i];
            if(c == '.') {
                continue;
            } else if((c >= '0' && c <= '9')) {
                digit++;
            } else {
                return true;
            }
        }
        return digit == 0;
    }
    
    bool isInvalidInteger(string s) {
        if(s.size() == 0) return false;
        int digit = 0, start = (s[0] == '-' || s[0] == '+') ? 1: 0;
        for(int i=start; i<s.size(); i++) {
            char c = s[i];
            if(c < '0' || c > '9') return true;
            digit++;
        }
        return digit == 0;
    }
    
    bool isNumber(string s) {
        if(s.size() == 1) {
            return (s[0] >= '0' && s[0] <= '9');
        }
        if(s[0] == 'e' || s[0] == 'E' || s[s.size()-1] == 'e' || s[s.size()-1] == 'E')
            return false;
        if(s[s.size()-1] == '-' || s[s.size()-1] == '+')
            return false;
        if(hasInvalidCharacter(s))
            return false;
        if(hasInvalidPlusMinus(s))
            return false;
        string beforeE, afterE;
        bool hasEFound = false;
        for(char c: s) {
            if(c == 'e' || c == 'E') {
                hasEFound = true;
            } else if(hasEFound == true && c == '.') {
                return false;
            } else if(hasEFound) {
                afterE += c;
            } else {
                beforeE += c;
            }
        }
        if(isInvalidDecimal(beforeE)) return false;
        if(isInvalidInteger(afterE)) return false;
        return true;
    }
};