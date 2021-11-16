#include <iostream>
#include "lexerkit.hpp"
using namespace ELEMENT;

int main()
{
    Lexer lexer(R"(
        int main()
        {
            $value = 3683
            $value++;
            cout << "\"Hello World!\"" + ", My Robot ID is " << $value << "\n";
            return 1.5;
        }
    )");
    Data data = lexer.Process();
    for(int i = 0; i < data.size(); i++)
    {
        cout << data.getType(data.first(i)) << " : " << data[i] << endl;
    }
}