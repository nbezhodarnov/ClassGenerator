#include <QCoreApplication>
#include <iostream>

#include "generateProgram.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl;
    return 0;
    //return a.exec();
}
