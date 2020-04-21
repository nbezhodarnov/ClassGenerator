#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/ClassUnit.h"

// Конкретный класс, генерирующий класс на языке программирования C#
class CSharpClassUnit: public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name, Unit::Flags flags = ClassUnit::PRIVATE): ClassUnit(name) { // конструктор
        m_fields.resize(ClassUnit::ACCESS_MODIFIERS.size()); // размер массива изменяется на 6, так как C++ имеет 6 типов доступа

        // определение типа доступа класса
        classAccessModifier = flags;
        if (flags >= ClassUnit::ACCESS_MODIFIERS.size()) {
            classAccessModifier = ClassUnit::PRIVATE;
            throw std::runtime_error("CSharpClassUnit: Unknown access modifier.");
        }
    }
    void add(Unit* unit, Unit::Flags flags) { // функция добавления функции в класс
        if (unit == nullptr) { // проверка на существование объекта
            return;
        }
        // опеределение типа доступа
        int accessModifier = ClassUnit::PRIVATE;
        if(flags < ClassUnit::ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        } else {
            throw std::runtime_error("CSharpClassUnit: Unknown access modifier.");
        }

        m_fields[accessModifier].push_back(unit); // добавление функции в список с соответствующим типом доступа
    }
    std::string compile(unsigned int level = 0) const { // функция генерации класса
        // объявление типа доступа
        std::string classAccessModifierString = "";
        if (classAccessModifier != ClassUnit::PRIVATE) {
            classAccessModifierString = ACCESS_MODIFIERS[classAccessModifier] + ' ';
        }

        std::string result = generateShift(level) + classAccessModifierString + "class " + m_name + " {\n"; // объявление класса
        for(size_t i = 0; i < m_fields.size(); ++i) { // цикл объявления функций и определения их тел
            if(m_fields[i].empty()) { // пустые списки пропускаются
                continue;
            }
            for(const auto& f: m_fields[i]) {
                result += generateShift(level + 1) + ClassUnit::ACCESS_MODIFIERS[i] + ' ' + f->compile(level + 1); // генерация функций
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n"; // закрытие класса
        return result;
    }
private:
    Unit::Flags classAccessModifier; // тип доступа класса
};

#endif // CSHARPCLASSUNIT_H
