#include <cstdlib>
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime=customers[0][0]+customers[0][1];
        double waitingTime=customers[0][1];
        for(int i=1;i<customers.size();i++){
            if(totalTime<customers[i][0])
                totalTime+=(customers[i][0]-totalTime);
            waitingTime+=totalTime-customers[i][0]+customers[i][1];
            totalTime+=customers[i][1] ;
        }
return waitingTime/customers.size();
        
    }
};