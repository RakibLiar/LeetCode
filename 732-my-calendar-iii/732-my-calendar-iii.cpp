class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    static bool comp(int a, int b) {
        if(abs(a) == abs(b))
            return a<b;
        return abs(a) < abs(b);
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int mx = 0, ans = 0;
        
        for(auto it: mp) {
            ans += it.second;
            mx = max(mx, ans);
        }
        
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */