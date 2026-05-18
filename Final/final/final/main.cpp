#include<iostream>

using namespace std;



int validateInput(char text[])
{
    int current = 0;

    int position = 0;


    while(text[position] != '\0')
    {
        char value = text[position];




        if(current == 0)
        {
            if(value == 'a')
            {
                current = 1;
            }

            else
            {
                return 0;
            }
        }




        else if(current == 1)
        {
            if(value == 'a')
            {
                current = 1;
            }

            else if(value == 'b')
            {
                current = 2;
            }

            else
            {
                return 0;
            }
        }




        else if(current == 2)
        {
            if(value == 'b')
            {
                current = 2;
            }

            else if(value == 'a')
            {
                current = 1;
            }

            else
            {
                return 0;
            }
        }


        position++;
    }



    if(current == 1 || current == 2)
    {
        return 1;
    }

    return 0;
}





void printAnswer(char sample[])
{
    cout << sample << " -> ";


    if(validateInput(sample))
    {
        cout << "Accepted";
    }

    else
    {
        cout << "Rejected";
    }

    cout << endl;
}




int main()
{
    char input1[] = "a";
    char input2[] = "ab";
    char input3[] = "abb";
    char input4[] = "aaabbb";
    char input5[] = "ba";


    printAnswer(input1);
    printAnswer(input2);
    printAnswer(input3);
    printAnswer(input4);
    printAnswer(input5);


    return 0;
}
