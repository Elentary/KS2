// KS2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#pragma comment (lib, "Ws2_32.lib")

#define PORT 1701
#define MAX_LEN 255
#define BCASTIP "255.255.255.255"

void findCorrectConfig(const SOCKET& server_socket, sockaddr_in* own_addr) {
	std::cout << "Start binding...\n";
	auto current_port = ntohs(own_addr->sin_port);
	while (bind(server_socket, (sockaddr*)own_addr, sizeof(*own_addr)) < 0) {
		std::cout << "Bind failed. Error : " << WSAGetLastError() << "\n";
		std::cout << "Incrementing the port...\n";
		own_addr->sin_port = htons(current_port++);
	}
	std::cout << "Bind done.\n";
}

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

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);
	findCorrectConfig(server_socket, &server);

	while (true) {
		std::cout << "Waiting for clients to discover me...\n";
		std::cout.flush();

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

		std::cout << "\tReceived ping from " << recv_ip << ":" << ntohs(si_other.sin_port) << "\n";

		strcpy_s(buf, "server");

		if (sendto(server_socket, buf, recv_len, 0, (sockaddr*)&si_other, si_len) == SOCKET_ERROR) {
			std::cout << "Sending failed. Error : " << WSAGetLastError() << "\n";
			closesocket(server_socket);
			return WSAGetLastError();
		}
	}

	closesocket(server_socket);
	WSACleanup();

	return 0;
}

