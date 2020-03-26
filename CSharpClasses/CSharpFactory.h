#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "CSharpClasses/CSharpClassUnit.h"
#include "CSharpClasses/CSharpMethodUnit.h"
#include "CSharpClasses/CSharpPrintOperatorUnit.h"

class CSharpFactory: public AbstractFactory {
public:
    ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags flags = CSharpClassUnit::PRIVATE) const {
        return new CSharpClassUnit(name, flags);
    }
    MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return new CSharpMethodUnit(name, returnType, flags);
    }
    PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const {
        return new CSharpPrintOperatorUnit(text);
    }
};

#endif // CSHARPFACTORY_H
