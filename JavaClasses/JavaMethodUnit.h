#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include <vector>

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

class JavaMethodUnit: public MethodUnit {
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags):
        MethodUnit(name, returnType, flags) {}
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string result = ""; //generateShift(level);
        if(m_flags & MethodUnit::SYNCHRONIZED) {
            result += "synchronized ";
        }
        if(m_flags & MethodUnit::STATIC) {
            result += "static ";
        }
        if(m_flags & MethodUnit::ABSTRACT) {
            result += "abstract ";
        } else if (m_flags & MethodUnit::FINAL) {
            result += "final ";
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

#endif // JAVAMETHODUNIT_H
