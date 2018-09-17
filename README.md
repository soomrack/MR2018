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

Как пример можете глянуть мой файл:

> cmake_minimum_required(VERSION 3.9)
> project(Vlbager)
>
> set(CMAKE_C_STANDARD 11)
> 
> add_executable(Vlbager main.c)
> 
> add_library(Vlbagerlib STATIC mylibrary.c)
> 
> target_link_libraries(Vlbager Vlbagerlib)
