#include<iostream>
#include<fstream>

using namespace std;



int checkLetter(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return 1;

    if(ch >= 'A' && ch <= 'Z')
        return 1;

    return 0;
}



int checkDigit(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;

    return 0;
}



int sameString(char a[], char b[])
{
    int i = 0;

    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
            return 0;

        i++;
    }

    if(a[i] == '\0' && b[i] == '\0')
        return 1;

    return 0;
}



int checkKeyword(char word[])
{
    char kw1[] = "int";
    char kw2[] = "float";
    char kw3[] = "char";
    char kw4[] = "if";
    char kw5[] = "else";
    char kw6[] = "return";

    if(sameString(word, kw1))
        return 1;

    if(sameString(word, kw2))
        return 1;

    if(sameString(word, kw3))
        return 1;

    if(sameString(word, kw4))
        return 1;

    if(sameString(word, kw5))
        return 1;

    if(sameString(word, kw6))
        return 1;

    return 0;
}



int checkIdentifier(char word[])
{
    int i = 0;

    if(!(checkLetter(word[0]) || word[0] == '_'))
        return 0;

    i = 1;

    while(word[i] != '\0')
    {
        if(!(checkLetter(word[i]) ||
             checkDigit(word[i]) ||
             word[i] == '_'))
        {
            return 0;
        }

        i++;
    }

    return 1;
}



void showToken(char word[])
{
    if(checkKeyword(word))
    {
        cout << word << " is Keyword" << endl;
    }

    else if(checkIdentifier(word))
    {
        cout << word << " is Identifier" << endl;
    }

    else
    {
        cout << word << " is Invalid" << endl;
    }
}




void displayFile()
{
    ifstream inputFile("E:\\Compiler\\MID\\mid\\myfile.txt");

    char ch;

    cout << "File Content :" << endl << endl;

    while(inputFile >> noskipws >> ch)
    {
        cout << ch;
    }

    inputFile.close();
}




void tokenProcess()
{
    ifstream inputFile("E:\\Compiler\\MID\\mid\\myfile.txt");

    char ch;
    char word[100];

    int pos = 0;

    cout << endl;
    cout << endl;
    cout << "Detected Tokens :" << endl << endl;

    while(inputFile >> noskipws >> ch)
    {
        if(ch == ' '  ||
           ch == '\n' ||
           ch == ';'  ||
           ch == '('  ||
           ch == ')'  ||
           ch == '{'  ||
           ch == '}'  ||
           ch == ',')
        {
            if(pos > 0)
            {
                word[pos] = '\0';

                showToken(word);

                pos = 0;
            }
        }

        else
        {
            word[pos] = ch;

            pos++;
        }
    }


    if(pos > 0)
    {
        word[pos] = '\0';

        showToken(word);
    }

    inputFile.close();
}



int main()
{
    displayFile();

    tokenProcess();

    return 0;
}
