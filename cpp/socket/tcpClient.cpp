#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <memory.h>
#include <iostream>

using namespace std;

// tcp客户端程序
int main() {
    int sockfd; // 客户端socket

    struct sockaddr_in servaddr; // 服务器地址
    char buf[1024]; // 发送缓冲区

    // 第1步：创建客户端socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }
    memset(&servaddr, 0, sizeof(servaddr)); // 初始化服务器地址
    servaddr.sin_family = AF_INET; // 指定协议族，AF_INET表示使用IPv4地址
    servaddr.sin_port = htons(50005); // 指定端口号，使用htons函数将主机字节序转换为网络字节序
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 指定服务器的IP地址

    // 第2步：向服务器发起连接请求
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    cout << "connect success" << endl;

    // 从命令行循环读入数据，直到输入"exit"为止
    memset(buf, 0, sizeof(buf));
    cout << "input: ";
    while (fgets(buf, sizeof(buf), stdin) != NULL) {

        // 向服务器发送数据
        if (write(sockfd, buf, strlen(buf)) == -1) {
            perror("write");
            close(sockfd);
            return -1;
        }

        // 从服务器接收数据
        memset(buf, 0, sizeof(buf));
        if (read(sockfd, buf, sizeof(buf)) == -1) {
            perror("read");
            close(sockfd);
            return -1;
        }

        cout << "recv: " << buf << endl;

        cout << "input: ";
    }

    close(sockfd);
    return 0;
}