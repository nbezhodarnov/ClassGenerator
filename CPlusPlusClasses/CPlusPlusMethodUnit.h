#ifndef CPLUSPLUSMETHODUNIT_H
#define CPLUSPLUSMETHODUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

class CPlusPlusMethodUnit: public MethodUnit {
public:
    explicit CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        MethodUnit(name, returnType, flags) {}
    void add(Unit* unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level);
        if(m_flags & MethodUnit::STATIC) {
            result += "static ";
        } else if(m_flags & MethodUnit::VIRTUAL) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if(m_flags & MethodUnit::CONST) {
            result += " const";
        }
        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CPLUSPLUSMETHODUNIT_H
