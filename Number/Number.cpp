
#include <iostream>
#include <bitset>
#include <string>
#include <conio.h>
using namespace std;
template <size_t N1, size_t N2>
bitset <N1 + N2> concat(const bitset <N1>& b1, const bitset <N2>& b2) {
    string s1 = b1.to_string();
    string s2 = b2.to_string();
    return bitset <N1 + N2>(s1 + s2);
}
bitset<17> adding17Bin(bitset<17>a, bitset<16>b) {

    bitset<17> c;
    int carry = 0;
    for (int i = 0; i < 16; i++) {
        int sum = a[i] + b[i] + carry;

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
    if (carry == 1) {
        c[16] = 1;
    }

    return c;
}
bitset<17> MultiplyBinary(bitset<8> M, bitset<8> Q) {
    int n = 8;
    int k = 0;
    bitset<2 * 8 + 1> CAQ(Q.to_string());
    bitset<8> A;
    while (k < 8) {

        if (Q[0] == 1) {
            CAQ = adding17Bin(CAQ, concat(M, A));
        }
        CAQ = CAQ >> 1;
        Q = Q >> 1;
        k = k + 1;
    }

    return CAQ;
}

void PrintBin(bitset<8> a) {
    for (int i = 0; i < 8; i++) {
        cout << a[i];
    }
    cout << endl;
}
// ham nhan vao so nhi phan
bitset<8> BitInsert(string str) {
    cout << "Please enter the bin number " << str << ": " << endl;
    string number;
    cin >> number;
    bitset<8> x(number);
    return x;
}
// ham doi he 2( so ko dau ) sang he 10
template <size_t T>
int convertBinToDec(bitset<T> a) {

    int numbb = 0;
    for (int i = 0; i < T;i++) {

        if (a[i] == 1) {
            numbb += (int)pow(2, i);
        }
    }
    return numbb;
}
int convertBinToDec() {
    bitset<8> a = BitInsert("");
    int numbb = 0;
    for (int i = 0; i < 8;i++) {

        if (a[i] == 1) {
            numbb += (int)pow(2, i);
        }
    }
    return numbb;
}
// ham convert he 2( dang bu 2) sang he 10
template <size_t A>
int s2BinToDec(bitset<A> a) {
    int num = 0;
    for (int i = 0; i < A;i++) {
        if (a[i] == 1 && i == A-1) {
            int temp = (int)pow(2, i) * -1;
            num += temp;
        }
        else if (a[i] == 1) {
            num += (int)pow(2, i);
        }
    }
    return num;
}

template<size_t s2zise>
// ham doi tu so ko dau sang bu 2
bitset<s2zise> s2BinaryMinus(bitset<s2zise> a) {
    a = a.flip();
    int carry = 1;
    for (int i = 0; i< s2zise;i++) {
        if (carry == 1 && a[i]==0) {
            a[i] = 1;
            carry = 0;
        }
        else if (carry == 1 && a[i] == 1) {
            a[i] = 0;
            carry = 1;

        }
        else if (carry == 0 && a[i] == 1) {
            a[i] = 1;
            carry = 0;
        }
        else if(carry == 0 && a[i] == 0) {
            a[i] = 0;
            carry = 0;
        }
    }
    return a;
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
// ham doi tu he 10 sang he 2
bitset<8> TimDayBit(int x) {
    bitset<8> a;
    int k = 0;
    for (int i = 0; i <8; i++) {
        bool bit = (x >> i) & 1;
        a[k++] = bit;
    }
    return a;
}
// ham kiem tra so dau vao
int checkNumInRange() {
        
        
    int numb=0;
    do {
        cout << "Please enter the number in decimal (from 0 to 255): " << endl;
        cin >> numb;
    } while (numb > 255 || numb <= 0);
    return numb;
}
// ham doi tu he 10 sang he 2
bitset<8> ConvertIntToBin(int numb) {
    
    bitset<8> x;
    
    x = TimDayBit(numb);
    
    return x;
}
// ham doi tu he 10 sang he 16
void decToHexa(int n)
{
    int temp = n;
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
// ham doi tu he 16 sang he 10
void hexadecimalToDecimal()
{
    string hexVal;
    cout << "Please enter Hecxadecimal value: " << endl;
    cin >> hexVal;
    int len = (int)hexVal.length();
    int base = 1;
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from ASCII value
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base << 4;
        }
        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            // incrementing base by power
            base = base <<4;
        }
    }
    cout << hexVal << "(hex) is " << dec_val << "(dec)" << endl;
}
// ham doi tu so nhi phan sang 16
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
// ham cong 2 so nhi phan
template <size_t addzie>
bitset<addzie> AddingBinary(bitset<addzie> a, bitset<addzie> b) {
    
    bitset<addzie> c;
    int carry = 0;
    for (int i = 0; i<addzie; i++) {
        int sum = a[i] + b[i] + carry;
       
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
//Ham Nhan 2 so nhi phan
void handleMultiphy() {
    
    bitset<8>M =BitInsert("1");
    int a = s2BinToDec(M);
    bitset<8>Q = BitInsert("2");
    int b = s2BinToDec(Q);
    bitset<17> KQ = MultiplyBinary(M, Q);
    int kqint = convertBinToDec(KQ);
    cout << M << "(" << a << ") * " << Q << "(" << b << ") = " << KQ << "(" << kqint <<")" << endl;;
}
//Ham - 2 so nhi phan
template <size_t subnum>
bitset<subnum> SubtractBinary(bitset<subnum> a, bitset<subnum> b) {
    // convert so không dau sang bu 2
    bitset<subnum>c = s2BinaryMinus(b);

    bitset<subnum> kq = AddingBinary(a, c);
    return kq;
}
// Ham chia 2 so nhi phan
template<size_t sizeD>
void BinaryDivision(bitset<sizeD>Q, bitset<sizeD>M) {
    int k = sizeD;
    bitset<sizeD>temp;
    bitset<sizeD *2>AQ = concat(temp, Q);
    while (k > 0) {
        AQ = AQ << 1;
        bitset<sizeD> A(AQ.to_string().substr(0, sizeD));
       
        bitset<sizeD> temp = SubtractBinary(A, M);
        int x = s2BinToDec(temp);
       
        if ( x>=0) {
            AQ.set(0, 1);
            for (int i = 0; i < sizeD;i++) {
                AQ.set(i + sizeD, temp[i]);
            }   
        }
        k = k - 1;
    }
    int intQ = s2BinToDec(Q);
    int intM = s2BinToDec(M);
    bitset<sizeD> remain(AQ.to_string().substr(0, sizeD));
    bitset<sizeD> KQ(AQ.to_string().substr(sizeD, sizeD*2));
    int remainder = s2BinToDec(remain);
    int intKQ = s2BinToDec(KQ);
    cout << Q << "(" << intQ << ") / " << M << "(" << intM << ") = " << KQ << "(" << intKQ << "). So du: " << remain << "(" << remainder << ")" << endl;
    cout <<"AQ = " << AQ << endl;
    
}
// quan ly ket qua ham chia 2 so binary
void HandleDivision() {
    bitset<8>a = BitInsert("1");
    bitset<8>b = BitInsert("2");
    while (s2BinToDec(a) < s2BinToDec(b)) {
        cout << "KQ =" << 0 << ".So du: " << a << "(" << s2BinToDec(a) << ")" << endl;
        cout << "Number 1 must be bigger number 2" << endl;
        a = BitInsert("1");
        b = BitInsert("2");
    }
    BinaryDivision(a, b);
}
// Clear console screen sau moi method
void ClearS()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
//Quan ly ket qua in ra mang hinh
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
        cout << "7. Substract 2's Complement Binary of 8bits" << endl;
        cout << "8. Multiply of 2's Complement Binary of 8bits" << endl;
        cout << "9. Division of 2's Complement Binary of 8bits" << endl;
        cin >> choose;
        ClearS();
        switch (choose)
        {
        case 1: {
            cout << "Convert Int To Bin" << endl;
            int num = checkNumInRange();
            bitset<8> x = ConvertIntToBin(num);
            cout << num<<"(decimal) = "<< x<<"(bin)" << endl;
            break;
        }
        case 2:
        {
            
            cout << "Convert Bin to Int" << endl;
            bitset<8> a = BitInsert("");
            int numb;
            
            numb = convertBinToDec(a);
            cout <<a<<"(bin) = " << numb<<"(int)" << endl;
            break;
        }
        case 3: {
            cout << "Convert Decimal to Hexadecimal:" << endl;
            cout << "Please enter the decimal number: " << endl;
            int num = 0;
            cin >> num;
            decToHexa(num);
            break;
        }
        case 4: {
            cout << "Convert Hexadecimal to Decimal." << endl;
            hexadecimalToDecimal();
            break;
        }
        case 5: {
            cout << "Convert Binary to Hexadecimal" << endl;
            BinToHex();
            break;
        }
        case 6:
        {
            cout << "Adding 2 binary number" << endl;
            bitset<8> a = BitInsert("1");
            bitset<8> b = BitInsert("2");
            bitset<8> kq = AddingBinary(a,b);
            int aint = s2BinToDec(a);
            int bint = s2BinToDec(b);
            int kqint = s2BinToDec(kq);
            cout <<a<<"("<<aint<<") + "<<b<<"("<<bint<<") = "<< kq<<"("<<kqint<<")" << endl;
            break;
        }
        case 7: {
            cout << "Subtract 2 binary number" << endl;
            bitset<8> a = BitInsert("1");
            bitset<8> b = BitInsert("2");
            int inta = convertBinToDec(a);
            int intb = s2BinToDec(b);

            bitset<8>c = s2BinaryMinus(b);
            
            bitset<8> kq = AddingBinary(a,c);
            int intkq = s2BinToDec(kq);
            cout <<a<<"("<<inta<<") - "<<b<<"("<<intb<<") = " << kq<<"("<<intkq<<")" << endl;
            break;
        }
        case 8: {
            cout << "Multiply of 2 binary number" << endl;
            handleMultiphy();
        }
        case 9: {
            cout << "Division of 2 binary number" << endl;
            HandleDivision();
            break;
        }
        default:
            cout << "Number is out of range, please enter again: "<< endl;
            break;
        }
    } while (choose != 0);
}
int main()
{
    Result();
}
