#include <iostream>
#include <time.h>

using namespace std;

int factorial(int i) {
    cout << "factorial(" << i << ")\n";
    if (i < 2) return 1;
    return i * factorial(i - 1);
}

int main() {
    int k;
    cin >> k;

    float start = clock();
    int ans = factorial(k);
    float end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    cout << ans << ", 걸린 시간 : " << duration << endl;
    return 0;
}