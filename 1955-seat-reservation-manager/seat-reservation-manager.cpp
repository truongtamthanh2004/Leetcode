class SeatManager {
public:
    priority_queue<int> free;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            free.push(-i);
    }
    
    int reserve() {
        int res = -free.top();
        free.pop();
        return res;
    }
    
    void unreserve(int seatNumber) {
        free.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */