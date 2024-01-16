class RandomizedSet {
public:
    unordered_map<int, bool> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)) {
            mp[val] = true;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it != mp.end()) {
            mp.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = mp.begin();
        advance(it, rand() % mp.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */