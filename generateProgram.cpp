#include "CPlusPlusClasses/CPlusPlusFactory.h"
#include "CSharpClasses/CSharpFactory.h"
#include "JavaClasses/JavaFactory.h"

// Функция генерация класса на разных языках программирования
std::string generateProgram() {
    std::string result;
    AbstractFactory* factory;
    for (int i = 0; i < 3; i++){ // создание конкретной фабрики (порядок: C++, C#, Java)
        switch (i) {
            case 0:
                factory = new CPlusPlusFactory();
                break;
            case 1:
                factory = new CSharpFactory();
                break;
            case 2:
                factory = new JavaFactory();
                break;
        }
        ClassUnit* myClass(factory->CreateClassUnit("MyClass")); // создание класса

        // создание функций в классе
        myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
        myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
        myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
        Unit* method = factory->CreateMethodUnit("testFunc4", "void", MethodUnit::STATIC);

        method->add(factory->CreatePrintOperatorUnit(R"(Hello, world!\n)")); // добавление оператора вывода в функцию
        myClass->add(method, ClassUnit::PROTECTED); // добавление функции в класс
        result += myClass->compile() + '\n'; // генерация класса
        delete factory;
        delete myClass;
    }
    return result;
}
