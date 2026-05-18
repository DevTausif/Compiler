#include <iostream>

using namespace std;

// DFA Function
int checkString(char str[])
{
    int state = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        char ch = str[i];

        // q0
        if(state == 0)
        {
            if(ch == 'a')
                state = 1;
            else
                return 0;
        }

        // q1
        else if(state == 1)
        {
            if(ch == 'b')
                state = 2;

            else if(ch == 'a')
                state = 1;

            else
                return 0;
        }

        // q2
        else if(state == 2)
        {
            if(ch == 'b')
                state = 2;

            else if(ch == 'a')
                state = 1;

            else
                return 0;
        }

        i++;
    }

    // Final States
    if(state == 1 || state == 2)
        return 1;

    return 0;
}

int main()
{
    char test1[] = "a";
    char test2[] = "ab";
    char test3[] = "abb";
    char test4[] = "aaabbb";
    char test5[] = "ba";

    cout << test1 << " -> ";
    if(checkString(test1))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    cout << test2 << " -> ";
    if(checkString(test2))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    cout << test3 << " -> ";
    if(checkString(test3))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    cout << test4 << " -> ";
    if(checkString(test4))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    cout << test5 << " -> ";
    if(checkString(test5))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
