#include <iostream>

namespace Student{
    struct Student {
        std::string name;
        int group;
        int age;
    };
    void print(Student s)
    {
        std::cout << s.name << ' '
                  << s.group << ' '
                  << s.age << std::endl;
    }
}

namespace Teacher{
    struct Teacher {
        std::string name;
        int age;
    };
    void print(Teacher t)
    {
        std::cout << t.name << ' '
                  << t.age << std::endl;
    }
}

int main()
{
    std::cout << "Hello user!" << std::endl;
    using namespace Student;

    Student::Student a = {"Arthur", 13335/1, 22};
    Student::Student b = {"Nikita", 13335/1, 18};
    Student::print(a);
    Student::print(b);

    Teacher::Teacher t = ("Dmitry Sergeevich", 37);
    print(t);
    return 0;
}
