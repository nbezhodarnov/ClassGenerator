#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <string>
#include <vector>
#include <list>

#include "AbstractClasses/Unit.h"

class ClassUnit: public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string& name): m_name(name) {}
    virtual void add(Unit* unit, Flags flags) = 0;
    virtual std::string compile(unsigned int level = 0) const = 0;
    virtual ~ClassUnit() {
        for (unsigned int i = 0; i < m_fields.size(); i++) {
            for (auto iterator = m_fields[i].begin(); iterator != m_fields[i].end(); iterator++) {
                delete *iterator;
            }
            m_fields[i].clear();
        }
        m_fields.clear();
    }
protected:
    std::string m_name;
    using Fields = std::list<Unit*>;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_H
