#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
typedef struct UnsignedChar128 
{
    unsigned char data[16] { 0X00 };

} unsigned128bit;
typedef struct UnsignedChar64 
{
    unsigned char data[8] { 0X00 };

} unsigned64bit;
typedef struct UnsignedChar48 
{
    unsigned char data[6] { 0X00 };

} unsigned48bit;
typedef struct UnsignedChar16 
{
    unsigned char data[2] { 0X00 };

} unsigned16bit;

//Prototypes of all the functions used in the program.
void f1(const unsigned128bit XDOUT, const unsigned64bit CDOUT, unsigned64bit* MAC);
void f4(unsigned48bit* AK, const unsigned128bit XDOUT);
void Authgen(const unsigned48bit SQN, const unsigned48bit AK, const unsigned16bit AMF, const unsigned64bit MAC, unsigned128bit* AUTH);
