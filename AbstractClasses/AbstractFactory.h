#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "AbstractClasses/ClassUnit.h"
#include "AbstractClasses/MethodUnit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

// определение статического массива
const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "internal", "protected internal", "private protected"};

// Абстрактный класс AbstractFactory, используемый для создания объектов типов, наследуемых от ClassUnit, MethodUnit, PrintOperatorUnit
class AbstractFactory {
public:
    virtual ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags accessFlags = 0, Unit::Flags modificatorFlags = 0) const = 0; // функция создания объектов типа, наследуемого от ClassUnit
    virtual MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0; // функция создания объектов типа, наследуемого от MethodUnit
    virtual PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const = 0; // функция создания объектов типа, наследуемого от PrintOperatorUnit
    virtual ~AbstractFactory() {} // виртуальный деструктор
};

#endif // ABSTRACTFACTORY_H
