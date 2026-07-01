#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void makeBits(int value, int digits[]);
void writeBits(ofstream &outFile, int digits[]);

int number;
int i;

int main()
{
    ifstream inFile;
    ofstream outFile;
    int value;
    int digits[32];
    cout << "enter an integer: ";
    cin >> value; 
    makeBits(value, digits);
    for (i = 31; i >= 0; i--)
    {
        cout << "array:" << digits[0] << endl << digits[1] << endl << digits[2] << endl << digits[3] << endl;
        //if (i == 23 || i == 16 || i == 9)
        //{
            //outFile << " ";
        //} 
    }
    



    return 0;


}


void makeBits(int value, int digits[])
{
    int modulus_number;
    int quotent_number;
    int quotent_answer;
    int binary_digit;
    int i;
    cout << "first binary: "<< binary_digit << endl;

    modulus_number = value;
    cout << "Mod number: "<< modulus_number << endl;
    quotent_number = value;
    cout << "Quotent value: "<< quotent_number << endl;

    quotent_answer = quotent_number / 2;
    binary_digit = modulus_number % 2;
    while (quotent_answer > 0)
    {
        for (i = 0; i <= 31; i++)
        {
            if (binary_digit > 0)
            {
                digits[i] = 1;
                quotent_answer /=2;
                binary_digit %=2;
                cout << quotent_answer;
            }
            else if (binary_digit <= 0)
            {
                digits[i] = 0;
                quotent_answer /=2;
                binary_digit %=2;
            }


        }

    }



}
//            binary_digit = modulus_number % 2;
//            cout << "2                 Binary Digit: "<< binary_digit << endl;
//            quotent_answer = quotent_number / 2;
//            cout << "2Quotent Answer: "<< quotent_answer << endl;
            if (binary_digit = 1)
            {
                digits[i] = 1;
            }
            else if (binary_digit = 0)
            {
                digits[i] = 0;
            }
            quotent_answer /=2;
            binary_digit = quotent_answer % 2;
            cout << "2Binary Digit: "<< binary_digit << endl;
            cout << "2Quotent Answer: "<< quotent_answer << endl;