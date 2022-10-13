class Solution {
public:
    bool winnerOfGame(string colors) {
        array<int, 2> cnts = {0};
        char cur = colors[0]; int count = 0;
        
        for (const auto & c: colors) {
            if (c == cur) { 
                if (++count >= 3) cnts[c - 'A'] ++;
            } else { cur = c; count = 1; }
        }
        
        return cnts[0] > cnts[1];
    }
};
