class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        priority_queue<int , vector<int> , greater<int>>pq;
        for( int i = 0 ; i < n ; i++){
            pq.push(i);
        }

        sort(meetings.begin() , meetings.end() , [](const vector<int>&a , 
        const vector<int>&b){
            return (long long)a[0] < (long long)b[0];
        });

        // we are pushing all the elements in the queue 
        // so that we can manage the free rooms ;

        priority_queue<pair<int , int> , vector<pair<int , int>> , 
        greater<pair<int,int>>>pq2;

        vector<int>output(n,0);

        for( auto it : meetings){
            int starttime = it[0];
            int endtime = it[1];
          

          while(!pq2.empty() && pq2.top().first <= starttime){
              int value = pq2.top().second;
              pq2.pop();
              pq.push(value);
          }

          if(pq.empty()){
             
             auto it = pq2.top();
             pq2.pop();

             endtime = it.first + (endtime-starttime);
             pq.push(it.second);

          }

          int room = pq.top();
          pq.pop();
          pq2.push({endtime , room});
          output[room]++;

            // if the heap which stores the free room is not 
        }
       
       int maxRoom = 0;
        for (int i = 1 ; i < n; i++) {
            if ( output[i] > output[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;

    }
};