#include "hash_table.cpp"

int main()
{
    /*
    hash_table table(10);

    std::cout<<"Table empty: "<<table.empty()<<std::endl;

    table.insert("a");
    table.insert("a");
    std::cout<<table;

    std::cout<<"Table full: "<<table.full()<<std::endl;
    std::cout<<"Table dell 'a' key, print new table: " <<std::endl;
    table.del("a");
    std::cout<<table;

    table.search("a");
    std::cout<<"Search for 'a' key, number of collisions: "<<table.search1("a")<<std::endl;

    table.del("a");
    std::cout<<"Trying to delete element from empty table: "<<std::endl;
    table.del("a");


    // dodajemy nowe wartości do testowania
    table.insert("Kacper");
    table.insert("Eryk");
    table.insert("Olszak");
    table.insert("Emilka");
    table.insert("Bartek");
    table.insert("Kasia");
    // tu wypisze tylko te 6 powyzszych
    std::cout<<table<<std::endl;
    table.insert("Kamil");
    table.insert("Kuba");
    table.insert("Ela");
    table.insert("Franek");
    std::cout<<table;
    table.insert("za duzo bedzie");

    std::cout<<"Search for 'Kamil' key, number of collisions: "<<table.search1("Kamil")<<std::endl;
    std::cout<<"search for 'Ela' key (without number of collisions): "<<table.search("Ela")<<std::endl;
    //zwroci wartosc 9, poniewaz przejdzie całą tablice i nie znajdzie
    std::cout<<"Search for 'Punia' key, with number of collisions: "<<table.search1("Punia")<<std::endl;
    table.del("Punia");
    table.del("Franek");
    //sprawdzimy teraz czy Franek jest jeszcze w naszej liście, zwróci 9 bo go nie znajdzie
    std::cout<<"Search for 'Franek' key, with number of collisions: "<<table.search1("Franek")<<std::endl;*/

    hash_table H(42);
    std::string names[] = {"Julia", "Zuzanna", "Zofia", "Lena", "Maja", "Hanna", "Amelia", "Alicja", "Maria", "Aleksandra", "Oliwia", "Natalia", "Wiktoria", "Emilia", "Antonina", "Laura", "Pola", "Iga", "Anna", "Liliana", "Antoni", "Jakub", "Jan", "Szymon", "Franciszek", "Filip", "Aleksander", "Mikolaj", "Wojciech", "Kacper", "Adam", "Michal", "Marcel", "Stanislaw", "Wiktor", "Piotr", "Igor", "Leon", "Nikodem", "Mateusz"};

    for (int i = 0; i < sizeof(names) / sizeof(std::string); i++)
    {
        H.insert(names[i]);
    }

    std::cout << H;
    std::cout << std::endl;

    std::cout << "Search: " << std::endl;
    std::cout << H.search("Iga") << std::endl;
    std::cout << H.search("Lena") << std::endl;
    std::cout << H.search("Julia") << std::endl;

    std::cout << std::endl;
    H.del("Julia");
    H.del("dz");

    std::cout << "Search1: " << std::endl;
    std::cout << H.search("Julia") << std::endl;
    std::cout << H.search1("Julia") << std::endl;
    std::cout << H.search1("Iga") << std::endl;
    std::cout << H.search1("Lena") << std::endl;
}