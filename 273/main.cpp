class Solution {
public:
    string trans(int num) {
        map<int, const char *> m;
        m[0] = "Zero";
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[30] = "Thirty";
        m[40] = "Forty";
        m[50] = "Fifty";
        m[60] = "Sixty";
        m[70] = "Seventy";
        m[80] = "Eighty";
        m[90] = "Ninety";
        
        if (m.find(num) != m.end()) {
            return m[num];
        }
        char buffer[128];
        int digit;
        string ret;
        if (num >= 100) {
            digit = num / 100;
            num %= 100;
            if (ret != "") ret += " ";
            sprintf(buffer, "%s Hundred", m[digit]);
            ret += buffer;
        }
        if (num >= 20) {
            digit = num / 10 * 10;
            num %= 10;
            if (ret != "") ret += " ";
            ret += m[digit];
        }
        if (num > 0) {
            if (ret != "") ret += " ";
            ret += m[num];
        }
        return ret;
    }

    string numberToWords(int num) {
        string ret;
        int digit;
        if (num >= 1000000000) {
            digit = num / 1000000000;
            num %= 1000000000;
            if (ret != "") ret += " ";
            ret += trans(digit);
            ret += " Billion";
        }
        if (num >= 1000000) {
            digit = num / 1000000;
            num %= 1000000;
            if (ret != "") ret += " ";
            ret += trans(digit);
            ret += " Million";
        }
        if (num >= 1000) {
            digit = num / 1000;
            num %= 1000;
            if (ret != "") ret += " ";
            ret += trans(digit);
            ret += " Thousand";
        }
        if (num > 0) {
            if (ret != "") ret += " ";
            ret += trans(num);
        }
        else {//0
            if (ret == "") ret = trans(num);
        }
        return ret;
    }
};