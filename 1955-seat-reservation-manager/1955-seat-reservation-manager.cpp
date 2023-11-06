class SeatManager {
public:
    priority_queue< int, vector<int>, greater<int> > pq;
    vector<bool> isReserved;
    SeatManager(int n) {
        for(int i=1; i<=n; i++) {
            pq.push(i);
        }
        isReserved = vector<bool>(n+1, false);
    }
    
    int reserve() {
        while(isReserved[pq.top()]) {
            pq.pop();
        }
        int a = pq.top();
        pq.pop();
        isReserved[a] = true;
        return a;
    }
    
    void unreserve(int seatNumber) {
        isReserved[seatNumber] = false;
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */