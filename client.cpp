/*Simple HTTP client code::*/
#include <iostream>
#include <winsock2.h>
#include <cstring>

using namespace std;

#pragma comment(lib, "ws2_32.lib");

void head(){
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''HTTP CLIENT'''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
}

int main(){
    head();
    system("color a");
    /*Holds additional info after winsock has been initialized*/
    WSADATA ws_dat;
    //Declaration of socket
    SOCKET soc;
    /*Server declaration*/
    struct sockaddr_in serVer;
    char *message;
    char server_reply[50000];
    int rec_sze;

    //code to initialize winsock
    cout << "[*]Initializing winsock...........\n";
    if(WSAStartup(MAKEWORD(2,2),&ws_dat) != 0){
        cerr << "[!]Failed to initialize winsock. Error: " << WSAGetLastError() << endl;
        cout << "\n";
        system("pause");
        return 0;
    }
    cout << "[*]Winsock initialization successful!\n";
    cout << "[*]Creating socket..........\n";
    //Socket creation
    if((soc=socket(AF_INET, SOCK_STREAM, 0))==INVALID_SOCKET){
        cerr << "[!]Socket creation failed. Error: " << WSAGetLastError() << endl;
        cout << "\n";
        system("pause");
        return 0;
    }
    cout << "[*]Socket creation successful!\n\n";

    serVer.sin_addr.s_addr=inet_addr("127.0.0.1");
    serVer.sin_family=AF_INET;
    serVer.sin_port=htons(8080);
    cout << "[*]Connecting to available server......\n";
    //server connection
    if(connect(soc, (struct sockaddr*)&serVer, sizeof(serVer))<0){
        cerr << "[!]Connection Failed!!! Error: " << WSAGetLastError() << endl;
        cout << "\n";
        system("pause");
        return 0;
    }
    cout << "[*]Connected!!!\n\n";
    cout << "[*]Sending data.....\n";
    message="\nHi server, thank you for accepting me!\n\n"
    "GET/HTTP/1.1"
    "connection:Keep-alive";
        if(send(soc, message, strlen(message),0)<0){
            cerr << "[!]Failed to send message!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }
    cout << "[*]Data sent!!!\n\n";
    cout << "[*]Receiving reply.......\n";
    rec_sze=recv(soc, server_reply, 50000, 0);
    int sizee=rec_sze;
        if(sizee==SOCKET_ERROR){
            cerr << "[!]Error receiving reply!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }

    cout << "[*]Data received!!!\n\n";
    server_reply[sizee];
    cout << "[Data Received from server]:" << server_reply;
    cout << "\n\n";

    system("PAUSE");
    closesocket;
    WSACleanup();

}
