#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "AbstractClasses/ClassUnit.h"
#include "AbstractClasses/MethodUnit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "internal", "protected internal", "private protected"};

class AbstractFactory {
public:
    virtual ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags flags = 0) const = 0;
    virtual MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const = 0;
    virtual ~AbstractFactory() {};
};

#endif // ABSTRACTFACTORY_H
