class MyCalendarThree {
public:
    vector<int> v;
    MyCalendarThree() {
        
    }
    
    static bool comp(int a, int b) {
        if(abs(a) == abs(b))
            return a<b;
        return abs(a) < abs(b);
    }
    
    int book(int start, int end) {
        v.push_back(start);
        v.push_back(-end);
        sort(v.begin(), v.end(), comp);
        int ans = 0, mx = 0;
        for(int a: v) {
            if(a >= 0)
                ans++;
            else
                ans--;
            mx = max(ans, mx);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */