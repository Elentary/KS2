// KS2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#pragma comment (lib, "Ws2_32.lib")

#define PORT 1701
#define BPORT 1702
#define MAX_LEN 255
#define BCASTIP "255.255.255.255"

int main()
{
	WSADATA wsaData;
	SOCKET server_socket = INVALID_SOCKET;
	struct sockaddr_in server;

	std::cout << "Initialising Winsock...\n";
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "Failed. Error : " << WSAGetLastError() << "\n";
		return WSAGetLastError();
	}
	std::cout << "Initialised.\n";

	if ((server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
		std::cout << "Could not create socket : " << WSAGetLastError() << "\n";
		return WSAGetLastError();
	}
	std::cout << "Socket created.\n";

	char broadcast = '1';
	if (setsockopt(server_socket, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
		std::cout << "Opting seeting failed. Error : " << WSAGetLastError() << "\n";
		closesocket(server_socket);
		return WSAGetLastError();
	}
	const char OPTION_VALUE = 1;
	setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &OPTION_VALUE, sizeof(int));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	std::cout << "Start binding...\n";
	if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
		std::cout << "Bind failed. Error : " << WSAGetLastError() << "\n";
		closesocket(server_socket);
		return WSAGetLastError();
	}
	std::cout << "Bind done.\n";

	struct sockaddr_in broad_addr;
	broad_addr.sin_family = AF_INET;
	broad_addr.sin_port = htons(BPORT);
	inet_pton(AF_INET, BCASTIP, &broad_addr.sin_addr.S_un.S_addr);
	int broad_len = sizeof(broad_addr);

	/*struct sockaddr_in own_addr;
	int own_len = sizeof(own_addr);
	while (true) {
		int ip_len;
		char own_ip[MAX_LEN];
		strcpy_s(own_ip, "#!Init#!");
		if (sendto(server_socket, own_ip, MAX_LEN, 0, (sockaddr*)&broad_addr, broad_len) == SOCKET_ERROR) {
			std::cout << "Sending startup message failed. Error : " << WSAGetLastError() << "\n";
			closesocket(server_socket);
			return WSAGetLastError();
		}
		if ((ip_len = recvfrom(server_socket, own_ip, MAX_LEN, 0, (sockaddr*)&own_addr, &own_len)) == SOCKET_ERROR) {
			std::cout << "Receiving of startup message failed. Error : " << WSAGetLastError() << "\n";
			closesocket(server_socket);
			return WSAGetLastError();
		}
		if (strcmp(own_ip, "#!Init#!") == 0) {
			break;
		}
	}*/

	bool show = true;
	while (true) {
		//if (show) {
			std::cout << "Waiting for clients...\n";
			std::cout.flush();
		//}

		char buf[MAX_LEN];
		memset(buf, '\0', MAX_LEN);

		struct sockaddr_in si_other;
		memset(&si_other, 0, sizeof(si_other));
		int recv_len, si_len = sizeof(si_other);


		if ((recv_len = recvfrom(server_socket, buf, MAX_LEN, 0, (sockaddr*)&si_other, &si_len)) == SOCKET_ERROR) {
			std::cout << "Receiving failed. Error : " << WSAGetLastError() << "\n";
			closesocket(server_socket);
			return WSAGetLastError();
		}

		char recv_ip[255];
		inet_ntop(AF_INET, &si_other.sin_addr, recv_ip, 255);
		/*inet_ntop(AF_INET, &own_addr.sin_addr, own_ip, 255);
		if (si_other.sin_port == own_addr.sin_port && strcmp(recv_ip, own_ip) == 0) {
			show = false;
			continue;
		}*/

		std::cout << "\tReceived packet from " << recv_ip << ":" << ntohs(si_other.sin_port) << "\n";
		std::cout << "\tPacket data: " << buf << "\n";
		
		strcat_s(buf, "\tPacket source: ");
		strcat_s(buf, recv_ip);

		if (sendto(server_socket, buf, recv_len, 0, (sockaddr*)&broad_addr, broad_len) == SOCKET_ERROR) {
			std::cout << "Sending failed. Error : " << WSAGetLastError() << "\n";
			closesocket(server_socket);
			return WSAGetLastError();
		}
		//show = true;
	}

	closesocket(server_socket);
	WSACleanup();

    return 0;
}

