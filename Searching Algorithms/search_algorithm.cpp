#include "search_algorithm.hpp"

int linearSearch(int *S, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (S[i] == x)
            return i;
    return -1;
}

int binarySearch(int *S, int n, int x)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (S[mid] == x)
            return mid;
        else if (S[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

void init(int *S, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        S[i] = rand() % n;
}

void initSorted(int *S, int n)
{
    std::sort(S, S + n);
}

int interpolationSearch(int *S, int n, int x)
{
    int l = 0;
    int h = n - 1;
    while (l <= h && S[l] <= x && x <= S[h])
    {
        int i_sr = l + ((x - S[l]) * (h - l) / (S[h] - S[l]));
        if (S[i_sr] == x)
            return i_sr;
        else if (S[i_sr] > x)
            h = i_sr - 1;
        else
            l = i_sr + 1;
    }
    return -1;
}
