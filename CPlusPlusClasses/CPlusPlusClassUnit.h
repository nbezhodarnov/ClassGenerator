#ifndef CPLUSPLUSCLASSUNIT_H
#define CPLUSPLUSCLASSUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/ClassUnit.h"

class CPlusPlusClassUnit: public ClassUnit
{
public:
    explicit CPlusPlusClassUnit(const std::string& name): ClassUnit(name) {
         m_fields.resize(3);
    }
    void add(Unit* unit, Unit::Flags flags) {
         int accessModifier = ClassUnit::PRIVATE;
         if(flags < 3) {
              accessModifier = flags;
         }
         m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < m_fields.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";
            for(const auto& f: m_fields[i]) {
                result += f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // CPLUSPLUSCLASSUNIT_H
