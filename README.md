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
**server side:**
```sh
./server
```
**client side:**
```sh
./client
```
**packet analysis:**
```sh
sudo tcpdump -w text.pcap -i lo
```
*Please note:* run server and packet analizer first before running client, and press ctrl-c to exit form server and packet sniffer.
## Expected output:
Please refer to **OutputImages folder** in the repo.
