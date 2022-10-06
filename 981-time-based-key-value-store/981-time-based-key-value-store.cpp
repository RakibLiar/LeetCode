class TimeMap {
public:
    unordered_map<string, vector<int>> mp1;
    unordered_map<string, vector<string>> mp2;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp1[key].push_back(timestamp);
        mp2[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(mp1[key].size() == 0 || mp1[key][0] > timestamp) return "";
        int sz = mp1[key].size();
        if(mp1[key][sz-1] <= timestamp) return mp2[key][sz-1];
        int index = lower_bound(mp1[key].begin(), mp1[key].end(), timestamp) - mp1[key].begin();
        if(mp1[key][index] > timestamp) index--;
        return mp2[key][index];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */