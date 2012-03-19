#include <iostream>
#include <cstring>

using namespace std;

#define MAX_CHAR    16

/*
 * Returns the Edit Distnace of two strings as described in
 * Problem 15-3 of CRLS, 2E
 */
int edit_distance(char *s, int s_len, char *t, int t_len)
{
    int d[MAX_CHAR + 1][MAX_CHAR + 1];
    int i;
    int j;

    memset(d, 0, sizeof(d));
    for (i = 0; i <= s_len; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= t_len; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= s_len; i++) {
        for (j = 1; j <= t_len; j++) {
            int dist = (s[i] == t[j]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,
                          min(d[i][j - 1] + 1, d[i - 1][j - 1] + dist));
        }
    }

#if 1
    for (i = 0; i <= s_len; i++) {
        for (j = 0; j <= t_len; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
#endif

    return d[s_len][t_len];
}

int main()
{
    char s[MAX_CHAR + 1];
    char t[MAX_CHAR + 1];

    memset(s, 0, MAX_CHAR + 1);
    memset(t, 0, MAX_CHAR + 1);

    cout << "Source string:" << endl;
    cin >> (s + 1);
    cout << "Target string:" << endl;
    cin >> (t + 1);

    cout << edit_distance(s, strlen(s + 1), t, strlen(t + 1)) << endl;

    return 0;
}
