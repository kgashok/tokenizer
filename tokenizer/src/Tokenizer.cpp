///////////////////////////////////////////////////////////////////////////////
// Tokenizer.cpp
// =============
// General purpose string tokenizer (C++ string version)
//
// The default delimiters are space(" "), tab(\t, \v), newline(\n),
// carriage return(\r), and form feed(\f).
// If you want to use different delimiters, then use setDelimiter() to override
// the delimiters. Note that the delimiter string can hold multiple characters.
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2005-05-25
// UPDATED: 2011-03-08
///////////////////////////////////////////////////////////////////////////////

#include "Tokenizer.h"
#include <iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////
// constructor
///////////////////////////////////////////////////////////////////////////////
Tokenizer::Tokenizer() : buffer(""), token(""), delimiter(DEFAULT_DELIMITER)
{
    currPos = buffer.begin();
}

Tokenizer::Tokenizer(const std::string& str, const std::string& delimiter) : buffer(str), token(""), delimiter(delimiter)
{
    currPos = buffer.begin();
}



///////////////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////////////
Tokenizer::~Tokenizer()
{
}



///////////////////////////////////////////////////////////////////////////////
// reset string buffer, delimiter and the currsor position
///////////////////////////////////////////////////////////////////////////////
void Tokenizer::set(const std::string& str, const std::string& delimiter)
{
    this->buffer = str;
    this->delimiter = delimiter;
    this->currPos = buffer.begin();
}

void Tokenizer::setString(const std::string& str)
{
    this->buffer = str;
    this->currPos = buffer.begin();
}

void Tokenizer::setDelimiter(const std::string& delimiter)
{
    this->delimiter = delimiter;
    this->currPos = buffer.begin();
}



///////////////////////////////////////////////////////////////////////////////
// return the next token
// If cannot find a token anymore, return "".
///////////////////////////////////////////////////////////////////////////////
std::string Tokenizer::next()
{
    if(buffer.size() <= 0) return "";           // skip if buffer is empty

    token.clear();                              // reset token string

    this->skipDelimiter();                      // skip leading delimiters

    // append each char to token string until it meets delimiter
    while(currPos != buffer.end() && !isDelimiter(*currPos))
    {
        token += *currPos;
        ++currPos;
    }
    return token;
}



///////////////////////////////////////////////////////////////////////////////
// skip ang leading delimiters
///////////////////////////////////////////////////////////////////////////////
void Tokenizer::skipDelimiter()
{
    while(currPos != buffer.end() && isDelimiter(*currPos))
        ++currPos;
}


///////////////////////////////////////////////////////////////////////////////
// return true if the current character is delimiter
///////////////////////////////////////////////////////////////////////////////
bool Tokenizer::isDelimiter(char c)
{
    return (delimiter.find(c) != std::string::npos);
}



///////////////////////////////////////////////////////////////////////////////
// split the input string into multiple tokens
// This function scans tokens from the current cursor position.
///////////////////////////////////////////////////////////////////////////////
std::vector<std::string> Tokenizer::split()
{
    std::vector<std::string> tokens;
    std::string token;
    while((token = this->next()) != "")
    {
        tokens.push_back(token);
    }

    return tokens;
}
/*
 *  Method: Tokenizer::sort_tokens
 *  Params:
 * Returns: std::vector<std::string>
 * Effects:
 */
std::vector<std::string>
Tokenizer::sort_tokens()
{
    std::vector<std::string> dummy;

    cerr << "Tokenizer::sort_tokens()" << endl;
    return dummy;
}


/*
 *  Method: Tokenizer::set_of_tokens
 *  Params:
 * Returns: std::set<std::string>
 * Effects:
 */
std::set<std::string>
Tokenizer::set_of_tokens()
{
    std::set<std::string> dummy;

    cerr << "Tokenizer::set_of_tokens()" << endl;
    return dummy;
}


/*
 *  Method: Tokenizer::longest_token
 *  Params:
 * Returns: std::string
 * Effects:
 */
std::string
Tokenizer::longest_token()
{
    std::string dummy;

    cerr << "Tokenizer::longest_token()" << endl;
    return dummy;
}


/*
 *  Method: Tokenizer::find_token
 *  Params: unsigned int n
 * Returns: std::string
 * Effects:
 */
std::string
Tokenizer::find_token(unsigned int n)
{
    std::string dummy;

    cerr << "Tokenizer::find_token()" << endl;
    return dummy;
}


/*
 *  Method: Tokenizer::check_for_duplicates
 *  Params:
 * Returns: bool
 * Effects:
 */
bool
Tokenizer::check_for_duplicates()
{
    bool dummy;

    cerr << "Tokenizer::check_for_duplicates()" << endl;
    return dummy;
}

std::map<int, string> Tokenizer::build_map() {
    std::map<int, string> dummy;

    cerr << "Tokenizer::build_map()" << endl;
	return dummy;
}
