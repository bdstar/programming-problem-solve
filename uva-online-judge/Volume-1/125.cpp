//27392254	125	Numbering Paths	Accepted	C++11	0.000	2022-04-08 08:29:42
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 30;

int main()
{
    int street, tc = 0;

    while(scanf("%d", &street) != EOF) {
        int u, v, n = 0, mat[MAXN][MAXN] = {0};

        while(street--) {
            scanf("%d %d", &u, &v);

            mat[u][v] = 1;
            n = max(n, max(u, v));
        }
        ++n;

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] += mat[i][k] * mat[k][j];

        for(int k = 0; k < n; ++k)
            if(mat[k][k] != 0)
                for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                        if(mat[i][k] && mat[k][j])
                            mat[i][j] = -1;

        printf("matrix for city %d\n", tc++);

        for(int i = 0; i < n; ++i) {
            printf("%d", mat[i][0]);

            for(int j = 1; j < n; ++j)
                printf(" %d", mat[i][j]);

            putchar('\n');
        }
    }

    return 0;
}