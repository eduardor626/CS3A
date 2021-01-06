// istream::peek example
#include <iostream>     // cin, cout
#include <string>       // string
#include <cctype>       // isdigit

using namespace std;

int main () {

  cout << "Please, enter a number or a word: ";
  cout.flush();    // ensure output is written
  //continues until user has entered something

  cin >> ws;  // eat up any leading white spaces

  /*In the default locale, the whitespace characters are the following:
  space ( 0x20 , ' ')
  form feed ( 0x0c , '\f')
  line feed ( 0x0a , '\n')
  carriage return ( 0x0d , '\r')
  horizontal tab ( 0x09 , '\t')
  vertical tab ( 0x0b , '\v')
  */

  int c = cin.peek();  // peek character
  //returns the decimal value of ascii table of the character

  if ( c == EOF ) return 1;
  if ( isdigit(c) )
  {
    int n;
    cin >> n;
    cout << "You entered the number: " << n << '\n';
  }
  else
  {
    string str;
    cin >> str;
    cout << "You entered the word: " << str << '\n';
  }

  return 0;
}
