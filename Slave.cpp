//g++ <input>.cpp -o <output> "C:\path_to\libws2_32.a"
#include <iostream>
#include <winsock2.h>
 
using namespace std;
 
int main(int argc, char* argv[])
{
    cout << "Enter the Server's IP Address/Hostname" << endl;
    string server_ip;
    cin >> server_ip;
    const char* ip_server = server_ip.c_str();
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
    int n = 5555;
    loop:
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr(ip_server);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(n);
    if(connect(server, (SOCKADDR *)&addr, sizeof(addr)) == -1)
    {
        n = n + 1;
        }; 
    string test;
    getline(cin, test);
    //test = "hih";
    const char* buffer = test.c_str();
    send(server, buffer, sizeof(buffer), 0);
    cout << "Message sent!" << endl;
 goto loop;
}