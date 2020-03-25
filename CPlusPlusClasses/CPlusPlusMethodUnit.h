#ifndef CPLUSPLUSMETHODUNIT_H
#define CPLUSPLUSMETHODUNIT_H

#include <vector>

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

class CPlusPlusMethodUnit: public MethodUnit {
public:
    enum Modifier {
        STATIC       = 1,
        CONST        = 2,
        VIRTUAL      = 4
    };
public:
    CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        MethodUnit(name, returnType, flags) {}
    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    virtual std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level);
        if(m_flags & STATIC) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
};

#endif // CPLUSPLUSMETHODUNIT_H
