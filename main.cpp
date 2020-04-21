#include <QCoreApplication>
#include <iostream>

#include "generateProgram.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl; // вывод класса
    return 0;
    //return a.exec();
}
