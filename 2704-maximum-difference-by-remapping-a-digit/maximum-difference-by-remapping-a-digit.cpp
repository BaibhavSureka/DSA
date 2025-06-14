class Solution {
public:
    int minMaxDifference(int num) {
        // for max - mark starting digit as 9 
        // for min - mark strting digit as 0 

        string s = to_string(num); // converstion of num to string 

        int n = s.size(); // assign n as the size of string.
        string str = s; // creating cpy for finding min value string 

        char lessThanNine; // the first element which is lesser than 9 
        int  maxInd = 0, minInd = 0; // 
        
        for(int i = 0 ; i < n ; i++) {
            if(s[i] != '9') { // its the first char which is smaller than 9 so we made this 9 
                lessThanNine = s[i]; // mark for later updation 
                maxInd = i;
                break;
            }
        }

        for(int i = maxInd ; i < n ; i++)
            if(s[i] == lessThanNine) s[i] = '9';

        char b;
        for(int i = 0 ; i < n ; i++) { 
            if(str[i] != '0') {
                b = str[i];
                minInd = i;
                break;
            }
        }

        for(int i = minInd ; i < n ; i++)
            if(str[i] == b) str[i] = '0';
            
        int mini = stoi(str); // conversion of string back to int 
        int maxi = stoi(s); // conversion of string back to int 

        return maxi - mini;
        
    }
};