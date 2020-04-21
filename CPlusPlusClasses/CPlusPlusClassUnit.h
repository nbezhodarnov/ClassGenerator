#ifndef CPLUSPLUSCLASSUNIT_H
#define CPLUSPLUSCLASSUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/ClassUnit.h"

// Конкретный класс, генерирующий класс на языке программирования C++
class CPlusPlusClassUnit: public ClassUnit
{
public:
    explicit CPlusPlusClassUnit(const std::string& name): ClassUnit(name) { // конструктор
         m_fields.resize(3); // размер массива изменяется на 3, так как C++ имеет всего 3 типа доступа
    }
    void add(Unit* unit, Unit::Flags flags) { // функция добавления методов в класс
         // идентификация типа доступа
         int accessModifier = ClassUnit::PRIVATE;
         if(flags < 3) {
              accessModifier = flags;
         }

         m_fields[accessModifier].push_back(unit); // добавление метода в список с соответствующим типом доступа
    }
    std::string compile(unsigned int level = 0) const { // функция генерации класса
        std::string result = generateShift(level) + "class " + m_name + " {\n"; // объявление класса
        for(size_t i = 0; i < m_fields.size(); ++i) { // цикл объявления функций и определения их тел
            if(m_fields[i].empty()) { // пропускаются пустые списки функций
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n"; // объявление типа доступа
            for(const auto& f: m_fields[i]) { // цикл по функциям с данным типом доступа
                result += f->compile(level + 1); // генерация функций
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n"; // закрытие класса
        return result;
    }
};

#endif // CPLUSPLUSCLASSUNIT_H
