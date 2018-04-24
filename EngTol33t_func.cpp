#include "l33tmain.h"

#include <string>
#include <iostream>
#include <vector>
#include <QApplication>


using namespace std;

//LeetMain::alphabet=1337;

//engalphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
//LeetMain::numbers={"O", "I", "Z", "E", "h","S","G","T","B", "P"};




string convert_alpha(char a){ //function converts letters to corresponding l33t symbol
    std::string alphabet[]={"@","8","<","|}","3","|#","6","{=}","1","_}","|{","|_","(\\/)","|\\|","{}","|*","(,)","Я","5","+","[_]","\\/","(/\\)","%","`/",">_"};
    return alphabet[((int) tolower(a)) - 97]; //finds index and returns corresponding l33t symbol
}
