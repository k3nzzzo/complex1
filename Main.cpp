#include <iostream>
#include "Complex.h"
#include <fstream>
int main()
{
    ifstream fileToRead;
    fileToRead.open("D:\\бсг\\нно\\complex.txt");

    if (!fileToRead)
    {
        return -1;
    }

    string number;
    getline(fileToRead, number);
    int n = stoi(number);


    Complex* p = new Complex[n];

    for (int i = 0; i<n;i++)
    {
        string line;
        getline(fileToRead, line);
        p[i] = Complex::string2Complex(line);
    }
    fileToRead.close();

    double maxAbs = p[0].abs();
    int maxPos = 0;
    for (int i = 1; i < n;i++)
    {
        double currentAbs = p[i].abs();
        if (currentAbs > maxAbs)
        {
            maxAbs = currentAbs;
            maxPos = i;
        }
        
    }
    cout << "Number with max abs is ";
    p[maxPos].printComplex();
    cout << endl;

    return 0;
}