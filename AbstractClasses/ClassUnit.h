#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <string>
#include <vector>
#include <list>

#include "AbstractClasses/Unit.h"

// Абстрактный класс ClassUnit, используемый для генерации класса
class ClassUnit: public Unit
{
public:
    enum AccessModifier { // типы доступа
        PUBLIC, // C++, C#, Java
        PROTECTED, // C++, C#, Java
        PRIVATE, // C++, C#, Java
        INTERNAL, // C#
        PROTECTED_INTERNAL, // C#
        PRIVATE_PROTECTED // C#
    };
    static const std::vector<std::string> ACCESS_MODIFIERS; // статический массив названий типов доступа
public:
    explicit ClassUnit(const std::string& name): m_name(name) {} // конструктор
    virtual void add(std::shared_ptr<Unit> unit, Flags flags) = 0; // виртуальная функция добавления
    virtual std::string compile(unsigned int level = 0) const = 0; // виртуальная функция генерации кода
    virtual ~ClassUnit() {} // виртуальный деструктор, очищающий память и позволяющий наследникам определять свои
protected:
    std::string m_name; // название класса
    using Fields = std::list<std::shared_ptr<Unit>>; // сокращение типа данных для удобства
    std::vector<Fields> m_fields; // массив списков функций, распределённый по типам доступа
};

#endif // CLASSUNIT_H
