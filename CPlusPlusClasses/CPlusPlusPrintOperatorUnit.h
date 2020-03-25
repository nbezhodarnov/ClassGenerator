#ifndef CPLUSPLUSPRINTOPERATORUNIT_H
#define CPLUSPLUSPRINTOPERATORUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/PrintOperatorUnit.h"

class CPlusPlusPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit CPlusPlusPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {}
    virtual std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPLUSPLUSPRINTOPERATORUNIT_H
