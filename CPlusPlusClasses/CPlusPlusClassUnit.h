#ifndef CPLUSPLUSCLASSUNIT_H
#define CPLUSPLUSCLASSUNIT_H

#include <memory>
#include <string>
#include <vector>

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/ClassUnit.h"

//extern const std::vector<std::string> ACCESS_MODIFIERS;

class CPlusPlusClassUnit: public ClassUnit
{
public:
    explicit CPlusPlusClassUnit(const std::string& name): ClassUnit(name) {
         m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags) {
         int accessModifier = ClassUnit::PRIVATE;
         if(flags < ClassUnit::ACCESS_MODIFIERS.size()) {
              accessModifier = flags;
         }
         m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
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
