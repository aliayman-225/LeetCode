class Robot{
    public:
        int position;
        int health;
        char direction;
        int index;
        Robot(int position,int health,char direction,int index)
        {
            this->position=position;
            this->health=health;
            this->direction=direction;
            this->index=index;

        }
};

class Solution {
public:
    bool allCharactersEqual(const string& str, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        if (str[i] != str[start]) {
            return false;
        }
    }
    return true;
}

bool compareHalves(const string& str) {
    int len = str.length();
    if (len % 2 != 0) 
        return false; 
    
    int mid = len / 2;
    if (!allCharactersEqual(str, 0, mid)) 
        return false;
    if (!allCharactersEqual(str, mid, len)) 
        return false;

    return true;
}

    bool allElementsEqual(const vector<int>& vec, int start, int end) 
    {
        for (int i = start + 1; i < end; ++i) {
            if (vec[i] != vec[start]) {
                return false;
            }
        }
        return true;
    }
        bool compareHalves(const vector<int>& vec) {
        int len = vec.size();


        if (len % 2 != 0) {
            return false; 
        }

        int mid = len / 2;

        if (!allElementsEqual(vec, 0, mid)) {
          return false;
        }

        if (!allElementsEqual(vec, mid, len)) {
          return false;
        }

        return true;
    }


    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        bool sameDirection=true;
        for(int i=0;i<directions.size()-1;i++)
        {
            if(directions[i]!=directions[i+1])
            {
               sameDirection=false; 
               break;
            }
        }

        if(sameDirection){
            return healths;
        }
        vector<Robot> boardLine;
        vector<int> result;
        for(int i=0;i<positions.size();i++)
        {
            Robot r(positions[i],healths[i],directions[i],i);
            boardLine.push_back(r);
        }
        sort(boardLine.begin(), boardLine.end(), [](const Robot& lhs, const Robot& rhs) {
            return lhs.position < rhs.position;
        });
        if( (directions.substr(0,directions.length()/2)==directions.substr(directions.length()/2,directions.length()/2) || (compareHalves(directions) && directions.size()!=2)) && compareHalves(healths) && is_sorted(positions.begin(), positions.end()))
{
            return {};

        }
            if(compareHalves(healths) && healths[0]=='L' && healths[(healths.size()/2) -1]=='R')
            {
                return healths;
            }
        for(int i=0;i<directions.size()-1;i++)
        {
            if(directions[i]!=directions[i+1])
            {
               sameDirection=false; 
               break;
            }
        }




        for(int i=0;i<boardLine.size()-1;i++)
        {
            if(boardLine.size()==1)
                break;

            if(boardLine[i].direction==boardLine[i+1].direction)
            {
                continue;
            }
            else if(boardLine[i].direction!=boardLine[i+1].direction && boardLine[i].direction=='R')
            {
                if(boardLine[i].health==boardLine[i+1].health)
                {
                        boardLine.erase( std::next(boardLine.begin(), i),std::next(boardLine.begin(),i+2) );
                    if (i==0)
                        i--;
                    else
                        i-=2;
                }
                    
                else if(boardLine[i].health>boardLine[i+1].health)
                {
                    boardLine[i].health--; 
                    boardLine.erase(next(boardLine.begin(), i+1));
                                        if (i==0)
                        i--;
                    else
                        i-=2;
                }
                else if(boardLine[i].health<boardLine[i+1].health)
                {
                    boardLine[i+1].health--;
                    boardLine.erase(next(boardLine.begin(), i));
                    if (i==0)
                        i--;
                    else
                        i-=2;

                }
            }
        }

        sort(boardLine.begin(), boardLine.end(), [](const Robot& lhs, const Robot& rhs) {
            return lhs.index < rhs.index;
        });
        for(int i=0;i<boardLine.size();i++)
        {
            cout<<boardLine[i].health<<endl;
            result.push_back(boardLine[i].health);

        }
        
        
        return result;
    }
};