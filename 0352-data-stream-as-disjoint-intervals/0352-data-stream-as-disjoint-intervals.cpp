class SummaryRanges {
public:
    vector<bool> v;
    SummaryRanges() {
        v = vector<bool> (10001, false);
    }
    
    void addNum(int value) {
        v[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start = -1;
        int end = -1;
        for(int i=0; i<=10000; i++) {
            if(!v[i]) {
                if(start != -1) {
                    res.push_back({start, end});
                }
                start = end = -1;
            } else {
                if(start == -1) {
                    start = i;
                    end = i;
                } else {
                    end = i;
                }
            }
        }
        if(start != -1) {
            res.push_back({start, end});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */