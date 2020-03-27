#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

class CSharpMethodUnit: public MethodUnit {
public:
    explicit CSharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags):
        MethodUnit(name, returnType, flags) {}
    void add(Unit* unit, Unit::Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string result = "";
        if(m_flags & MethodUnit::ASYNC) {
            result += "asyns ";
        }
        if(m_flags & MethodUnit::UNSAVE) {
            result += "unsave ";
        }
        if( m_flags & MethodUnit::VIRTUAL) {
            result += "virtual ";
        } else {
            if(m_flags & MethodUnit::STATIC) {
                result += "static ";
            }
            if(m_flags & MethodUnit::ABSTRACT) {
                result += "abstract ";
            }
        }
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CSHARPMETHODUNIT_H
