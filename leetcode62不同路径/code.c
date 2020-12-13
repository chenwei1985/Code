int uniquePaths(int m, int n){
    if (m <= 0 || n <= 0) {
        return 0;
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    int data[m][n];
    int i = 0;
    int j = 0;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; j++) {
            if (i == 0) {
                data[i][j] = 1;
            } else {
                if (j == 0) {
                    data[i][j] = 1;
                } else {
                    data[i][j] = data[i][j - 1] + data[i - 1][j];
                }
            }
        }
    }
    return data[m-1][n-1];
}