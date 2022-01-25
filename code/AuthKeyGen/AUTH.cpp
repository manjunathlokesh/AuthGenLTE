#include "AUTH.hpp"


void f1(const unsigned128bit XDOUT,const unsigned64bit CDOUT, unsigned64bit * MAC) 
{
    for (int i = 0; i < 8; i++) 
    {
        MAC -> data[i] = XDOUT.data[i] ^ CDOUT.data[i];
    }
}

void f4(unsigned48bit * AK,const unsigned128bit XDOUT) 
{
    int j = 0;
    for (int i = 3; i < 9; i++) 
    {
        AK -> data[j] = XDOUT.data[i];
        j++;
    }
}

void Authgen(const unsigned48bit SQN,const unsigned48bit AK,const unsigned16bit AMF,const unsigned64bit MAC, unsigned128bit * AUTH) 
{
    int index = 0;
    for (int i = 0; i < 6; i++) 
    {
        AUTH -> data[i] = SQN.data[i] ^ AK.data[i];
    }
    for (int j = 6; j < 8; j++) 
    {
        AUTH -> data[j] = AMF.data[index++];
    }
    index = 0;
    for (int k = 8; k < 16; k++) 
    {
        AUTH -> data[k] = MAC.data[index++];
    }
}
