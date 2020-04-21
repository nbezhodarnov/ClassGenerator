#ifndef CPLUSPLUSFACTORY_H
#define CPLUSPLUSFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "CPlusPlusClasses/CPlusPlusClassUnit.h"
#include "CPlusPlusClasses/CPlusPlusMethodUnit.h"
#include "CPlusPlusClasses/CPlusPlusPrintOperatorUnit.h"

// Конкретный класс, создающий объекты для генерации кода на языке программирования C++
class CPlusPlusFactory: public AbstractFactory {
public:
    ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags, Unit::Flags) const {
        return new CPlusPlusClassUnit(name); // создание объекта типа CPlusPlusClassUnit
    }
    MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return new CPlusPlusMethodUnit(name, returnType, flags); // создание объекта типа CPlusPlusMethodUnit
    }
    PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const {
        return new CPlusPlusPrintOperatorUnit(text); // создание объекта типа CPlusPlusPrintOperatorUnit
    }
    ~CPlusPlusFactory() {} // деструктор
};

#endif // CPLUSPLUSFACTORY_H
