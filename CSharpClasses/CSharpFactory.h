#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "CSharpClasses/CSharpClassUnit.h"
#include "CSharpClasses/CSharpMethodUnit.h"
#include "CSharpClasses/CSharpPrintOperatorUnit.h"

// Конкретный класс, создающий объекты генерации кода на языке программирования C#
class CSharpFactory: public AbstractFactory {
public:
    ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags flags = ClassUnit::PRIVATE, Unit::Flags = 0) const {
        return new CSharpClassUnit(name, flags); // создание объекта типа CSharpClassUnit
    }
    MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return new CSharpMethodUnit(name, returnType, flags); // создание объекта типа CSharpMethodUnit
    }
    PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const {
        return new CSharpPrintOperatorUnit(text); // создание объекта типа CSharpPrintOperatorUnit
    }
    ~CSharpFactory() {} // деструктор
};

#endif // CSHARPFACTORY_H
