#include "CPlusPlusClasses/CPlusPlusFactory.h"
#include "CSharpClasses/CSharpFactory.h"
#include "JavaClasses/JavaFactory.h"

std::string generateProgram() {
    std::string result;
    AbstractFactory* factory;
    for (int i = 0; i < 3; i++){
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
        ClassUnit* myClass(factory->CreateClassUnit("MyClass"));
        myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
        myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
        myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
        Unit* method = factory->CreateMethodUnit("testFunc4", "void", MethodUnit::STATIC);
        method->add(factory->CreatePrintOperatorUnit(R"(Hello, world!\n)"));
        myClass->add(method, ClassUnit::PROTECTED);
        result += myClass->compile() + '\n';
        delete factory;
        delete myClass;
    }
    return result;
}
