#include "AUTH.hpp"
//All data structures related to auth key generation reside in AUTH.hpp

int main() 
{
	int j = 0;
    unsigned128bit K;
    unsigned128bit XDOUT;
    unsigned128bit RAND;
    unsigned48bit AK;
    unsigned64bit CDOUT;
    unsigned48bit SQN;
    unsigned16bit AMF;
    unsigned64bit MAC;
    unsigned128bit AUTH;
	unsigned char temp = 0x00;
    AMF.data[0] = 0x80;
	//AMF is hard coded for now it will change dynamically according to USIM data
    
    for (int i = 0; i < 8; i++)
    {
		//CDOUT is the combination of SQN and AMF
        if (i < 6)
            CDOUT.data[i] = SQN.data[i];
        else {
            CDOUT.data[i] = AMF.data[j];
            j++;
        }
    }
    //for this program USIM k value is set to 0x00112233445566778899AABBCCDDEEFF
    for (int i = 0; i < 16; i++) 
    {
        K.data[i] = temp;
        temp = temp + 0x11;
    }
	//Printing value of K to console
    cout << "k    :";
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", K.data[i]);
    }
    cout << endl;
    cout << "RAND :";
    srand(time(0));

	//RAND value is hardcoded you can comment this part of the code and uncomment the below for loop for random value
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
	//printing XDOUT value.
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", XDOUT.data[i]);
    }
    cout << endl;
	//take out 48 bits from(24 to 71) XDOUT and assign it to AK.
    f4( & AK, XDOUT);
    cout << "AK   :";
	//printing AK value.
    for (int i = 0; i < 6; i++) 
    {
        printf("%02X", AK.data[i]);
    }
    cout << endl;
    cout << "CDOUT:";
	//printing CDOUT value.
    for (int i = 0; i < 8; i++) 
    {
        printf("%02X", CDOUT.data[i]);
    }
    cout << endl;
	//XOR first half bits with CDOUT and assign it to MAC
    f1(XDOUT, CDOUT, & MAC);
    cout << "MAC  :";
	//printing MAC value.
    for (int i = 0; i < 8; i++) 
    {
        printf("%02X", MAC.data[i]);
    }
    cout << endl;
	//Authgen function will XOR SQN and AK. It will concatenate AMF and MAC to AUTH value.
    Authgen(SQN, AK, AMF, MAC, & AUTH);
    cout << "AUTH :";
	//printing AUTH value.
    for (int i = 0; i < 16; i++) 
    {
        printf("%02X", AUTH.data[i]);
    }
    cout << endl;
    return 0;
}
