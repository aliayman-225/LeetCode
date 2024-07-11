class Solution {
public:
    string reverseParentheses(string s) {
        string newString=s;
        string subString="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')' && subString.length()==0)
            {
                for(int j=i;j>=0;j--)
                {
                    if(s[j]!='(' &&s[j]!=')')
                        subString+=(s[j]);
                    else if (s[j]!='(' && s[j]==')' && s[j-1]=='(')
                    {
                        newString.erase(j-1,2);
                        subString="()";
                        break;
                    }
                    else if(s[j]!='(' &&s[j]==')')
                    {
                       subString+=(s[j-1]); 
                       j--;
                    } 
                    else{
                        newString.erase(j, subString.length()+2);
                        newString.insert(j,subString);
                        break;
                    }
                }
            }
            else if(subString.length()!=0)
                break;
        }
        if(newString.find('(')!=string::npos)
            return reverseParentheses(newString);
        else
            return newString;      
    }
};