// testing Tokenizer class

#include "Tokenizer.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    // instanciate Tokenizer class
    Tokenizer str;
    string token;
    int counter = 0;

    // set source string with default delimiters (space, tab, and newline char)
    str.set("This is a testing\t string.\n\nTry to modify it \t\t yourself.");

    // Tokenizer::next() returns a next available token from source string
    // If it reaches EOS, it returns zero-length string, "".
    while((token = str.next()) != "")
    {
        ++counter;
        cout << counter << ": " << token << endl;
    }
    cout << endl;


    // set a different string and delimiters(~, _)
    // Notice that space is not delimiter any more.
    counter = 0;
    str.set("Now,~the_delimiters~~~are__changed~to_tild  and  underscore.~", "~_");
    while((token = str.next()) != "")
    {
        ++counter;
        cout << counter << ": " << token << endl;
    }

    return 0;
}

