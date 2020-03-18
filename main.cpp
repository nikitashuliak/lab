#include <bits/stdc++.h>

using namespace std;

// TEST CASE
/*12 10
a b c d e f g h k l j i
0
0 a 1
0 b 2
1 c 3
2 d 3
2 j 2
3 e 4
4 g 6
5 f 4
2 k 6
6 h 7
6 i 8
9 l 9
*/
//

void bfs(const vector<vector<pair<int, char>>> & s, vector<pair<int, bool>> & used, int start, int n, vector<int> & unreach) {
    used[start].second = true;
    used[start].first++;
    queue<pair<int, char>> q;
    q.push({start, '['});
    while (!q.empty()){
        int u = q.front().first;
        q.pop();
        bool flag = false;
        for (int i = 0; i < (int)s[u].size(); i++) {
            if (!used[s[u][i].first].second) {
                flag = true;
                used[s[u][i].first].second = true;
                used[s[u][i].first].first++;
                q.push({s[u][i]});
            } else {
                if (used[s[u][i].first].first > 0) {
                    flag = true;
                }
            }
        }
        if (!flag) {
            unreach.push_back(u);
        }
    }
}



int main() {
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int len_a, len_s;
    cin >> len_a >> len_s;
    vector<char> alphabit(len_a);
    for (int i = 0; i < len_a; i++){
        cin >> alphabit[i];
    }
    int s0;
    cin >> s0;

    vector<vector<pair<int, char>>> s(len_s);
    int a, b;
    char wt;
    while (cin >> a >> wt >> b){
        if (find(alphabit.begin(), alphabit.end(), wt) == alphabit.end()){
            puts("A letter is not in alphabet.");
            return 0;
        }
        s[a].push_back(make_pair(b, wt));
    }
    vector<pair<int, bool>> used;
    for (int i = 0; i < len_s; i++) {
        used.push_back({0, false});
    }
    vector<int> unreach;

    bfs(s, used, s0, len_s, unreach);

    cout << "Dead-end nodes: ";
    for (int i = 0; i < (int)unreach.size(); i++) {
        cout << unreach[i] << ' ';
    }
    cout << "\nUnreachable nodes: ";
    for (int i = 0; i < len_s; i++) {
        if (!used[i].second) {
            cout << i << ' ';
        }
    }

    return 0;
}
