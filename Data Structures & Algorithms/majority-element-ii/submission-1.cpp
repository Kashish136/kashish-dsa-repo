class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();

        for(int i = 0 ; i < nums.size() ; i++){

            int val = nums[i];
            if(count1 == 0 && val != element2){
                element1 = val;
                count1++;
            }

            else if(count2 == 0 && val != element1){
                element2 = val;
                count2++;
            }

            else if(val == element1){
                count1++;
            }
            else if(val == element2){
                count2++;
            }

            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        int mini = n/3+1;

        for(int i = 0 ; i < nums.size() ; i++){
            int val = nums[i];
            if(val == element1){
                count1++;
            }

            if(val == element2){
                count2++;
            }
        }


        vector<int>ans;
        if(count1 >= mini){
            ans.push_back(element1);
        }
        if(count2 >= mini){
            ans.push_back(element2);
        }

        sort(ans.begin() , ans.end());
        return ans ;
    }
};