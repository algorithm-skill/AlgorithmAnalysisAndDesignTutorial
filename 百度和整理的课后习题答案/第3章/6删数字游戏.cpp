//https://blog.csdn.net/yuanxu716/article/details/72974373
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    string s;
    while (cin >> s >> k) {
        if (k > s.size()) {
            cout << "Invalid Input.";
            continue;
        }
        while (k) {
            int i;
            for (i = 0; i < s.size() - 1 && s[i] <= s[i + 1]; i++);
            s.erase(i, 1);
            k--;
 
        }
        if (s.empty()) {
            cout << 0 << endl;
            continue;
        }
 
        int i = 0;
        for (i = 0; i < s.size()-1;) {
            if (s[i] == '0') i++;
            else break;
        }
        cout << s.substr(i) << endl;
    }
}