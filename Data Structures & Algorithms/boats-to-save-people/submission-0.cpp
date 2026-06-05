class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        

        sort(nums.begin() , nums.end());
        int count = 1;
        int n = people.size();
        int weight = 0;
        int currentcount = 0;

        for(int i = 0 ; i < n ; i++){
            int num = people[i];
            if(weight + num <= limit && currentcount < 2){
                weight += num[i];
                currentcount++;
            }

            else{
                count++;
                weight = 0;
                currentcount = 0;
            }

            
        }

        return count;
    }
};