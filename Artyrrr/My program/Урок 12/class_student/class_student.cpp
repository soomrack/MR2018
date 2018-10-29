#include <iostream>

struct Student {
    std::string name;
    int group;
    int age;

    void print()
    {
            std::cout << name << ' '
                  << group << ' '
                  << age << std::endl;
    }
};

struct Teacher {
    std::string name;
    int age;

    void print()
    {
        std::cout << name << ' '
                  << age << std::endl;
    }
};


int main()
{
    std::cout << "Hello user!" << std::endl;

    Student a = {"Arthur", 13335/1, 22};
    Student b = {"Nikita", 13335/1, 18};
    a.print();
    b.print()

    Teacher t = ("Dmitry Sergeevich", 37);
    t.print();
    return 0;
}
