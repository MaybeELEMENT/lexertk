#include <iostream>
#include "lexerkit.hpp"
using namespace ELEMENT;

int main()
{
    //Main Input string for the lexer
    Lexer lexer(R"(
        PRINT "Hello World!"; PRINT 123;
        PRINT true;
        PRINT false;
    )");
    /*Configure the lexer*/
    lexer.false_template = "false";
    lexer.true_template = "true";
    lexer.use_boolean = true;
    /*Configure the lexer*/
    
    //Process the code
    Data data = lexer.Process();
    bool printing = false;
    for(int i = 0; i < data.size(); i++)
    {
        if(data.first(i) == KEYWORD)
        {
            //Check if the keyword is `PRINT`
            if(data[i] == "PRINT") printing = true;
        }
        else if(data.first(i) == PUNCTUATOR) { if(printing) {cout << endl; printing = false;} }
        else if(data.first(i) == END_LINE);
        else
        {
            //Check if `PRINT` keyword was exist
            if(printing)
            {
                //Check if the token is STRING, BOOLEAN, INTERGER, DECIMAL or CHARACTER
                if(data.first(i) == STRING || data.first(i) == BOOLEAN || data.first(i) == INTERGER 
                || data.first(i) == DECIMAL || data.first(i) == CHARACTER) 
                    cout << data[i];
                else 
                {
                    //Give undefined error
                    cout << "Undefined \"" << data[i] << "\"." << endl;
                    exit(1);
                }
            }
            else
            {
                //Give undefined error
                cout << "Undefined \"" << data[i] << "\"." << endl;
                exit(1);
            }
        }
    }
}
