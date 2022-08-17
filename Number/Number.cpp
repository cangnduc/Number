// Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>
#include<conio.h>
#include <iostream>
#include <ctime>
#include <bitset>
////something change
using namespace std;
void PrintBin(bitset<8> a) {
    for (int i = 0; i < 8; i++) {
        cout << a[i];
    }
    cout << endl;
}
int convertBinToDec(bitset<8> a) {

    int numbb = 0;
    for (int i = 0; i < 8;i++) {

        if (a[i] == 1) {
            numbb += (int)pow(2, i);
        }
    }
    return numbb;
}
int s2BinToDec(bitset<8> a) {
    int num = 0;
    for (int i = 0; i < 8;i++) {

        if (a[i] == 1) {
            num += (int)pow(2, i);
            cout << a[i] << " " << i << endl;
        }
        else if (a[i] == 1 && i == 7) {
            num -= (int)pow(2, i);
            cout << a[i];
        }
        

    }
    return num;
}
bitset<8> BitInsert(string str) {
    cout << "Please enter the bin number " << str << ": " << endl;
    string number;
    cin >> number;
    bitset<8> x(number);
    return x;
}

bool checkingBinInRange(bitset<8> a) {
    int numbb = 0;
    for (int i = 0; i < 8;i++) {

        if (a[i] == 1) {
            numbb += (int)pow(2, i);
        }
    }
    if (numbb > 127 || numbb < -128) {
        return false;
    }
    return true;
}
bool* insertBin(string str) {
    bitset<8> x(5);
    cout << "Please enter the bin number: " << str << endl;
    int number;
    cin >> number;
    static bool a[8]={};
    int remainder;
    for (int i = 7; i >= 0;i--) {
        remainder = number % 10;
        if (!remainder) {
            a[i] = 0;
        }
        else {
            a[i] = remainder;
        }

        number = number / 10;
    }
    return a;
}
bitset<8> TimDayBit(int x) {
    bitset<8> a;
    
    int k = 0;
    for (int i = 0; i <8; i++) {
        bool bit = (x >> i) & 1;
        a[k++] = bit;
    }
    return a;
}
int checkNumInRange() {
        
        
    int numb=0;
    do {
        cout << "Please enter the number in decimal (from -128 to 127): " << endl;
        cin >> numb;
    } while (numb > 127 || numb <= -128);
    return numb;
}
bitset<8> ConvertIntToBin() {
    int numb;
    bitset<8> x;
    numb = checkNumInRange();
    x = TimDayBit(numb);
    
    return x;
}
int convertBinToDec() {
    bitset<8> a = BitInsert("");
    int numbb = 0;
    for (int i = 0; i <8;i++) {
        
        if (a[i] == 1) {
           numbb += (int)pow(2,i);
        }
    }
    return numbb;
}
void decToHexa(int n)
{
    int temp = n;
    // char array to store hexadecimal number
    char hexaDeciNum[8] = {};
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
        // storing remainder in temp variable.
        temp = n % 16;
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }
    cout << temp << "(10) is ";
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
    cout << "(hecxadecimal)" << endl;
    
}
void hexadecimalToDecimal()
{
    string hexVal;
    cout << "Please enter Hecxadecimal value: " << endl;
    cin >> hexVal;
    int len = (int)hexVal.length();

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last
    // character
    for (int i = len - 1; i >= 0; i--) {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;

            // incrementing base by power
            base = base << 4;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;

            // incrementing base by power
            base = base <<4;
        }
    }
    cout << hexVal << "(hex) is " << dec_val << "(dec)" << endl;
}
void BinToHex()
{
    int hex[1000] = {};
    int i = 1, j = 0, rem, dec = 0, binaryNumber;
    cout << "Please enter the binary number: " << endl;
    cin >> binaryNumber;
    int temp = binaryNumber;
    while (binaryNumber > 0)
    {
        rem = binaryNumber % 2;
        dec = dec + rem * i;
        i = i * 2;
        binaryNumber = binaryNumber / 10;
    }
    i = 0;
    while (dec != 0)
    {
        hex[i] = dec % 16;
        dec = dec / 16;
        i++;
    }

    cout << temp << "(binary) is ";
    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] > 9)
            cout << (char)(hex[j] + 55) << "\n";
        else
            cout << hex[j];
    }
    cout << "(hexadecimal)" << endl;
}
bitset<8> AddingBinary() {
    bitset<8> a = BitInsert("1");
    bitset<8> b = BitInsert("2");
    bitset<8> c;
    int carry = 0;
    for (int i = 0; i<8; i++) {
        int sum = a[i] + b[i] + carry;
        cout << sum << endl;
        if (sum == 0) {
            c[i] = 0;
            carry = 0;
        }
        else if (sum == 1) {
            c[i] = 1;
            carry = 0;
        }
        else if (sum == 2) {
            c[i] = 0;
            carry = 1;
        }
        else if (sum == 3) {
            c[i] = 1;
            carry = 1;
        }
    }
    
    return c;
}
void Result() {
    int choose =0;
    do {
        cout << "Please enter your choice" << endl;;
        cout << "1. Cover int to Bin" << endl;
        cout << "2. Convert Bin to Int" << endl;
        cout << "3. Convert Decimal to Hexadecimal number" << endl;
        cout << "4. Convert Hexadecimal to Decimal number" << endl;
        cout << "5. Convert Binary to Hexadecimal" << endl;
        cout << "6. Adding 2's Complement Binary of 8bits" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1: {
            cout << "Convert Int To Bin" << endl;
            bitset<8> x = ConvertIntToBin();
            cout << x << endl; 
            break;
        }
        case 2:
        {
            cout << "Convert Bin to Int" << endl;
            int numb;
            
            numb = convertBinToDec();
            cout << numb << endl;
            break;
        }
        case 3: {
            cout << "Please enter the decimal number: " << endl;
            int num = 0;
            cin >> num;
            decToHexa(num);
            break;
        }
        case 4: {
            hexadecimalToDecimal();
            break;
        }
        case 5: {
            BinToHex();
            break;
        }
        case 6:
        {
            bitset<8> kq = AddingBinary();
            cout << kq << endl;
            break;
        }
        case 7: {
            bitset<8> a = BitInsert("");
            int num = s2BinToDec(a);
            cout << num << endl;
            break;
        }
        default:
            cout << "Number is out of range, please enter again: "<< endl;
            break;
        }
    } while (choose != 0);
}

void KetQua() {
    
    bool* a;
    bool* b;
    b = insertBin("2");
    for (int i = 0; i < 8; i++) {

        cout << b[i];
    }
    cout << endl;
    a = insertBin("1");
    for (int i = 0; i < 8; i++) {

        cout << a[i];
    }
}
int main()
{
   

    Result();
    //TimDayBit(42);
    // a pointer to an int.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
