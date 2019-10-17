

//The goal of this program is to take character and binary input and translate it to the other

#include <iostream>
#include <string>
using namespace std;

string translateLetters(string input);
string translateBinary(string input);

class Letter
{
public:
    Letter(char c);
    Letter(string bi);
    string fillBinary();
    char fillChar();
    
    char m_letter;
    string m_binary;
};

Letter::Letter(char c)
{
    m_letter = c;
    m_binary = fillBinary();
}

Letter::Letter(string bi)
{
    m_binary = bi;
    m_letter = fillChar();
}

string Letter::fillBinary()
{
    string toReturn;
    if (m_letter == ' ')
        return "00000";
    int value = (m_letter - 'a' + 1);
    
    if (value >= 16)
    {
        toReturn += '1';
        value -= 16;
    }
    else
        toReturn += '0';
    
    if (value >= 8)
    {
        toReturn += '1';
        value -= 8;
    }
    else
        toReturn += '0';
    
    if (value >= 4)
    {
        toReturn += '1';
        value -= 4;
    }
    else
        toReturn += '0';
    
    if (value >= 2)
    {
        toReturn += '1';
        value -= 2;
    }
    else
        toReturn += '0';
    
    if (value >= 1)
    {
        toReturn += '1';
        value -= 1;
    }
    else
        toReturn += '0';
    
    return toReturn;
}

char Letter::fillChar()
{
    int value = 0;
    int j = 1;
    for (int i = 4; i >=0; i--)
    {
        value += ( (m_binary[i] - '0') * j);
        j *= 2;
    }
    if (value == 0)
        return ' ';
    return ('a' + value - 1);
    
}

int main()
{
    cout << "Enter your text: " << endl;
    string inpt;
    getline(cin, inpt);
    
    if (inpt[0] == '1' || inpt[0] == '0')
    {
        Letter* text[inpt.size()/5];
        int k = 0, i = 0;
        while (k < (inpt.size() - (inpt.size()%5) ))
        {
            text[i] = new Letter(inpt.substr(k, 5));
            k += 5;
            i++;
        }
        
        for (int j = 0; j < inpt.size()/5; j++)
        {
            cout << text[j]->m_letter;
            delete text[j];
        }
    }
    else
    {
        Letter* text[inpt.size()];
        int k = 0;
        while (k < inpt.size())
        {
            text[k] = new Letter(tolower(inpt[k]));
            k++;
        }
        
        for (int j = 0; j < inpt.size(); j++)
        {
            cout << text[j]->m_binary;
            delete text[j];
        }
    }
    cout << endl;
}





