#include <iostream>
#include <fstream>

using namespace std;

// Manual string compare
int compareString(char a[], char b[])
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return 0;

        i++;
    }

    if (a[i] == '\0' && b[i] == '\0')
        return 1;

    return 0;
}

// Check letter
int isLetter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z'))
        return 1;

    return 0;
}

// Check digit
int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;

    return 0;
}

// Keyword check
int isKeyword(char str[])
{
    char k1[] = "int";
    char k2[] = "float";
    char k3[] = "char";
    char k4[] = "if";
    char k5[] = "else";
    char k6[] = "return";

    if (compareString(str, k1)) return 1;
    if (compareString(str, k2)) return 1;
    if (compareString(str, k3)) return 1;
    if (compareString(str, k4)) return 1;
    if (compareString(str, k5)) return 1;
    if (compareString(str, k6)) return 1;

    return 0;
}

// Identifier check
int isIdentifier(char str[])
{
    int i = 0;

    if (!(isLetter(str[0]) || str[0] == '_'))
        return 0;

    i = 1;

    while (str[i] != '\0')
    {
        if (!(isLetter(str[i]) ||
              isDigit(str[i]) ||
              str[i] == '_'))
        {
            return 0;
        }

        i++;
    }

    return 1;
}

// Print token type
void identifyToken(char token[])
{
    if (isKeyword(token))
    {
        cout << token << " -> Keyword" << endl;
    }
    else if (isIdentifier(token))
    {
        cout << token << " -> Identifier" << endl;
    }
    else
    {
        cout << token << " -> Invalid Token" << endl;
    }
}

// Print file content
void printFile()
{
    ifstream file("E:\\Compiler\\MID\\mid\\myfile.txt");

    char ch;

    cout << "File Content:\n";

    while (file >> noskipws >> ch)
    {
        cout << ch;
    }

    file.close();
}

// Process tokens
void processFile()
{
    ifstream file("E:\\Compiler\\MID\\mid\\myfile.txt");

    char ch;
    char token[100];

    int index = 0;

    cout << "\n\nToken Identification:\n";

    while (file >> noskipws >> ch)
    {
        if (ch == ' ' ||
            ch == '\n' ||
            ch == ';' ||
            ch == '(' ||
            ch == ')' ||
            ch == '{' ||
            ch == '}' ||
            ch == ',')
        {
            if (index > 0)
            {
                token[index] = '\0';

                identifyToken(token);

                index = 0;
            }
        }
        else
        {
            token[index] = ch;
            index++;
        }
    }

    if (index > 0)
    {
        token[index] = '\0';

        identifyToken(token);
    }

    file.close();
}

int main()
{
    printFile();

    processFile();

    return 0;
}

