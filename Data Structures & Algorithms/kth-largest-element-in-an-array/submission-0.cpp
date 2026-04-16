class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        

        priority_queue<int,vector<int>,greater<int>>minHeap;

        // for finding the largest element we declare the minheap
        // which is the queue or element used for finding the smallest element 
        // in the array

        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
