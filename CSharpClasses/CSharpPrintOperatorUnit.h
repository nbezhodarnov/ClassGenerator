#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

class CSharpPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit CSharpPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {}
    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "System.Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // CSHARPPRINTOPERATORUNIT_H
