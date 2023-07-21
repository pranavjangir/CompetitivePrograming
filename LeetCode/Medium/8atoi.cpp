#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr char WHITESPACE = ' ';
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

int getSign(const string& s) {
    if (s.empty()) {
        return 0;
    }
    if (s[0] == '-') {
        return -1;
    }
    return 1;
}


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(s[i] == ' '){ // skipping space characters at the beginning
            i++;
        }

        int positive = 0, negative = 0; 

        if(s[i] == '+'){
            positive++; // number of positive signs at the start in string
            i++;
        }

        if(s[i] == '-'){
            negative++; // number of negative signs at the start in string
            i++;
        }

        double ans = 0; 

        while(i<n and s[i] >= '0' and s[i] <= '9'){
            ans = ans*10 + (s[i] - '0'); // (s[i] - '0') is converting character to integer
            i++;
        }

        if(negative > 0) // if negative sign exist
            ans = -ans;
        if(positive > 0 and negative > 0) // if both +ve and -ve sign exist, Example: +-12
            return 0;

        if(ans > INT_MAX) // if ans > 2^31 - 1
            ans = INT_MAX;

        if(ans < INT_MIN) // if ans < 2^31
            ans = INT_MIN;

        return (int)ans;
    }
};