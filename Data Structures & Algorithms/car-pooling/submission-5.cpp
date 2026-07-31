class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        

        sort(trips.begin() , trips.end());

        int lastposition = -1;
        int count = 0;

        for(int i = 0 ; i < trips.size() ; i++){
            int people = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            if(lastposition == -1){
                lastposition = to;
                count += people;

                if(people > capacity){
                    return false ;
                }
            }

            else{

                if(from <= lastposition){
                    count += people;

                    if(people > capacity){
                        return false ;
                    }
                }
            }



        }

        return true ;
    }
};