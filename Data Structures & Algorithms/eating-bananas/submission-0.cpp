class Solution {
public:

    int isvalid(int mid , vector<int>&piles){

        int count = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            int pile = piles[i];
            count += (pile + mid - 1) / mid;
        }

        return count ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(isvalid(mid , piles) <= h){
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
