class Solution {
public:
    int minOperations(vector<string>& logs) {
        int minResult=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i][0]!='.')
                minResult++;
            else if(logs[i][0]=='.' && logs[i][1]=='.' && minResult!=0)
                minResult--; 
        }
        return minResult;  
    }
};