#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "JavaClasses/JavaClassUnit.h"
#include "JavaClasses/JavaMethodUnit.h"
#include "JavaClasses/JavaPrintOperatorUnit.h"

class JavaFactory: public AbstractFactory {
public:
    ClassUnit* CreateClassUnit(const std::string& name, Unit::Flags accessFlags = ClassUnit::PUBLIC, Unit::Flags modifierFlags = 0) const {
        return new JavaClassUnit(name, accessFlags, modifierFlags);
    }
    MethodUnit* CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return new JavaMethodUnit(name, returnType, flags);
    }
    PrintOperatorUnit* CreatePrintOperatorUnit(const std::string& text) const {
        return new JavaPrintOperatorUnit(text);
    }
    ~JavaFactory() {}
};

#endif // JAVAFACTORY_H
