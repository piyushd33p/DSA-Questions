class StockSpanner {
public:
    stack<pair<int,int>> st;
    // void findSpan(stack<int>& st, int num, vector<int>& count){
    //     if(st.empty() || st.top() > num){
    //         return;
    //     }

    //     count[0]++;
    //     int ele = st.top();
    //     st.pop();

    //     findSpan(st, num, count);
    //     st.push(ele);
    // }

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */