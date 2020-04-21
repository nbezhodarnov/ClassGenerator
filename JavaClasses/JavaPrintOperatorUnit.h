#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

// Конкретный класс, генерирующий оператор вывода на языке программирования Java
class JavaPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {} // конструктор
    std::string compile(unsigned int level = 0) const { // функция генерации оператора вывода
        return generateShift(level) + "System.out.print( \"" + m_text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_H
