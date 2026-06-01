/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        // sort(intervals.begin() , intervals.end() , [](const Interval&a , 
        // Interval &b){

        //     return a.start < b.start;
        // });


        // priority_queue<int , vector<int> , greater<int>>pq;
        // // we are declaring a minheap;
        // for(const auto&it : intervals){
        //     if(!pq.empty() && pq.top() <= it.start){
        //         pq.pop();
        //     }
        //     pq.push(it.end);
        // }
         
        //  return pq.size();

        vector<int>start , end;
        for( auto it : intervals){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        int ans = 0;
        int i = 0;
        int j = 0;
        int n = intervals.size();
        int output = 0;

        while( i < n ){
            if(start[i] <= end[j]){
                i++;
                ans++;
            }
            else{
                j++;
                ans--;
            }
            output = max(output  , ans);
        }

        return output ;
    }
};
