#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "AllInclude.h"

class Solution {
public:
    Solution() = default;
    void client() {
        // 第1步：创建客户端socket
        int sockfd;
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            return;
        }

        // 第2步：绑定服务器的IP地址和端口号
        struct hostent* h;  // 服务器信息
        if (0 == (h = gethostbyname("127.0.0.1"))) { // 指定服务器的IP地址
            cout << "gethostbyname failed.\n";
            close(sockfd);
            return;
        }

        struct sockaddr_in servaddr;  // socket的一些信息
        memset(&servaddr, 0, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(9999);   // 指定服务器的端口号，使用htons函数将主机字节序转换为网络字节序
        memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);  // 将主机地址拷贝到socket地址中

        // 向服务器发起连接请求
        if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
            perror("connect");
            close(sockfd);
            return;
        }

        // 第3步：与服务器进行通信，发送一个报文后等待回复，然后再发送下一个报文
        char send_recive_buf[1024] = {0};

        for (int i = 0; i < 12; ++i) {
            int iret; // 用于接收返回值，显示发送或接收的字节数
            memset(send_recive_buf, 0, sizeof(send_recive_buf));
            sprintf(send_recive_buf, "这是第%d个报文，编号为%03d", i + 1, i + 1);

            // 向服务器发送报文
            if ((iret = send(sockfd, send_recive_buf, strlen(send_recive_buf), 0)) == -1) {
                perror("send");
                close(sockfd);
                return;
            }
            cout << "send " << iret << " bytes: " << send_recive_buf << endl;
            cout << "content: " << send_recive_buf << endl;

            memset(send_recive_buf, 0, sizeof(send_recive_buf));
            iret = recv(sockfd, send_recive_buf, sizeof(send_recive_buf), 0);
            if (iret == -1) {
                perror("recv");
                cout << iret << endl;
                close(sockfd);
                return;
            } else if (iret == 0) {
                cout << "服务器已关闭" << endl;
                close(sockfd);
                return;
            }
            cout << "接收" << iret << "字节的报文: " << send_recive_buf << endl;
            sleep(3);
        }

        // 第4步：关闭socket
        close(sockfd);
        return;
    }

    void server() { 
        // 第1步：创建服务器socket
        int listenfd; // 文件描述符，用于监听
        if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            return;
        }

        // 第2步：把服务器用于通信的地址和端口绑定到socket上
        struct sockaddr_in servaddr;  // socket的一些信息，数据结构
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET; // 协议族，在socket编程中只能是AF_INET
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY为0，表示本机的任意IP地址
        servaddr.sin_port = htons(9999); // 指定服务器的端口号，使用htons函数将主机字节序转换为网络字节序

        // 由于std的原因，这里需要使用::将bind函数进行限定，限定于全局作用域
        if (::bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {  
            perror("bind");
            close(listenfd);
            return;
        }

        // 第3步：监听客户端的连接请求，把socket设置为被动监听状态，10为最大监听数
        if (listen(listenfd, 10) == -1) {
            perror("listen");
            close(listenfd);
            return;
        }

        // 第4步：接受客户端的连接请求，返回一个新的socket，这个socket用于同连接到服务器的客户端进行通信
        int connfd; // 文件描述符，用于通信
        int socklen = sizeof(struct sockaddr_in); // sockaddr_in的长度
        struct sockaddr_in clientaddr; // 用于保存客户端的地址信息
        connfd = accept(listenfd, (struct sockaddr*)&clientaddr, (socklen_t*)&socklen);
        // 来到这里，客户端就可以和服务器进行通信了

        // inet_ntoa()函数用于将网络字节序的IP地址转换为点分十进制的IP地址
        cout << "客户端 " << inet_ntoa(clientaddr.sin_addr) << " 已连接" << endl;
        
        // 第5步：与客户端进行通信，接收一个报文后回复，回复ok
        char send_recive_buf[1024] = {0};
        while (1) {
            int iret; // 用于接收返回值，显示发送或接收的字节数
            memset(send_recive_buf, 0, sizeof(send_recive_buf));

            // 接收客户端的报文
            iret = recv(connfd, send_recive_buf, sizeof(send_recive_buf), 0);
            if (iret == -1) {
                perror("recv");
                cout << iret << endl;
                close(connfd);
                close(listenfd);
                return;
            } else if (iret == 0) {
                /**
                 * 服务端接收到了 FIN 报文，TCP 协议栈会为 FIN 包插入一个文件结束符 EOF 到接收缓冲区中，
                 * 应用程序可以通过 read 调用来感知这个 FIN 包。这个 EOF 会被放在已排队等候的其他已接收
                 * 的数据之后，这就意味着服务端需要处理这种异常情况，因为 EOF 表示在该连接上再无额外数据到
                 * 达。此时，服务端进入 CLOSE_WAIT 状态；
                 */
                cout << "客户端已关闭" << endl;
                close(connfd);
                close(listenfd);
                return;
            }

            cout << "接收" << iret << "字节的报文: " << send_recive_buf << endl;

            strcpy(send_recive_buf, "ok");

            // 向客户端发送报文
            iret = send(connfd, send_recive_buf, strlen(send_recive_buf), 0);
            if (iret == -1) {
                perror("send");
                close(connfd);
                close(listenfd);
                return;
            } else if (iret == 0) {
                cout << "客户端已关闭" << endl;
                close(connfd);
                close(listenfd);
                return;
            }

            cout << "发送 " << iret << " bytes: " << send_recive_buf << endl;
        }

        // 第6步：关闭socket，释放资源
        close(connfd);
        close(listenfd);
        return; 
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    if (0 == atoi(argv[1])) {
        s.client();
    } else {
        s.server();
    }
    return 0;
}