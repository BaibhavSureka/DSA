class Solution {
public:
    string makeFancyString(string s) 
    {
        int n;
        string solution;
        for(auto &a:s)
        {
            n = solution.size();
            if(n > 1 and solution.back() == a and solution.back() == solution[n - 2])
            {
                continue;
            }
            solution += a;
        }
        return solution;
    }
};