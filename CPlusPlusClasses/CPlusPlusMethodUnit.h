#ifndef CPLUSPLUSMETHODUNIT_H
#define CPLUSPLUSMETHODUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"

// Конкретный класс, генерирующий функцию на языке программирования C++
class CPlusPlusMethodUnit: public MethodUnit {
public:
    explicit CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags):
        MethodUnit(name, returnType, flags) {} // конструктор
    void add(std::shared_ptr<Unit> unit, Flags /* flags */ = 0) { // функция добавления операторов в тело
        if (unit != nullptr) { // проверка на существование объекта
            m_body.push_back(unit);
        }
    }
    std::string compile(unsigned int level = 0) const { // функция генерации функции
        std::string result = generateShift(level);

        // объявление модификаторов и функции
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

        // генерация тела функции
        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1); // генерация операторов
        }
        result += generateShift(level) + "}\n"; // закрытие функции

        return result;
    }
};

#endif // CPLUSPLUSMETHODUNIT_H
