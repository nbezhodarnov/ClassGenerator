#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"

// Абстрактный класс PrintOperatorUnit, используемый для генерации операции вывода
class PrintOperatorUnit: public Unit {
public:
    explicit PrintOperatorUnit(const std::string& text): m_text(text) {} // конструктор
    virtual std::string compile(unsigned int level = 0) const = 0; // виртуальная функция генерации кода
protected:
    std::string m_text; // текст операции вывода
};

#endif // PRINTOPERATORUNIT_H
