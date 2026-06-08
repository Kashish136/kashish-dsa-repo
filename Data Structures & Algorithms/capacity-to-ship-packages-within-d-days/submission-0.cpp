class Solution {
public:
    
    int helper(vector<int>&weights , int mid){
        int count = 1;
        int initial = 0;

        for(int i = 0 ; i < weights.size() ; i++){
            int wt = weights[i];
            if((initial+wt) <= mid){
                initial += wt;
            }
            else{
                count++;
                initial = wt;
            }
        }
      return count ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        

        int low = *min_element(weights.begin() , weights.end());
        int high = *max_element(weights.begin() , weights.end());
        int ans = -1;


        while(low <= high){
            int mid = (low+(high-low)/2);
            if(helper(weights , mid) <= days){
                ans = mid;
                high = mid-1;
            }

            else{
                low = mid+1;
            }
        }
        return ans ;
    }
};