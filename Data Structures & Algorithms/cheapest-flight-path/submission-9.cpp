class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        vector<int>prices(n,INT_MAX);
        prices[src] = 0;

        for(int i = 0 ; i <= k ; i++){

            for(const auto &flight : flights){
                int source = flight[0];
                int destination = flight[1];
                int price = flight[2];

                if(prices[source] != INT_MAX && prices[source]+wt < prices[destination]){
                    prices[destination] = prices[source]+price;
                }
            }
        }


        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
