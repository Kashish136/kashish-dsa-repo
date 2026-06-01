class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {



        int n = gas.size();
        
        for( int i = 0 ; i < n ; i++){

         bool possible = true;
         int total = 0

        for( int j = 0 ; j < n ; j++){

            int key = gas[((j+i)%n)];
            int value = cost[((j+i)%n)];
            total += (key-value);
            if(total < 0){
                possible = false;
                break;
            }
        }

        if(possible == true){
            return i;
        }
    }

    return -1;
    }
};
