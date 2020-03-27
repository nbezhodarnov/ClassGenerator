#ifndef CPLUSPLUSFACTORY_H
#define CPLUSPLUSFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "CPlusPlusClasses/CPlusPlusClassUnit.h"
#include "CPlusPlusClasses/CPlusPlusMethodUnit.h"
#include "CPlusPlusClasses/CPlusPlusPrintOperatorUnit.h"

class CPlusPlusFactory: public AbstractFactory {
public:
    ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags, Unit::Flags) const {
        return new CPlusPlusClassUnit(name);
    }
    MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return new CPlusPlusMethodUnit(name, returnType, flags);
    }
    PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const {
        return new CPlusPlusPrintOperatorUnit(text);
    }
    ~CPlusPlusFactory() {}
};

#endif // CPLUSPLUSFACTORY_H
