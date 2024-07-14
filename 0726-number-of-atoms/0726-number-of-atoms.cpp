class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        int n = formula.size();
        std::stack<std::map<std::string, int>> stk;
        stk.push({});
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push({});
                ++i;
            } else if (formula[i] == ')') {
                std::map<std::string, int> top = stk.top();
                stk.pop();
                int j = i + 1, num = 0;
                while (j < n && isdigit(formula[j])) {
                    num = num * 10 + formula[j] - '0';
                    ++j;
                }
                num = num == 0 ? 1 : num;
                for (auto &p : top) {
                    stk.top()[p.first] += p.second * num;
                }
                i = j;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) ++j;
                std::string name = formula.substr(i, j - i);
                i = j;
                int num = 0;
                while (j < n && isdigit(formula[j])) {
                    num = num * 10 + formula[j] - '0';
                    ++j;
                }
                num = num == 0 ? 1 : num;
                stk.top()[name] += num;
                i = j;
            }
        }
        
        std::map<std::string, int> counts = stk.top();
        std::string result;
        for (auto &p : counts) {
            result += p.first;
            if (p.second > 1) result += std::to_string(p.second);
        }
        return result;
    }
};