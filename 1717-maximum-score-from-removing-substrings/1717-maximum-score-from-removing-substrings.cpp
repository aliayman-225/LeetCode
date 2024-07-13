class Solution {
public:
    int maximumGain(string s, int x, int y) {
    int maxPoints = 0;
    if (x > y) {
        stack<char> st;
        for (int i=0;i<s.length();i++) {
            if (!st.empty() && st.top() == 'a' && s[i] == 'b') {
                st.pop();
                maxPoints += x;
            } else {
                st.push(s[i]);
            }
        }
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (int i=0;i<remaining.length();i++) {
            if (!st.empty() && st.top() == 'b' && remaining[i] == 'a') {
                st.pop();
                maxPoints += y;
            } else {
                st.push(remaining[i]);
            }
        }
    } else {
        stack<char> st;
        for (int i=0;i<s.length();i++) {
            if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                maxPoints += y;
            } else {
                st.push(s[i]);
            }
        }

        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (int i=0;i<remaining.length();i++) {
            if (!st.empty() && st.top() == 'a' && remaining[i] == 'b') {
                st.pop();
                maxPoints += x;
            } else {
                st.push(remaining[i]);
            }
        }
    }

    return maxPoints;
    }
};