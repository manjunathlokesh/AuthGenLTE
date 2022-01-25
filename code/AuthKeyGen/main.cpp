#include "AUTH.hpp"

int main() 
{
    unsigned128bit K;
    unsigned128bit XDOUT;
    unsigned128bit RAND;
    unsigned48bit AK;
    unsigned64bit CDOUT;
    unsigned48bit SQN;
    unsigned16bit AMF;
    unsigned64bit MAC;
    unsigned128bit AUTH;

    AMF.data[0] = 0x80;
    int j = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 6)
            CDOUT.data[i] = SQN.data[i];
        else {
            CDOUT.data[i] = AMF.data[j];
            j++;
        }
    }
    unsigned char temp = 0x00;
    for (int i = 0; i < 16; i++) 
    {
        K.data[i] = temp;
        temp = temp + 0x11;
    }
    cout << "k    :";
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", K.data[i]);
    }
    cout << endl;
    cout << "RAND :";
    srand(time(0));

    RAND.data[0] = 0x31;
    RAND.data[1] = 0x32;
    RAND.data[2] = 0x31;
    RAND.data[3] = 0x31;
    RAND.data[4] = 0x35;
    RAND.data[5] = 0x38;
    RAND.data[6] = 0x36;
    RAND.data[7] = 0x34;
    RAND.data[8] = 0x31;
    RAND.data[9] = 0x32;
    RAND.data[10] = 0x31;
    RAND.data[11] = 0x31;
    RAND.data[12] = 0x35;
    RAND.data[13] = 0x38;
    RAND.data[14] = 0x36;
    RAND.data[15] = 0x34;
    // for(int i = 0; i < 16; i++)
    //{
    // RAND.data[i] = (rand() % 127);
    //}
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", RAND.data[i]);
    }
    cout << endl;
    cout << "XDOUT:";
    for (int i = 0; i < 16; i++)
        XDOUT.data[i] = K.data[i] ^ RAND.data[i];
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", XDOUT.data[i]);
    }
    cout << endl;
    f4( & AK, XDOUT);
    cout << "AK   :";
    for (int i = 0; i < 6; i++) 
    {
        printf("%02X", AK.data[i]);
    }
    cout << endl;
    cout << "CDOUT:";
    for (int i = 0; i < 8; i++) 
    {
        printf("%02X", CDOUT.data[i]);
    }
    cout << endl;
    f1(XDOUT, CDOUT, & MAC);
    cout << "MAC  :";
    for (int i = 0; i < 8; i++) 
    {
        printf("%02X", MAC.data[i]);
    }
    cout << endl;
    Authgen(SQN, AK, AMF, MAC, & AUTH);
    cout << "AUTH :";
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", AUTH.data[i]);
    }
    cout << endl;
    return 0;
}
