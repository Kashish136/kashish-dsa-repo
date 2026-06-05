class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        deque<int>dq;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){

            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && dq.back() <= nums[i]){
                dq.pop_back();
            }

            if( i >= k-1){
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans ;
    }
};
