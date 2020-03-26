#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <vector>

#include "AbstractClasses/Unit.h"

class MethodUnit: public Unit {
public:
    enum Modifier {
        STATIC       = 1,
        CONST        = 2,
        VIRTUAL      = 4,
        ABSTRACT     = 8,
        ASYNC        = 16,
        UNSAVE       = 32
    };
public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        m_name(name), m_returnType(returnType), m_flags(flags) {}
    virtual void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    virtual std::string compile(unsigned int level = 0) const = 0; /*{
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
    }*/
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODUNIT_H
