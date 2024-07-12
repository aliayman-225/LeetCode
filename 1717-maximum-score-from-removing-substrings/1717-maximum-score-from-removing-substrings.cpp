class Solution {
public:
    int maximumGain(string s, int x, int y) {
int maxPoints = 0;

    // Determine the more valuable operation
    if (x > y) {
        // First remove all "ab" substrings
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                maxPoints += x;
            } else {
                st.push(c);
            }
        }

        // Collect the remaining string
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Now remove all "ba" substrings from the remaining string
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                maxPoints += y;
            } else {
                st.push(c);
            }
        }
    } else {
        // First remove all "ba" substrings
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                maxPoints += y;
            } else {
                st.push(c);
            }
        }

        // Collect the remaining string
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Now remove all "ab" substrings from the remaining string
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                maxPoints += x;
            } else {
                st.push(c);
            }
        }
    }

    return maxPoints;
    }
};