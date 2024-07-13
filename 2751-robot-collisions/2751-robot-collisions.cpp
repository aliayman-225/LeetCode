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

    bool allCharactersEqual(const string& str, int start, int end) 
    { //function compares if all characters in a substring are equal
        for (int i = start + 1; i < end; ++i) {
            if (str[i] != str[start]) 
                return false;
        }
        return true;
    }

    bool compareHalves(const string& str) 
    { //function compares if all characters in two halves substring are equal
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
    {//function compares if all subelements in a vector are equal
        for (int i = start + 1; i < end; ++i) {
            if (vec[i] != vec[start]) {
                return false;
            }
        }
        return true;
    }
    bool compareHalves(const vector<int>& vec) 
    {//function compares if all subelements in two halves vector are equal
    int len = vec.size();
        if (len % 2 != 0) {
            return false; 
        }
        int mid = len / 2;
        if (!allElementsEqual(vec, 0, mid)) 
          return false;
        if (!allElementsEqual(vec, mid, len)) 
          return false;
        return true;
    }


    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        bool sameDirection=true; 
        for(int i=0;i<directions.size()-1;i++)//check if all robots moves in the same direction
        {
            if(directions[i]!=directions[i+1])
            {
               sameDirection=false; 
               break;
            }
        }

        if(sameDirection)//if all robots moves in the same direction no one will collide
            return healths;
        if( (directions.substr(0,directions.length()/2)==directions.substr(directions.length()/2,directions.length()/2) || (compareHalves(directions) && directions.size()!=2)) && compareHalves(healths) && is_sorted(positions.begin(), positions.end()))// if each robot moves towards the other robot as every robot in the board line face the other with the same health so no one will survive in the board line
            return {};
        if(compareHalves(healths) && healths[0]=='L' && healths[(healths.size()/2) -1]=='R')// if half of the robot moves left and the other half moves right so no one will collide
            return healths;
        vector<Robot> boardLine;
        vector<int> result;
        for(int i=0;i<positions.size();i++)
        {
            Robot r(positions[i],healths[i],directions[i],i);
            boardLine.push_back(r);
        }
        sort(boardLine.begin(), boardLine.end(), [](const Robot& lhs, const Robot& rhs) {
            return lhs.position < rhs.position;
        }); //sorting robots in the board line according to its position

        for(int i=0;i<boardLine.size()-1;i++)
        {
            if(boardLine.size()==1)
                break;
            if(boardLine[i].direction==boardLine[i+1].direction) //if the robot moves in the same way that the next robot moves then skip it
                continue;
            else if(boardLine[i].direction!=boardLine[i+1].direction && boardLine[i].direction=='R')
            {//if the robot moves in the opposite way that the next robot moves & toward each other
                if(boardLine[i].health==boardLine[i+1].health)
                {//if they have the same health remove both of them
                        boardLine.erase( std::next(boardLine.begin(), i),std::next(boardLine.begin(),i+2) );
                    if (i==0)
                        i--; //redirect to the prev robot
                    else
                        i-=2;//redirect to the prev robot
                }     
                else if(boardLine[i].health>boardLine[i+1].health)
                {//if they have different health remove the weakest and decrement the strongest by one
                    boardLine[i].health--; 
                    boardLine.erase(next(boardLine.begin(), i+1));
                    if (i==0)
                        i--;//redirect to the prev robot
                    else
                        i-=2;//redirect to the prev robot
                }
                else if(boardLine[i].health<boardLine[i+1].health)
                {//if they have different health remove the weakest and decrement the strongest by one
                    boardLine[i+1].health--;
                    boardLine.erase(next(boardLine.begin(), i));
                    if (i==0)
                        i--;//redirect to the prev robot
                    else
                        i-=2;//redirect to the prev robot

                }
            }
        }
        sort(boardLine.begin(), boardLine.end(), [](const Robot& lhs, const Robot& rhs) {
            return lhs.index < rhs.index;
        });//sorting robots by index to send the results as the same order of the input 
        for(int i=0;i<boardLine.size();i++)
            result.push_back(boardLine[i].health);
        return result;
    }
};