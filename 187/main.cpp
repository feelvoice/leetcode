class Solution {
public:

    int ton(char c) {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else if (c == 'T') return 3;
    }
    char toc(int n) {
        if (n == 0) return 'A';
        else if (n == 1) return 'C';
        else if (n == 2) return 'G';
        else if (n == 3) return 'T';
    }

    string n_to_str(int n) {
        string ret;
        for (int i=0; i<10; i++) {
            ret.append(1, toc(n % 4));
            n /= 4;
        }
        return ret;
    }

    int str_to_n(const string &s) {
        int ret = 0;
        for (int i=0; i<s.length(); i++) {
            ret = ret * 4 + ton(s[s.length()-1-i]);
        }
        return ret;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int len = s.length();
        if (len <= 10) return ret;
        
        map<int, int> m;
        for (int i=0; i<=len-10; i++) {
            string one = s.substr(i, 10);
            ++m[str_to_n(one)];
        }
        
        for (map<int, int>::iterator i=m.begin(); i!=m.end(); ++i) {
            if (i->second > 1) {
                ret.push_back(n_to_str(i->first));
            }
        }
        return ret;
    }
};