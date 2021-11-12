# lexertk
The most modern, easiest, advanced and Customizable Lexer Took Kit in the World
-----------
Example Code:
```cpp
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
    Parser data = lexer.Process();
    for(int i = 0; i < data.size(); i++)
    {
        cout << data.getType(data.first(i)) << " : " << data[i] << endl;
    }
}
```
Output:
<br>
<img width="684" alt="Screen Shot 2021-11-12 at 4 55 19 PM" src="https://user-images.githubusercontent.com/66505831/141439160-503d1860-5c95-49d4-a7a9-b485e4454df9.png">
----------
Available configuration:
| Configuration Name  |   Type  | Default Value            | Description |
| ------------------- | ------- | ------------------------ | ----------- |
| error_prefix        | string  | "Error on line $line : " | Change the prefix of error message. str_error or decimal_error must be true in order for this to work
| decimal_error_msg   | string  | "Invalid syntax '.'"     | Change the message of decimal error message. decimal_error must be true in order for this to work
| unclose_string_1    | string  | "Unclosed \`'\`"         | Change the message of unclosed Apostrophe mark/string, str_error must be true in order for this to work
| unclose_string_2    | string  | "Unclosed \`\\"\`"       | Change the message of unclosed Ditto mark, str_error must be true in order for this to work
| unfinished_escape   | string  | "Unfinished \`\\\`"      | Change the message of Unfinished Escape, this error happen when like `\n` but without `n`
| true_template       | string  | "true"                   | Change the string to define as `TRUE` label
| and_template        | string  | "and"                    | Change the string to define as `AND` label
| or_template         | string  | "or"                     | Change the string to define as `OR` label
| false_template      | string  | "false"                  | Change the string to define as `FALSE` label
