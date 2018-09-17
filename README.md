# MR2018

Приведите ваши личные CMakeLists.txt к виду:

> cmake_minimum_required(VERSION 3.9)
> project(!Название проекта!)
>
> set(CMAKE_C_STANDARD 11)
>
> add_executable(!Название проекта! !Имя файла с исходным кодом исполняемой функции!)
>
> add_library(!Наименование вашей библиотеки! STATIC !Имя с файлом библиотеки.с!)
>
> target_link_libraries(!Название проекта! !Наименование вашей библиотеки!)
