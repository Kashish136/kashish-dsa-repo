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
    bool canAttendMeetings(vector<Interval>& intervals) {
        

        sort(intervals.begin() , intervals.end());
        int prevstart = intervals[0][0];
        int prevend = intervals[0][1];
        int n = intervals.size();

        for( int i = 1 ; i < n ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(prevend < start){
                return false ;
            }
            else{
                prevend = end;
            }
        }

        return true;
    }
};
