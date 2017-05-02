#include <algorithm>
#include <cassert>
#include <cstdio>

static int cnt = 0;

bool cmpLess(int a, int b)
{
    ++cnt;
    return a < b;
}

bool cmpGt(int a, int b)
{
    ++cnt;
    return a > b;
}

int main()
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    const int N = sizeof(A) / sizeof(int);
    const int logN = 3; // ln(N) rounded up

    std::stable_sort(A, A + N, cmpLess);
    printf("cmpLess=%d\n", cnt);
    assert(cnt <= N * logN * logN);
    
    //reset cnt
    cnt = 0;

    std::stable_sort(A, A + N, cmpGt);
    printf("cmpGt=%d\n", cnt);
    assert(cnt <= N * logN * logN);
}

