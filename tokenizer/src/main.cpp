// testing Tokenizer class

#include "Tokenizer.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // instantiate Tokenizer class
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
    str.set("Now,~the_delimiters~~~are__changed~to_tilde  and  underscore.~", "~_");
    while((token = str.next()) != "")
    {
        ++counter;
        cout << counter << ": " << token << endl;
    }

    cout << endl << "*** demonstrate Tokenizer's sort  ***" << endl;
    str.set("Now,~the_delimiters~~~are__changed~to_tilde  and  underscore.~", "~_");
    vector<string> sv = str.sort_tokens();
    cout << "SV size: " << sv.size() << endl;
    // Using integer index to print
    counter = 0;
    for ( unsigned int i = 0; i < sv.size(); i++ )
    	cout << ++counter << ": " << sv[ i ] << endl;

    cout << endl << "*** demonstrate Tokenizer's longest method  ***" << endl;
    str.set("This is a simple test~ for finding longest token_ and shortest_ and shorter", "~_");
    string longest = str.longest_token();
    cout << "longest: " << longest << endl;

    cout << endl << "*** demonstrate Tokenizer's longest method 2 ***" << endl;
    str.set("Zebb~Now,~bad*_zeal_Zeal", "~_");
    longest = str.longest_token();
    cout << "longest: " << longest << endl;

    // demonstrate the ability of the set to only retain unique strings
    cout << endl << "*** demonstrate the ability of the"
    		<< " set to only retain unique strings  ***" << endl;

    str.set("Zebb~Now,~bad*_zeal_Zeal~ duplicate coming ~Zebb~Now,~bad*_zeal_Zeal", "~_");
    set<string> st = str.set_of_tokens();
    cout << "set size: " << st.size() << endl;

    counter = 0;
    for (set<string>::iterator pos = st.begin();
    		pos != st.end();
    		pos++ )
    {
    	++counter;
    	token = *pos;
    	cout << counter << ": " << token << endl;
    }

    //
    // check for duplicates in a quick manner. How?
    cout << endl << "*** demonstrate the ability to check for duplicates  ***" << endl;
    str.set("Zebb~Now,~bad*_zeal_Zeal~ duplicate coming ~Zebb~Now,~bad*_zeal_Zeal", "~_");
    bool dupe = str.check_for_duplicates();
    cout << "Duplicates? " << ((dupe == true)? "yes!" :  "no!") << endl;

    // find the nth token in the list of tokens
    cout << endl << "*** demonstrate the ability to select the nth element  ***" << endl;
    str.set("thre5 eight10101 seven9999 five777 two4 four66 six88888 on3 four66");
    counter = 0;
    vector<string> sv2 = str.split();
    for ( unsigned int i = 0; i < sv2.size(); i++ )
    	cout << ++counter << ": " << sv2[ i ] << endl;
    counter = 0;
    cout << "----------------------\n";
    for ( unsigned int i = 0; i < sv2.size(); i++ ){
       	cout << ++counter << ": " << str.find_token(i) << endl;
    }

    return 0;
}
