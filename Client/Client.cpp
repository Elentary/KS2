// KS2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <stdio.h>
#include <future>
#include <thread>
#include <chrono>

#pragma comment (lib, "Ws2_32.lib")

#define PORT 1701
#define BPORT 1702
#define MAX_LEN 255
#define SERVER "127.0.0.1"

void receivingFromServer(const SOCKET& server_socket) {
	struct sockaddr_in si_other;
	int slen = sizeof(si_other);
	while (true) {
		char buf[MAX_LEN];
		memset(buf, '\0', MAX_LEN);
		int recv_len;

		if ((recv_len = recvfrom(server_socket, buf, MAX_LEN, 0, (sockaddr*)&si_other, &slen)) == SOCKET_ERROR) {
			std::cout << "Receiving faled. Error : " << WSAGetLastError() << "\n";
			break;
		}

		char ip[255];
		std::cout << "\tReceived packet from " << inet_ntop(AF_INET, &si_other.sin_addr, ip, 255) << ":" << ntohs(si_other.sin_port) << "\n";
		std::cout << "\tPacket data:\n\t----------\n\t" << buf << "\n\t----------\n";
		std::cout << "Enter message :\n";
		std::cout.flush();
	}
}

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
	struct sockaddr_in si_other;
	int slen = sizeof(si_other);

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

	const char OPTION_VALUE = 1;
	setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &OPTION_VALUE, sizeof(int));

	struct sockaddr_in own_addr;
	own_addr.sin_family = AF_INET;
	own_addr.sin_port = htons(BPORT);
	own_addr.sin_addr.S_un.S_addr = INADDR_ANY;
	findCorrectConfig(server_socket, &own_addr);

	memset(&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER, &si_other.sin_addr.S_un.S_addr);
	si_other.sin_port = htons(PORT);

	std::thread thread(receivingFromServer, std::ref(server_socket));
	thread.detach();

	while (true) {
		std::cout << "Enter message :\n";
		std::cout.flush();

		char buf[MAX_LEN];
		memset(buf, '\0', MAX_LEN);
		gets_s(buf);

		if (sendto(server_socket, buf, strlen(buf), 0, (sockaddr*)&si_other, slen) == SOCKET_ERROR) {
			std::cout << "Sending failed. Error : " << WSAGetLastError() << "\n";
			return WSAGetLastError();
		}
	}

	closesocket(server_socket);
	WSACleanup();

	return 0;
}

