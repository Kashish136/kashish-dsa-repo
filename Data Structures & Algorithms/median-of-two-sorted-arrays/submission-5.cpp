class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        int n = nums1.size();
        int m = nums2.size();
        int low = 0;
        int high = n-1;

      if(n > m)
      return findMedianSortedArrays(nums2, nums1);

        int length = (n+m+1)/2;

        while(low <= high){
            int cut1 = (low + (high-low)/2);
            int cut2 = length-cut1;

            int left1 = INT_MIN;
            int left2 = INT_MIN;
            int right1 = INT_MAX;
            int right2 = INT_MAX;

            if(cut1 != 0){
                left1 = nums1[cut1-1];
            }

            if(cut2 != 0){
                left2 = nums2[cut2-1];
            }

            if(cut1 != n){
                right1 = nums1[cut1];
            }

            if(cut2 != m){
                right2 = nums2[cut2];
            }


            if(left1 <= right2 && left2 <= right1){
                if(length%2 == 0){
                    return ((max(left1 , left2) + min(right1 , right2))/2.0);
                }
                else{
                    return (max(left1 , left2));
                }
            }

            else if(left1 > right2){
                low = cut1+1;
            }

            else{
                high = cut1-1;
            }
        }

        return 0.0;
    }
};
