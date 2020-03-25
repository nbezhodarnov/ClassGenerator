#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

class AbstractFactory {
public:
    virtual ClassUnit* CreateClassUnit(const std::string& name) const = 0;
    virtual MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const = 0;
};

#endif // ABSTRACTFACTORY_H
