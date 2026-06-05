class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        

        sort(people.begin() , people.end());
        // int count = 1;
        // int n = people.size();
        // int weight = 0;
        // int currentcount = 0;

        // for(int i = 0 ; i < n ; i++){
        //     int num = people[i];
        //     if(weight + num > limit){
        //         count++;
        //         weight = num;
        //         currentcount = 1;
        //     }

        //     else if(currentcount == 2){
        //         count++;
        //         currentcount = 1;
        //         weight = num;
        //     }

        //     else{
        //         weight += num;
        //         currentcount++;
        //     }
            
        // }

        // return count;


        int left = 0;
        int right = people.size()-1;
        int ans = 0;
        
        

        while(left <= right){
            int remain = limit-people[right--];
            ans++;
            if(left <= right && remain >= people[left]){
                left++;
            }
        }

        return ans ;
    }
};