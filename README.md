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
| error_prefix        | string  | "Error on line $line : " | Change the prefix of error message. `str_error` or/and `decimal_error` must be true in order for this to work
| decimal_error_msg   | string  | "Invalid syntax '.'"     | Change the message of decimal error message. `decimal_error` must be true in order for this to work
| unclose_string_1    | string  | "Unclosed \`'\`"         | Change the message of unclosed Apostrophe mark/string, `str_error` must be true in order for this to work
| unclose_string_2    | string  | "Unclosed \`\\"\`"       | Change the message of unclosed Ditto mark, `str_error` must be true in order for this to work
| unfinished_escape   | string  | "Unfinished \`\\\`"      | Change the message of Unfinished Escape, this error happen when like `\n` but without `n`
| true_template       | string  | "true"                   | Change the string to define as `TRUE` label, `use_boolean` must be enabled in order to let this work
| and_template        | string  | "and"                    | Change the string to define as `AND` label, `use_and_or_keyword` or/and `use_and_ore_operator` must be enabled in order to let this work
| or_template         | string  | "or"                     | Change the string to define as `OR` label, `use_and_or_keyword` or/and `use_and_ore_operator` must be enabled in order to let this work
| false_template      | string  | "false"                  | Change the string to define as `FALSE` label, `use_boolean` must be enabled in order to let this work
| str_classify        | boolean | false                    | Set if classify string and character, if enabled. When the string use `'` instead of `"`. it will be given `CHARACTER` label instead of string. If disabled, `'` and `"` will be the same.
| str_error           | boolean | true                     | Set if enable String error.
| decimal_error       | boolean | true                     | Set if enable Decimal error. This will happen when invalid `.` happened. For example `1.1.1` instead of `1.1`. This is recommened to enable if you're making a programming language
| str_only_escape.    | boolean | false                    | If enabled, escape character will only work inside a string label. `\"` and `\'` is not included.
| use_and_or_on_operator | boolean | false                 | If enabled, operator `&&`/`||` will be identified as `AND`/`OR` label
| use_bitwise         | boolean | false                    | If enabled, operator `&`, `|`, `^`, `~` will be identified as `BIWISE` label
| use_boolean         | boolean | true                     | If enabled, keyword that is same as `true_template`/`false_template`'s value will be identified as `TRUE`/`FALSE`
| use_and_or_keyword  | boolean | false                    | If enabled, keyword that is same as `and_template`/`or_template`'s value will be identified as `AND`/`OR` label
----------
## Available operators:
- `+` (Labeled as `OPERATORS`)
- `-` (Labeled as `OPERATORS`)
- `*` (Labeled as `OPERATORS`)
- `/` (Labeled as `OPERATORS`)
- `^` (If `use_bitwise` enabled, this will be labeled as `BITWISE`)
- `%` (Labeled as `OPERATORS`)
- `(` (Labeled as `OPERATORS`)
- `)` (Labeled as `OPERATORS`)
- `[` (Labeled as `OPERATORS`)
- `]` (Labeled as `OPERATORS`)
- `{` (Labeled as `OPERATORS`)
- `}` (Labeled as `OPERATORS`)
- `;` (Labeled as `OPERATORS`)
- `~` (If `use_bitwise` enabled, this will be labeled as `BITWISE`)
- `!` (Labeled as `OPERATORS`)
- `&&` (If `use_and_or_on_operator` enabled, this will be labeled as `AND`
- `||` (If `use_and_or_on_operator` enabled, this will be labeled as `OR`
- `<` (Labeled as `COMPARISON`)
- `>` (Labeled as `COMPARISON`)
- `<<` (Labeled as `OPERATORS`)
- `>>` (Labeled as `OPERATORS`)
- `<<=` (Labeled as `ASSIGNMENT`)
- `>>=` (Labeled as `ASSIGNMENT`)
- `<=>` (Labeled as `OPERATORS`)
- `<=` (Labeled as `COMPARISON`)
- `>=` (Labeled as `COMPARISON`)
- `->` (Labeled as `OPERATORS`)
- `--` (Labeled as `DECREMENT`)
- `++` (Labeled as `INCREMENT`)
- `-=` (Labeled as `ASSIGNMENT`)
- `+=` (Labeled as `ASSIGNMENT`)
- `&` (If `use_bitwise` enabled, this will be labeled as `BITWISE`)
- `|` (If `use_bitwise` enabled, this will be labeled as `BITWISE`)
- `==` (Labeled as `COMPARISON`)
- `!=` (Labeled as `COMPARISON`)
- `=` (Labeled as `OPERATORS`)
- `&=` (Labeled as `ASSIGNMENT`)
- `|=` (Labeled as `ASSIGNMENT`)
- `^=` (Labeled as `ASSIGNMENT`)
- `*=` (Labeled as `ASSIGNMENT`)
- `/=` (Labeled as `ASSIGNMENT`)
- `%=` (Labeled as `ASSIGNMENT`)
- `,` (Labeled as `OPERATORS`)
- `?` (Labeled as `OPERATORS`)
- `?:` (Labeled as `OPERATORS`)
- `.` (Only labeled as `OPERATORS` if not a part of decimal)
## Example of tokens:
- STRING
  - `"Hello World!"`
  -  `'Hello World!'`
- CHARACTER
  - `'A'` (Only work if `str_classify` enabled)
- END_LINE
  - Just new line.
- INTERGER
  - `12363`
- DECIMAL
  - `156.7`
- OPERATOR
  - `+`
  - `-`
  - `,`
- VARIABLE
  - `$hello`
  - `$joemama`
- INCREMENT
  - `++`
- DECREMENT
  - `--`
- PUNCTUATOR
  - `;`
- COMPARISON
  - `==`
  - `<=`
  - `>=`
- ASSIGNMENT
  - `+=`
  - `-=`
  - `>>=`
- OR
  - `or` (Only work if `use_and_or_keyword` enabled, can be configured using `or_template`)
  - `&&` (Only work if `use_and_or_on_operator` enabled)
- AND
  - `and` (Only work if `use_and_or_keyword` enabled, can be configured using `and_template`)
  - `||` (Only work if `use_and_or_on_operator` enabled)
- BITWISE
  - `&` (Only work if `use_bitwise` enabled)
  - `|` (Only work if `use_bitwise` enabled)
  - `^` (Only work if `use_bitwise` enabled)
- TRUE
  - `true` (Only work if `use_boolean` enabled, can be configured using `true_template`)
- FALSE
  - `false` (Only work if `use_boolean` enabled, can be configured using `false_template`)
## Available function and it use
- Class `Lexer`
  - `Lexer()`
    - Example: `Lexer lexerobject(value);`
    - `value` argument is for the string lexer will process.
  - `read_file()`
    - Example: `lexerobject.read_file(file_path);`
    - `file_path` argument is for the path lexer to read and return as string.
  - `Process()`
    - Example: `lexerobject.Process();`
    - This function will process the value brought in by `Lexer lexerobject(value);` and return the results as `Parser` class
- Class `Parser`
  - `append()`
    - Example: `parserobject.append(KEYWORD, "deeznut");`
    - This function will append label KEYWORD, value "deeznut" as pair to the data of Parser class
  - `first()`
    - Example: `parserobject.first(2);`
    - This function will get the label of results's array 2, which is the third result's label.
  - `getType()`
    - Example: `parserobject.getType(parserobject.first(1));`
    - If the second result of parserobject's data is `INCREMENT`. Then it will return string `"INCREMENT"`, `parserobject.getType(COMPARISON);` will return string `"COMPARISON"` too as well.
  - `size()`
    - Example: `parserobject.size();`
    - This function will return the size of the data. If the size of the Parser class data is 30, it will return 30 of size_t.
  - `second()`
    - Example: `parserobject.second(2);`
    - This function will get the value of results's array 2, which is the third result's value.
  - `ModifyVariable()`
    - Example: `parserobject.ModifyVariable("hi", "hello");`
    - This function will change the variable value `hi` to `hello`, this function is kinda useless but i dont care lol. I will remove this soon
  - `jsonlize()`
    - Example: `parserobject.jsonlize();`
    - This function will return the data of class as json type in string, for example:
      - Data that lexer will process is `Bruh moment "lol"`
      - Then the function will return 
```json
[
    {
        "KEYWORD": "Bruh"
    }, 
    {
        "KEYWORD": "moment"
    }, 
    {
        "STRING": "lol"
    }
]
```
  - `xmlize()`
    - Example: `parserobject.xmlize();`
    - This function will return the data of class as json type in string, for example:
      - Data that lexer will process is `Bruh moment "lol"`
      - Then the function will return 
```xml
<?xml version="1.0" encoding="UTF-8"?>
<lexer>
    <keyword>Bruh</keyword>
    <keyword>moment</keyword>
    <string>lol</string>
</lexer>
```
  - `yamlize()`
    - Example: `parserobject.yamlize();`
    - This function will return the data of class as json type in string, for example:
      - Data that lexer will process is `Bruh moment "lol"`
      - Then the function will return 
```yaml
 lexer:
     - keyword:
         - 'Bruh'
     - keyword:
         - 'moment'
     - string:
         - 'lol'
```
  - `operator[]`
    - Example: `parserobject[1]`
    - This operator will get the value of results's array 2, which is the third result's value.
        
