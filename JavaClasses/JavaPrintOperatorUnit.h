#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

class JavaPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {}
    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "System.out.print( \"" + m_text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_H
