#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    //wprowadzanie wymiarow lotniska i ilosci pasow
    int n, m;
    cin >> n >> m;
    
    const int MAXN = 1500;
    char plan[MAXN][MAXN];
    
    //wprowadzanie planu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> plan[i][j];
        }
    }
    
    int len = 0, k = 0, llXH = 0, llYH = 0, llXV = 0, llYV = 0, clX = 0, clY = 0;
    int lls[2][2];
    
    //sprawdzanie pol
    for (int M = 0; M < m; M++) {
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                clX = j;
                clY = i;
                
                if (k != 0) {
                    
                    // horyzontalnie
                    len = 0;
                    while (clX < n && plan[i][clX] == '.' && len <= k) {
                        len++;
                        clX++;
                    }
                    if (len >= lls[M][0]) {
                        lls[M][0] = len;
                        llXH = j;
                        llYH = i;
                    }
                    
                    // wertykalnie
                    len = 0;
                    while (clY < n && plan[clY][j] == '.' && len <= k) {
                        len++;
                        clY++;
                    }
                    if (len >= lls[M][1]) {
                        lls[M][1] = len;
                        llXV = j;
                        llYV = i;
                    }
                } else {
                    // horyzontalnie
                    len = 0;
                    while (clX < n && plan[i][clX] == '.') {
                        len++;
                        clX++;
                    }
                    if (len >= lls[M][0]) {
                        lls[M][0] = len;
                        llXH = j;
                        llYH = i;
                    }
                    
                    // wertykalnie
                    len = 0;
                    while (clY < n && plan[clY][j] == '.') {
                        len++;
                        clY++;
                    }
                    if (len >= lls[M][1]) {
                        lls[M][1] = len;
                        llXV = j;
                        llYV = i;
                    }
                }
            }
        }
        
        if ((lls[M][0] > lls[M][1] || lls[M][0] == lls[M][1]) && (lls[M][0] != 0 && lls[M][1] != 0)) {
            k = lls[M][0];
            for (int i = 0; i < lls[M][0]; i++) {
                plan[llYH][llXH+i] = 'q';
            }
        } else if (M == 1 && lls[M][0] == 0 && lls[M-1][0] == n) {
            int midpoint = n / 2;
            k = midpoint;
        } else if (M == 1 && lls[M][1] == 0 && lls[M-1][1] == n) {
            int midpoint = n / 2;
            k = midpoint;
        } else {
            k = lls[M][1];
            for (int i = 0; i < lls[M][1]; i++) {
                plan[llYV+i][llXV] = 'q';
            }
        }
    }
    
//    //wypisywanie planu
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << plan[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << k << "\n";

    return 0;
}
