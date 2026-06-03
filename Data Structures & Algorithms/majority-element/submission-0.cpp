class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        int element ;

        for( int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            if(count == 0){
                count++;
                element = nums[i]
            }

            else if(element == nums[i]){
                count++;
            }

            else{
                count--;
            }
        }

        int value = element;
        int count2 = 0;

        for( int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == value){
                count2++;
            }
        }

        if(count2 > nums.size()/2){
            return value;
        }

        return -1;
    }
};