#include <bits/stdc++.h>

using namespace std;

int main() {
    int len_a, len_s;
    cin >> len_a >> len_s;
    vector<vector<pair<int, char>>> s(len_s);
    for (int i = 0; i < len_s; i++) {
        int a, b;
        char x;
        cin >> a >> b >> x;
        s[a].push_back({b, x});
    }

    for (int i = 0; i < len_s; i++) {
        for (auto j : s[i]) {
            cout << "( " << j.first << ", " << j.second << " ) ;";
        }
        cout << "\n";
    }


    return 0;
}
