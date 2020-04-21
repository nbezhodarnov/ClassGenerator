#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <list>

#include "AbstractClasses/Unit.h"

// Абстрактный класс MethodUnit, используемый для генерации функций
class MethodUnit: public Unit {
public:
    enum Modifier { // модификаторы функций
        STATIC       = 1, //C++, C#, Java
        CONST        = 2, //C++, C#, Java
        VIRTUAL      = 4, //C++, C#
        ABSTRACT     = 8, //C#, Java
        ASYNC        = 16, //C#
        UNSAVE       = 32, //C#
        FINAL        = 64, //Java
        SYNCHRONIZED  = 128 //Java
    };
public:
    explicit MethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        m_name(name), m_returnType(returnType), m_flags(flags) {} // конструктор
    virtual void add(std::shared_ptr<Unit> unit, Flags flags = 0) = 0; // виртуальная функция добавления
    virtual std::string compile(unsigned int level = 0) const = 0; // виртуальная функция генерации кода
    virtual ~MethodUnit() {} // виртуальный деструктор, очищающий память и позволяющий наследникам определять свои
protected:
    std::string m_name; // название функции
    std::string m_returnType; // возвращаемый тип
    Flags m_flags; // модификаторы
    std::list<std::shared_ptr<Unit>> m_body; // тело функции
};

#endif // METHODUNIT_H
