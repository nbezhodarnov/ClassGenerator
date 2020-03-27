#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"
#include "AbstractClasses/ClassUnit.h"

class JavaClassUnit: public ClassUnit
{
public:
    explicit JavaClassUnit(const std::string& name, Unit::Flags accessFlags = ClassUnit::PUBLIC, Unit::Flags modifierFlags = 0): ClassUnit(name) {
         m_fields.resize(3);
         classAccessModifier = accessFlags;
         classModifier = 0;
         if (modifierFlags & MethodUnit::FINAL) {
             classModifier |= MethodUnit::FINAL;
         } else if (modifierFlags & MethodUnit::ABSTRACT) {
             classModifier |= MethodUnit::ABSTRACT;
         }
         if (accessFlags >= 2) {
             classAccessModifier = ClassUnit::PUBLIC;
             throw std::runtime_error("JavaClassUnit: Unsupported access modifier.");
         }
    }
    void add(Unit* unit, Unit::Flags flags) {
         int accessModifier = ClassUnit::PUBLIC;
         if(flags < 3) {
              accessModifier = flags;
         }
         m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const {
        std::string classAccessModifierString = "", classModifierString = "";
        classAccessModifierString = ACCESS_MODIFIERS[classAccessModifier] + ' ';
        if (classModifier & MethodUnit::FINAL) {
            classModifierString = "final ";
        } else if (classModifier & MethodUnit::ABSTRACT) {
            classModifierString = "abstract ";
        }
        std::string result = generateShift(level) + classAccessModifierString + classModifierString + "class " + m_name + " {\n";
        for(size_t i = 0; i < m_fields.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }
            for(const auto& f: m_fields[i]) {
                result += generateShift(level + 1) + ClassUnit::ACCESS_MODIFIERS[i] + ' ' + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
private:
    Unit::Flags classAccessModifier, classModifier;
};

#endif // JAVACLASSUNIT_H
