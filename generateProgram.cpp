#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
"protected", "private" };

std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void",
MethodUnit::STATIC ),
        ClassUnit::PRIVATE
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void",
MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
    );
    auto method = std::make_shared< MethodUnit >( "testFunc4",
"void", MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello,
world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}
