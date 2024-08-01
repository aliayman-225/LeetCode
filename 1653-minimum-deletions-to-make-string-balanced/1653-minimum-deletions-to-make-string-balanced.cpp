class Solution {
public:
    int minimumDeletions(string s) {
        int siz = s.size();
        int f[siz + 1];
        memset(f, 0, sizeof(f));
        int numb = 0;
        for (int i = 1; i <= siz; ++i) {
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1];
                ++numb;
            } else {
                f[i] = min(f[i - 1] + 1, numb);
            }
        }
        return f[siz];
    }
};
  