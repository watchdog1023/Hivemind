#include <iostream>
#include <winsock2.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream> 
 
using namespace std;

void server()
{
        WSADATA WSAData;
        SOCKET server, client;
        SOCKADDR_IN serverAddr, clientAddr;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5555);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);
        
        cout << "Listening for incoming connections..." << endl;
        loop:
                string test;
                const char* buffer = test.c_str();
                int clientAddrSize = sizeof(clientAddr);
                if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
                        {
                                recv(client, buffer, sizeof(buffer), 0);
                                cout  << "1--"+string(buffer) << endl;
                        }
                goto loop;
}
 
void server1()
{
        WSADATA WSAData;
        SOCKET server, client;
        SOCKADDR_IN serverAddr, clientAddr;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5556);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);

        cout << "Listening for incoming connections..." << endl;
        loop:
                string test;
                const char* buffer = test.c_str();
                int clientAddrSize = sizeof(clientAddr);
                if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
                        {
                                recv(client, buffer, sizeof(buffer), 0);
                                cout  << "2--"+string(buffer) << endl;
                        }
                goto loop;
}

void server2()
{
        WSADATA WSAData;
        SOCKET server, client;
        SOCKADDR_IN serverAddr, clientAddr;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5557);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);

        cout << "Listening for incoming connections..." << endl;
        loop:
                string test;
                const char* buffer = test.c_str();
                int clientAddrSize = sizeof(clientAddr);
                if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
                        {
                                recv(client, buffer, sizeof(buffer), 0);
                                cout  << "3--"+string(buffer) << endl;
                        }
                goto loop;
}

void server3()
{
        WSADATA WSAData;
        SOCKET server, client;
        SOCKADDR_IN serverAddr, clientAddr;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5558);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);

        cout << "Listening for incoming connections..." << endl;
        loop:
                string test;
                const char* buffer = test.c_str();
                int clientAddrSize = sizeof(clientAddr);
                if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
                        {
                            recv(client, buffer, sizeof(buffer), 0);
                                cout  << "4--"+string(buffer) << endl;
                        }
                goto loop;
}

void server4()
{
        WSADATA WSAData;
        SOCKET server, client;
        SOCKADDR_IN serverAddr, clientAddr;
        WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(5559);
        bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
        listen(server, 0);

        cout << "Listening for incoming connections..." << endl;
        loop:
                string test;
                const char* buffer = test.c_str();
                int clientAddrSize = sizeof(clientAddr);
                if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
                        {
                                recv(client, buffer, sizeof(buffer), 0);
                                cout  << "5--"+string(buffer) << endl;
                        }
                goto loop;
}


int main()
{
        using namespace boost;
    
        thread_group tgroup;
        tgroup.create_thread(bind(&server));
        tgroup.create_thread(bind(&server1));
        tgroup.create_thread(bind(&server2));
        tgroup.create_thread(bind(&server3));
        tgroup.create_thread(bind(&server4));
        tgroup.join_all();
}