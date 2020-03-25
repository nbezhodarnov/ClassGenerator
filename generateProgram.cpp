#include <memory>

#include "CPlusPlusClasses/CPlusPlusFactory.h"

std::string generateProgram() {
    std::shared_ptr<AbstractFactory> factory(new CPlusPlusFactory());
    std::shared_ptr<ClassUnit> myClass(factory->CreateClassUnit("MyClass"));
    myClass->add(std::shared_ptr<MethodUnit>(factory->CreateMethodUnit("testFunc1", "void", 0)), ClassUnit::PUBLIC);
    myClass->add(std::shared_ptr<MethodUnit>(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC)), ClassUnit::PRIVATE);
    myClass->add(std::shared_ptr<MethodUnit>(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST)), ClassUnit::PUBLIC);
    auto method = std::shared_ptr<MethodUnit>(factory->CreateMethodUnit("testFunc4", "void", MethodUnit::STATIC));
    method->add(std::shared_ptr<PrintOperatorUnit>(factory->CreatePrintOperatorUnit(R"(Hello, world!\n)")));
    myClass->add(method, ClassUnit::PROTECTED);
    return myClass->compile();
}
