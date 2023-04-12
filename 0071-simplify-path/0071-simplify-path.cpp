class Solution {
public:
    void setPath(vector<string> &vs, string temp) {
        if(temp == ".")
            return;
        else if(temp == ".." && vs.size())
            vs.pop_back();
        else if(temp.size() && temp != "..")
            vs.push_back(temp);
    }
    string simplifyPath(string path) {
        string answer, temp;
        vector<string> vs;
        for(int i=1; i<path.size(); i++) {
            if(path[i] == '/') {
                setPath(vs, temp);
                temp = "";
            } else {
                temp += path[i];
            }
        }
        if(temp.size()) {
            setPath(vs, temp);
        }
        for(auto s:vs) {
            answer += "/" + s;
        }
        if(!answer.size())
            answer = "/";
        return answer;
    }
};