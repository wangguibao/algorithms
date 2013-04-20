/*
 * POJ1274 - Perfect Stalls
 * Problem: 1274    User: LoiteringLeo
 * Memory: 748K     Time: 32MS
 * Language: G++    Result: Accepted
 *
 * Maximum bipartite matching.
 * http://comzyh.tk/blog/archives/148/
 */
#include <iostream>
#include <vector>

using namespace std;

const int max_cow = 201;
const int max_stall = 201;

vector<int> g[max_cow];
int pair_of_stall[max_stall];   /* Pair of each stall */
bool searched[max_stall];         /* false - cow not searched; true - cow searched */

bool augment_path(int u)
{
    for (unsigned int i = 0; i < g[u].size(); i++) {
        int stall = g[u][i];
        if (searched[stall] == false) {
            searched[stall] = true;
            if (pair_of_stall[stall] == -1 || augment_path(pair_of_stall[stall])) {
                pair_of_stall[stall] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    int m;

    while (cin >> n >> m) {
        int i;
        int j;
        int k;
        int stall;
        int count = 0;

        for (i = 1; i <= n; i++) {
            g[i].clear();
            cin >> k;
            for (j = 1; j <= k; j++) {
                cin >> stall;
                g[i].push_back(stall);
            }
        }

        for (i = 1; i <= m; i++) {
            pair_of_stall[i] = -1;
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                searched[j] = false;
            }

            if (augment_path(i) == true) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
