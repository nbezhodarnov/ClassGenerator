#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

// Конкретный класс генерации функций на языке программирования C#
class CSharpMethodUnit: public MethodUnit {
public:
    explicit CSharpMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags):
        MethodUnit(name, returnType, flags) {} // конструктор
    void add(Unit* unit, Unit::Flags /* flags */ = 0) { // функция добавления операторов в тело
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const { // функция генерации функции
        std::string result = "";

        // объявление модификаторов
        if(m_flags & MethodUnit::ASYNC) {
            result += "asyns ";
        }
        if(m_flags & MethodUnit::UNSAVE) {
            result += "unsave ";
        }
        if( m_flags & MethodUnit::VIRTUAL) {
            result += "virtual ";
        } else { // при объявлении не могут стоять одновременно virtual и static/abstract
            if(m_flags & MethodUnit::STATIC) {
                result += "static ";
            }
            if(m_flags & MethodUnit::ABSTRACT) {
                result += "abstract ";
            }
        }

        // объявление функции
        result += m_returnType + " ";
        result += m_name + "()";

        // генерация тела функции
        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1); // генерация операторов функций
        }
        result += generateShift(level) + "}\n"; // закрытие функции

        return result;
    }
};

#endif // CSHARPMETHODUNIT_H
