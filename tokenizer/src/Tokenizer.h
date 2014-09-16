///////////////////////////////////////////////////////////////////////////////
// Tokenizer.h
// ===========
// General purpose string tokenizer (C++ string version)
//
// The default delimiters are space(" "), tab(\t, \v), newline(\n),
// carriage return(\r), and form feed(\f).
// If you want to use different delimiters, then use setDelimiter() to override
// the delimiters. Note that the delimiter string can hold multiple characters.
///////////////////////////////////////////////////////////////////////////////
#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>
#include <set>
// default delimiter string (space, tab, newline, carriage return, form feed)
const std::string DEFAULT_DELIMITER = " \t\v\n\r\f";
class Tokenizer
{
public:
    // ctor/dtor
    Tokenizer();
    Tokenizer(const std::string& str, const std::string& delimiter=DEFAULT_DELIMITER);
    ~Tokenizer();
    // set string and delimiter
    void set(const std::string& str, const std::string& delimiter=DEFAULT_DELIMITER);
    void setString(const std::string& str);             // set source string only
    void setDelimiter(const std::string& delimiter);    // set delimiter string only

    std::string next();                                 // return the next token, return "" if it ends

    std::vector<std::string> split();                   // return array of tokens from current cursor
    std::vector<std::string> sort_tokens();             // sort the tokens and return it in a vector
    std::set<std::string> set_of_tokens();              // returns a set of unique tokens

    std::string longest_token();                        // returns the longest token in the string
    std::string find_token(unsigned int n = 0);         // returns the nth element in an sorted list
    bool check_for_duplicates();                        // returns true if there are duplicate tokens
protected:
private:
    void skipDelimiter();                               // ignore leading delimiters
    bool isDelimiter(char c);                           // check if the current char is delimiter

    std::string buffer;                                 // input string
    std::string token;                                  // output string
    std::string delimiter;                              // delimiter string
    std::string::const_iterator currPos;                // string iterator pointing the current position
};

#endif // TOKENIZER_H
