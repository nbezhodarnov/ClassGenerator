#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "AbstractClasses/AbstractFactory.h"

#include "JavaClasses/JavaClassUnit.h"
#include "JavaClasses/JavaMethodUnit.h"
#include "JavaClasses/JavaPrintOperatorUnit.h"

// Конкретный класс, создающий объекты для генерации кода на языке программирования Java
class JavaFactory: public AbstractFactory {
public:
    std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name, Unit::Flags accessFlags = ClassUnit::PUBLIC, Unit::Flags modifierFlags = 0) const {
        return std::shared_ptr<ClassUnit>(new JavaClassUnit(name, accessFlags, modifierFlags)); // создаёт объект типа JavaClassUnit
    }
    std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return std::shared_ptr<MethodUnit>(new JavaMethodUnit(name, returnType, flags)); // создаёт объект типа JavaMethodUnit
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const {
        return std::shared_ptr<PrintOperatorUnit>(new JavaPrintOperatorUnit(text)); // создаёт объект типа JavaPrintOperatorUnit
    }
    ~JavaFactory() {} // деструктор
};

#endif // JAVAFACTORY_H
