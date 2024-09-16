#include <bits/stdc++.h>
#include "RLE.cpp"

#define ROW 8
#define COL 8

void Zigzag(double matrix[ROW][COL]) {
    vector<int> diagonal;
    vector<int> ans;

    for (int line = 1; line <= (ROW + COL - 1); line++) {
        int start_col = max(0, line - ROW);
        int count = min({line, (COL - start_col), ROW});
        diagonal.clear();
        
        for (int j = 0; j < count; j++) {
            diagonal.push_back(matrix[min(ROW, line) - j - 1][start_col + j]);
        }
        
        if (line % 2 != 0) {
            reverse(diagonal.begin(), diagonal.end());
        }

        for (int val : diagonal) {
            ans.push_back(val);
        }
    }
    runLengthEncode(ans);
}
