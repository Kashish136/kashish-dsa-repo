class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int output = INT_MIN;
        int low = 0;
        int high = heights.size();

        while( low <= high){

            int area = min(heights[low] , heights[high])*(high-low);
            output = max(area , output);



            if(heights[low] <= heights[high]){
                low++;
            }

            else{
                high--;
            }


        }


        return area;
    }
};
