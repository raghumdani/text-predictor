#include "editdistance.h"
#include <string>
#include <algorithm>

EditDistance::EditDistance() {
    //Do Nothing
}

EditDistance::EditDistance(std::string A, std::string B) {
    int M = A.size(), N = B.size();
    E = new int*[M + 1];
    sizI = M; sizJ = N;
    for(int i = 0; i <= M; ++i) {
        E [i] = new int[N + 1];
    }
    for(int j = 0; j <= N; ++j) {
        E [0][j] = j;
    }
    for(int i = 1; i <= M; ++i) {
        E [i][0] = i;
        for(int j = 1; j <= N; ++j) {
            if(A[i-1] == B[j-1]) {
                E [i][j] = std::min(E [i-1][j] + 1, std::min(E [i][j-1] + 1,E [i-1][j-1]));
            }
            else {
                E [i][j] = std::min(E [i-1][j] + 1,std::min(E [i][j-1] + 1, E [i-1][j-1] + 1));
            }
        }
    }
    edit_dist = E [M][N];
}

EditDistance::~EditDistance()
{
    for(int i = 0; i <= sizI; ++i) {
        delete [] E [i];
    }
}

int EditDistance::getDistance() {
    return edit_dist;
}
