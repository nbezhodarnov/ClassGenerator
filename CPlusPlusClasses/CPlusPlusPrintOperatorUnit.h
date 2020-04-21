#ifndef CPLUSPLUSPRINTOPERATORUNIT_H
#define CPLUSPLUSPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

// Конкретный класс, генерирующий оператор вывода на языке программирования C++
class CPlusPlusPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit CPlusPlusPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {} // конструктор
    std::string compile(unsigned int level = 0) const { // функция генераци оператора вывода
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPLUSPLUSPRINTOPERATORUNIT_H
