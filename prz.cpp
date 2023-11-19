#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    //wprowadzanie rozmiaru planszy i ilosci przyciskow
    int n, m;
    cin >> n >> m;
    int plansza[n][n];
    int R_count[n], C_count[n];
    int parzystosci[n][2];
    int wcisniete = 0;
    int wcisniete_map[n][n];
    int wcisniete_tab[m];
    
    //ustalanie pozycji przyciskow
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            plansza[i][j] = 0;
            wcisniete_map[i][j] = 0;
        }
        R_count[i] = 0;
        C_count[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        wcisniete_tab[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        plansza[r-1][c-1] = 1;
        wcisniete_map[r-1][c-1] = i+1;
        R_count[r-1]++;
        C_count[c-1]++;
    }
    
    //szukanie ktore wcisnac
    for (int i = 0; i < n; i++) {
        parzystosci[i][0] = R_count[i] % 2;
        parzystosci[i][1] = C_count[i] % 2;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (parzystosci[i][0] == 0 && plansza[i][j] == 1) {
                plansza[i][j] = 2;
                wcisniete++;
                wcisniete_tab[wcisniete-1] = wcisniete_map[i][j];
            } else if (parzystosci[i][1] == 0 && plansza[j][i] == 1) {
                plansza[j][i] = 2;
                wcisniete++;
                wcisniete_tab[wcisniete-1] = wcisniete_map[j][i];
            } else if (parzystosci[i][0] > 0 && plansza[i][j] == 1 && plansza[i+1][j] == 1) {
                plansza[i+1][j] = 2;
                wcisniete++;
                wcisniete_tab[wcisniete-1] = wcisniete_map[i+1][j];
            } else if (parzystosci[i][1] > 0 && plansza[j][i] == 1 && plansza[j+1][i] == 1) {
                plansza[j+1][i] = 2;
                wcisniete++;
                wcisniete_tab[wcisniete-1] = wcisniete_map[j+1][i];
            }
        }
    }
    
    //wypisywanie wyniku
    if (wcisniete > 0) {
        cout << "TAK\n" << wcisniete << "\n";
        for (int i = 0; i < m; i++) {
            if (wcisniete_tab[i] > 0) {
                cout << wcisniete_tab[i] << " ";
            }
        }
    } else {
        cout << "NIE";
    }
    
    return 0;
}

/*
3 6
1 1
1 2
2 2
3 1
3 2
3 3
*/
