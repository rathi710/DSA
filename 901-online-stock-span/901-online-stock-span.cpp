class StockSpanner {
public:
    
    //pair.first denotes the price 
	//pair.second denotes the number of stocks less than equal to the current price
    stack<pair<int,int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;            //since current stock is also counted
        
        //get the previous stocks which are less than or equal to the  current price
        while(!st.empty() && st.top().first<=price)
        {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price,span});
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */