# Authentication key generation
This program will generate authentication key using algorithms at UE side or network side as well. The algorithm mainly refers to 3gpp TS 35.206 specification.
# Software requirments:
Linux OS(V 16.04 or up) or windows OS running on the host machine or in a virtual machine with latest **gcc/g++ compilers** installed.
# Compilation notes:
For windows you can just create a project in your preferred IDE and copy files and run the program.\
For Linux :
```sh
g++ -g -Wall -std=c++14 AUTH.cpp main.cpp -o output
```
## Running the program:
```sh
./output
```
*Please note:* RAND value is hard coded. you can uncomment the section of code where it choses random value for RAND.
## Expected output:
Please refer to **Output folder** in the repo.
