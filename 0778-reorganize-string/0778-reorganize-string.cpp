class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> freq;
        for(char c : s){
            freq[c]++;
        }
        priority_queue<pair<int , char>> pq;

        for(auto& [c, cnt] : freq){
            pq.push({cnt , c});
            
        }

        string result ="";
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [count, c] = pq.top(); pq.pop();
            result += c;
            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = {count - 1, c};
        }
        return result.length() == s.length() ? result : "";
    }
};