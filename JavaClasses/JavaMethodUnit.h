#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

// Конкретный класс, генерирующий функцию на языке программирования Java
class JavaMethodUnit: public MethodUnit {
public:
    explicit JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags):
        MethodUnit(name, returnType, flags) {} // конструктор
    void add(Unit* unit, Unit::Flags /* flags */ = 0) { // функция добавления операторов в тело
        if (unit != nullptr) { // проверка на существование объекта
            m_body.push_back(unit);
        }
    }
    std::string compile(unsigned int level = 0) const { // функция генерации функции
        std::string result = "";

        // объявление модификаторов
        if(m_flags & MethodUnit::SYNCHRONIZED) {
            result += "synchronized ";
        }
        if(m_flags & MethodUnit::STATIC) {
            result += "static ";
        }
        if(m_flags & MethodUnit::ABSTRACT) {
            result += "abstract ";
        } else if (m_flags & MethodUnit::FINAL) { // при объявлении модификаторов не могут стоять одновременно abstract и final
            result += "final ";
        }

        // объявление функции
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";

        // генерация тела функции
        for(const auto& b: m_body) {
            result += b->compile(level + 1); // генерация операторов функции
        }
        result += generateShift(level) + "}\n"; // закрытие функции

        return result;
    }
};

#endif // JAVAMETHODUNIT_H
