class Solution {
public:
    int scoreOfString(string s) {
        int result=0;
        for(int i =0;i<s.length()-1;i++)
        {
            int temp1 = int(s[i]);
            int temp2 = int(s[i+1]);
            int tempResult=temp1-temp2;
            if(tempResult<0)
                tempResult*=-1;
            result+=tempResult;
        }
        return result;
        
    }
};