#include "hash_table.hpp"

hash_table::hash_table(int c)
{
    this->capacity = c;
    this->size = 0;
    this->T = new std::string[this->capacity];

    for (int i = 0; i < capacity; i++)
        T[i] = "NULL";
}

bool hash_table::empty()
{
    if (size == 0)
        return true;

    return false;
}

bool hash_table::full()
{
    if (size == capacity)
        return true;

    return false;
}

int hash_table::hashFunction(std::string s)
{
    int sum_letters = 0;

    // we need to travel of every letter and add them to sum (it'll use ASCII code, so we no need to cast it to int)
    for (int i = 0; i < s.size(); i++)
    {
        sum_letters += s[i];
    }

    return sum_letters % capacity; // it's value of hash
}

int hash_table::insert(std::string s)
{
    if (full())
    {
        std::cout << "We can't add more element." << std::endl;
        return INT_MAX;
    }

    // in this program we'll use open addressing method, linear sampling
    int hash = hashFunction(s); // hash of string s
    int collision = 0;          // number of collisions
    int attempt = 0;            // number of attempt

    // "NULL" is on index where there is no element before,
    // "FREE" is on index where we have element before but delete it
    while (T[(hash + attempt) % capacity] != "NULL" && T[(hash + attempt) % capacity] != "FREE")
    {
        // we increment attempt and collision if we don't find empty place
        attempt++;
        collision++;
    }

    size++;
    T[(hash + attempt) % capacity] = s;
    return collision;
}

void hash_table::del(std::string s)
{
    if (size == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return;
    }

    int hash = hashFunction(s);

    int attempt = 0; // we will increment this value to find s (if exist)
    while (T[(hash + attempt) % capacity] != s && T[(hash + attempt) % capacity] != "NULL" && attempt < capacity)
        attempt++;

    if (T[(hash + attempt) % capacity] == s)
    {
        // we need to make it possible to type new items under this index
        T[(hash + attempt) % capacity] = "FREE";
        size--;
        return;
    }
    else
    {
        std::cout << "There is no element: " << s << " in this array." << std::endl;
    }
}

std::string hash_table::search(std::string s)
{
    if (size == 0)
    {
        std::cout << "Array is empty" << std::endl;
        return "NULL";
    }

    int hash = hashFunction(s);

    int attempt = 0; // we will increment this value to find s (if exist)
    while (T[(hash + attempt) % capacity] != s && T[(hash + attempt) % capacity] != "NULL" && attempt < capacity)
        attempt++;

    if (T[(hash + attempt) % capacity] == s) // we find s value
    {
        return s;
    }
    else
    {
        std::cout << "There is no element: " << s << " in this array." << std::endl;
        return "NULL";
    }
}

int hash_table::search1(std::string s)
{
    if (empty())
    {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }

    // in this program we'll use open addressing method, linear sampling
    int hash = hashFunction(s); // hash of string s
    int collision = 0;          // number of collisions
    int attempt = 0;            // number of attempt

    while (T[(hash + attempt) % capacity] != "NULL" && attempt < capacity)
    {
        if (T[(hash + attempt) % capacity] == s)
            return collision; // if we find string we search for
        collision++;
        attempt++;
    }

    return collision; // if we don't find string s
}

std::ostream &operator<<(std::ostream &out, hash_table &ht)
{
    for (int i = 0; i < ht.capacity; i++)
    {
        if (ht.T[i] != "NULL" && ht.T[i] != "FREE")
            out << "T[" << i << "]=" << ht.T[i] << std::endl;
    }

    return out << std::endl;
}
