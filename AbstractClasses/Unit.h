#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <string>

// Абстрактный класс Unit, содержащий общие функции, которые будут использоваться при наследовании
class Unit {
public:
    using Flags = unsigned int; // сокращение типа данных для удобства
public:
    virtual ~Unit() = default; // виртуальный деструктор, необходимый наследникам для определения собственного
    virtual void add(Unit*, Flags = 0) { // виртуальная функция добавления
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0; // виртуальная функция генерации кода
protected:
    virtual std::string generateShift(unsigned int level) const { // виртуальная функция табуляции, которую наследники могут переделать под себя
        static const auto DEFAULT_SHIFT = '\t';
        std::string result;
        for(unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
