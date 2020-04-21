#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "AbstractClasses/Unit.h"
#include "AbstractClasses/MethodUnit.h"
#include "AbstractClasses/ClassUnit.h"

// Конкретный класс, генерирующий класс на языке программирования Java
class JavaClassUnit: public ClassUnit
{
public:
    explicit JavaClassUnit(const std::string& name, Unit::Flags accessFlags = ClassUnit::PUBLIC, Unit::Flags modifierFlags = 0): ClassUnit(name) { // конструктор
        m_fields.resize(3); // размер массива изменяется на 3, так как Java имеет 3 типа доступа
        classAccessModifier = accessFlags; //определение типа доступа

        // определение модификаторов
        classModifier = 0;
        if (modifierFlags & MethodUnit::FINAL) {
            classModifier |= MethodUnit::FINAL;
        } else if (modifierFlags & MethodUnit::ABSTRACT) {
            classModifier |= MethodUnit::ABSTRACT;
        }

        if (accessFlags >= 2) { // проверка типа доступа
            classAccessModifier = ClassUnit::PUBLIC;
            if (accessFlags > 2) {
                throw std::runtime_error("JavaClassUnit: Unknown access modifier.");
            } else {
                throw std::runtime_error("JavaClassUnit: Unavailable access modifier for class.");
            }
        }
    }
    void add(Unit* unit, Unit::Flags flags) { // функция добавления функций в класс
        if (unit == nullptr) { // проверка на существование объекта
            return;
        }
        // определение типа доступа
        int accessModifier = ClassUnit::PUBLIC;
        if(flags < 3) {
            accessModifier = flags;
        } else {
            throw std::runtime_error("JavaClassUnit: Unknown access modifier.");
        }
        m_fields[accessModifier].push_back(unit); // добавление функции в список с соответствующим типом доступа
    }
    std::string compile(unsigned int level = 0) const { // функция генерации класса
        std::string classAccessModifierString = "", classModifierString = "";
        classAccessModifierString = ACCESS_MODIFIERS[classAccessModifier] + ' '; // объявление типа доступа

        // объявление модификаторов
        if (classModifier & MethodUnit::FINAL) {
            classModifierString = "final ";
        } else if (classModifier & MethodUnit::ABSTRACT) {
            classModifierString = "abstract ";
        }

        std::string result = generateShift(level) + classAccessModifierString + classModifierString + "class " + m_name + " {\n"; // объявление класса
        for(size_t i = 0; i < m_fields.size(); ++i) { // цикл объявления функции и определения их тел
            if(m_fields[i].empty()) { // пустые списки пропускаются
                continue;
            }
            for(const auto& f: m_fields[i]) {
                result += generateShift(level + 1) + ClassUnit::ACCESS_MODIFIERS[i] + ' ' + f->compile(level + 1); // генерация функции
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n"; // закрытие класса
        return result;
    }
private:
    Unit::Flags classAccessModifier, classModifier; // тип доступа и модификаторы класса
};

#endif // JAVACLASSUNIT_H
