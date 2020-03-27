#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <list>

#include "AbstractClasses/Unit.h"

class MethodUnit: public Unit {
public:
    enum Modifier {
        STATIC       = 1,
        CONST        = 2,
        VIRTUAL      = 4,
        ABSTRACT     = 8,
        ASYNC        = 16,
        UNSAVE       = 32,
        FINAL        = 64,
        SYNCHRONIZED  = 128
    };
public:
    explicit MethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        m_name(name), m_returnType(returnType), m_flags(flags) {}
    virtual void add(Unit* unit, Flags) = 0;
    virtual std::string compile(unsigned int level = 0) const = 0;
    virtual ~MethodUnit() {
        for (auto iterator = m_body.begin(); iterator != m_body.end(); iterator++) {
            delete *iterator;
        }
        m_body.clear();
    }
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::list<Unit*> m_body;
};

#endif // METHODUNIT_H
