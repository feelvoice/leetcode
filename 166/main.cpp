#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    string fraction(long long n, long long d) {
        string ret;
        map<long long, int> m;
        vector<int> digit, remain;
        do {
            if (m.find(n) != m.end()) break;
            m[n] = 1;
            remain.push_back(n);
            n *= 10;
            digit.push_back(n / d);
            n %= d;
        } while (n);
        
        char buffer[16];
        if (n == 0) {
            for (int i=0; i<digit.size(); i++) {
                sprintf(buffer, "%d", digit[i]);
                ret += buffer;
            }
        }
        else {
            for (int i=0; i<digit.size(); i++) {
                if (n == remain[i]) ret += "(";
                sprintf(buffer, "%d", digit[i]);
                ret += buffer;
            }
            ret += ")";
        }
        return ret;
    }

    string myfractionToDecimal(long long numerator, long long denominator) {
        char buffer[128];
        bool positive = true;
        if (denominator < 0) {
            denominator = -denominator;
            positive = !positive;
        }
        if (numerator < 0) {
            numerator = -numerator;
            positive = !positive;
        }
        if (numerator == 0) positive = true;

        if (numerator % denominator == 0) {
            if (positive) {
                sprintf(buffer, "%lld", numerator / denominator);
            }
            else {
                sprintf(buffer, "-%lld", numerator / denominator);
            }
            
            return buffer;
        }
        string ret;
        int n = numerator / denominator;
        if (positive) {
            sprintf(buffer, "%d.", n);
        }
        else {
            sprintf(buffer, "-%d.", n);
        }
        ret += buffer;
        ret += fraction(numerator % denominator, denominator);
        return ret;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        return myfractionToDecimal(numerator, denominator);
    }
};

int main()
{
    Solution s = Solution();
    cout << s.fractionToDecimal(7, -6);
    return 0;
}