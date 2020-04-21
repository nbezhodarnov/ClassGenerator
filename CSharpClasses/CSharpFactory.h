#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "CSharpClasses/CSharpClassUnit.h"
#include "CSharpClasses/CSharpMethodUnit.h"
#include "CSharpClasses/CSharpPrintOperatorUnit.h"

// Конкретный класс, создающий объекты генерации кода на языке программирования C#
class CSharpFactory: public AbstractFactory {
public:
    std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name, Unit::Flags flags = ClassUnit::PRIVATE, Unit::Flags = 0) const {
        return std::shared_ptr<ClassUnit>(new CSharpClassUnit(name, flags)); // создание объекта типа CSharpClassUnit
    }
    std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return std::shared_ptr<MethodUnit>(new CSharpMethodUnit(name, returnType, flags)); // создание объекта типа CSharpMethodUnit
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const {
        return std::shared_ptr<PrintOperatorUnit>(new CSharpPrintOperatorUnit(text)); // создание объекта типа CSharpPrintOperatorUnit
    }
    ~CSharpFactory() {} // деструктор
};

#endif // CSHARPFACTORY_H
