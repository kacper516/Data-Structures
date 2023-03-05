#include "patterns.hpp"

void naiveStringMatching(std::string T, std::string p) // algorytm naiwny
{
    int i;
    for (int s = 0; s <= T.size() - p.size(); s++)
    {
        i = 0;
        while (i < p.size() && p[i] == T[s + i])
            i++;

        if (i == p.size())
            std::cout << "We find pattern with shift value: " << s << std::endl;
    }
}

bool compare(std::string p, std::string T, int s)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] != T[s + i])
            return false;
    }
    return true;
}

void RabinKarp(std::string T, std::string p)
{
    int hp = 0, ht = 0;
    int j = p.size() - 1;

    for (int i = 0; i < p.size(); i++)
    {
        hp = hp + pow(2, j) * p[i];
        j--;
    }

    j = p.size() - 1;
    for (int i = 0; i < p.size(); i++)
    {
        ht = ht + pow(2, j) * T[i];
        j--;
    }

    for (int s = 0; s <= T.size() - p.size(); s++)
    {
        if (hp == ht)
        {
            bool match = compare(p, T, s);
            if (match == true)
                std::cout << "We find pattern with shift value: " << s << std::endl;
        }
        if (s <= T.size() - p.size())
            ht = (ht - T[s] * pow(2, p.size() - 1)) * 2 + T[s + p.size()];
    }
}

void BoyerMoore(std::string T, std::string p)
{
    int s = 0;
    int bc[256]; // 256 because it's ASCII array

    // we fill bc array
    for (int i = 0; i < 256; i++)
        bc[i] = -1;

    for (int i = 0; i < p.size() - 1; i++)
        bc[p[i]] = i;

    while (s <= T.size() - p.size())
    {
        // we check if we find pattern
        int i = p.size() - 1;
        while (i >= 0 && p[i] == T[s + i])
            i--;

        if (i == -1) // we find pattern on shift value s
        {
            std::cout << "We find pattern with shift value: " << s << std::endl;
            s++;
        }
        else // we don't find pattern we needd to count the value of new shift
        {
            if (bc[T[s + i]] == -1) // 1st case
                s = s + i + 1;
            else if (bc[T[s + i]] < i) // 2nd case
                s = s + i - bc[T[s + i]];
            else // 3rd case
                s++;
        }
    }
}
