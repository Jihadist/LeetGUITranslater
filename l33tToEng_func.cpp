#include "l33tmain.h"

#include <string>

#include <iostream>
//#include <conio.h>

#include <QDebug>

using namespace std;

//std::string numbers[]={"O", "I", "Z", "E", "h","S","G","T","B", "P"};


//std::string convert_alpha(char a){ //function converts letters to corresponding l33t symbol
//    return alphabet[((int) tolower(a)) - 97]; //finds index and returns corresponding l33t symbol
//}

std::string convert_alpha_from_leet (std::string TempAlpha,//Временная строка,  куда копируется CharSize элементов
                                unsigned int Size,//Длина строки TempAlpha
                                std::string InputTextString,//Входная строка в leet
                                std::string Alpha,//Символ из алфавита leet
                                std::string engAlpha,//Символ латинского алфавита
                                unsigned int Pos,//Текущая позиция цикла в слове по слову InputTextString
                                unsigned int PosJ){//Текущая позиция цикла по алфавиту
    if (InputTextString.length()-Pos>=Size)//Условие проверки четырех элементов
    {

        for (unsigned int k=0;k<Size;k++)
            TempAlpha.push_back(InputTextString[Pos+k]);//Копирование во временную строку CharSize символов из строки InputTextString начиная с позиции Pos+k
        //cout<<"temp"<<Size<<": "<<TempAlpha<<endl<<"current iterator : "<<PosJ<<endl;//Вывод текущей временной строки и итератора

//        if (Size==1)
//        {
//            //char *c=TempAlpha.c_str();
//            if (isspace(TempAlpha[0]))
//                return " ";
//        }
               //return " ";
        if (TempAlpha==Alpha)//Если временная строка равна символу алфавита, то на вывод отправляем символ алфавита
        {
          return engAlpha;
        }

        return "";
    }
//return "error";
}

unsigned int ENGSIZE=26;
unsigned int UMSIZE=10;
//string convert_digit(char a){ //function converts letters to corresponding l33t symbol
//    return numbers[int(a)]; //finds index and returns corresponding l33t symbol
//}

std::string l33t(std::string l33tIn)
{

    std::string alphabet[] ={"@","8","<","|}","3","|#","6","{=}","1","_}","|{","|_","(\\/)","|\\|","{}","|*","(,)","Я","5","+","[_]","\\/","(/\\)","%","`/",">_"};
    std::string engalphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    string l33tOut;
    //getline(cin,l33tIn);
    unsigned int CharSize;
    //cout<<l33tIn<<endl;

        for (unsigned int i=0;i<l33tIn.length();i++)//Цикл для прохода всей строки
        {
            //cout<<"Character "<<i<<" : "<<l33tIn[i]<<endl;//Выводит текущий итератор и текущий символ

                    for (unsigned int j=0;j<ENGSIZE;j++)//Цикл перебора всех элементов алфавита
                    {

                        string temp;//Временная строка, куда копируются текущие исследуемые элементы
                        string TempFunc;

                        //
                        for (CharSize=4; CharSize>0;CharSize--)
                        {
                            TempFunc=convert_alpha_from_leet(temp,CharSize,l33tIn,alphabet[j],engalphabet[j],i,j);

                            if (!TempFunc.empty())
                                    {
                                        l33tOut+=TempFunc;
                                        //cout<<"String is not empty"<<endl;
                                        TempFunc.clear();
                                        i+=CharSize-1;
                                        break;
                                    }//Working

                            temp.clear();

                        }


                    }

        }
        //cout<<"RAW Text:"<<l33tOut<<endl;

//_getch();
return l33tOut;
}
