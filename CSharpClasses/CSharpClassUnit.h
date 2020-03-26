#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include <memory>
#include <string>
#include <vector>

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/ClassUnit.h"

class CSharpClassUnit: public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name, Unit::Flags flags = ClassUnit::PRIVATE): ClassUnit(name) {
         m_fields.resize(ClassUnit::ACCESS_MODIFIERS.size());
         classAccessModifier = flags;
         if (flags >= ClassUnit::ACCESS_MODIFIERS.size()) {
             classAccessModifier = ClassUnit::PRIVATE;
             throw std::runtime_error("CSharpClassUnit: There is no such access modifier.");
         }
    }
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags) {
         int accessModifier = ClassUnit::PRIVATE;
         if(flags < ClassUnit::ACCESS_MODIFIERS.size()) {
              accessModifier = flags;
         }
         m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string classAccessModifierString = "";
        if (classAccessModifier != ClassUnit::PRIVATE) {
            classAccessModifierString = ACCESS_MODIFIERS[classAccessModifier] + ' ';
        }
        std::string result = generateShift(level) + classAccessModifierString + "class " + m_name + " {\n";
        for(size_t i = 0; i < ClassUnit::ACCESS_MODIFIERS.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }
            //result += CSharpClassUnit::ACCESS_MODIFIERS[i] + ":\n";
            for(const auto& f: m_fields[i]) {
                result += generateShift(level + 1) + ClassUnit::ACCESS_MODIFIERS[i] + ' ' + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
private:
    Unit::Flags classAccessModifier;
};

#endif // CSHARPCLASSUNIT_H
