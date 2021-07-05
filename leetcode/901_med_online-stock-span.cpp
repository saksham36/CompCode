class StockSpanner {
public:
    stack<int> s;
    vector<int>prices;
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        prices.push_back(price);
        while(!s.empty() && prices[s.top()-1] <= price)
            s.pop();
        int span = s.empty() ? idx+1: idx+1 - s.top();
        idx ++;
        s.push(idx);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */