#include <iostream>
#include "lexerkit.hpp"
using namespace ELEMENT;

int main()
{
    Lexer lexer(R"(
        PRINT "Hello World!"; PRINT 123;
        PRINT true;
        PRINT false;
    )");
    lexer.false_template = "false";
    lexer.true_template = "true";
    lexer.use_boolean = true;
    Data data = lexer.Process();
    bool printing = false;
    for(int i = 0; i < data.size(); i++)
    {
        if(data.first(i) == KEYWORD)
        {
            if(data[i] == "PRINT") printing = true;
        }
        else if(data.first(i) == PUNCTUATOR) { if(printing) {cout << endl; printing = false;} }
        else if(data.first(i) == END_LINE);
        else
        {
            if(printing)
            {
                
                if(data.first(i) == STRING || data.first(i) == BOOLEAN || data.first(i) == INTERGER 
                || data.first(i) == DECIMAL || data.first(i) == CHARACTER) 
                    cout << data[i];
                else 
                {
                    cout << "Undefined \"" << data[i] << "\"." << endl;
                    exit(1);
                }
            }
            else
            {
                cout << "Undefined \"" << data[i] << "\"." << endl;
                exit(1);
            }
        }
    }
}