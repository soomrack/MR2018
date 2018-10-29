#include <iostream>

namespace Student{
    struct Student {
        std::string name;
        int group;
        int age;
    };
    void print(Student s)
    {
        std::cout << s.name << ''
                  << s.group << ' '
                  << s.age << std::endl;
    }
}

int main()
{
    std::cout << "Hello user!" << std::endl;
    Student::Student a = {"Arthur", 13335/1, 22};
    Student::print(a);
    return 0;
}
