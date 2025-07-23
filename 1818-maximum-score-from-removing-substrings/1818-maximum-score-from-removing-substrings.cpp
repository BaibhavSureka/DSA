class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char &ch : s) {
                if (ch == 'a') ch = 'b';
                else if (ch == 'b') ch = 'a';
            }
        }
        
        int score = 0;
        stack<char> st;

        // First pass: remove "ab"
        for (char ch : s) {
            if (!st.empty() && st.top() == 'a' && ch == 'b') {
                st.pop();
                score += x;
            } else {
                st.push(ch);
            }
        }

        // Second pass: remove "ba"
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char ch : remaining) {
            if (!st.empty() && st.top() == 'b' && ch == 'a') {
                st.pop();
                score += y;
            } else {
                st.push(ch);
            }
        }

        return score;
    }
};
