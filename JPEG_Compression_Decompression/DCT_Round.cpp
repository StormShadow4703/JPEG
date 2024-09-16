#include "Zigzag.cpp"
#define PI 3.14159265358979323846
const int N = 8;

double dct[N][N];

void dctTransform(double submatrix[N][N], double dct[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double ci = (i == 0) ? 1 / sqrt(N) : sqrt(2) / sqrt(N);
            double cj = (j == 0) ? 1 / sqrt(N) : sqrt(2) / sqrt(N);
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    sum += submatrix[k][l] * cos((2 * k + 1) * i * PI / (2 * N)) * cos((2 * l + 1) * j * PI / (2 * N));
                }
            }
            dct[i][j] = round(ci * cj * sum);
        }
    }

    Zigzag(dct);
}
