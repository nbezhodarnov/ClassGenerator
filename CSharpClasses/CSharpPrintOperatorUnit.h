#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

// Конкретный класс, генерирующий оператор вывода на языке программирования C#
class CSharpPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit CSharpPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {} // констурктор
    std::string compile(unsigned int level = 0) const { // функция генерации оператора вывода
        return generateShift(level) + "System.Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // CSHARPPRINTOPERATORUNIT_H
