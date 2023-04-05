#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

// tcp客户端程序，使用select实现

// 初始化服务端的监听端口
int initsetver(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    int opt = 1;
    unsigned int len = sizeof opt;

    // 将socket设置为可重用，因为服务器可能会因为异常退出，导致端口被占用，opt指启用该选项
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, len) < 0) {
        perror("setsockopt");
        return -1;
    }

    // 设置周期性发送keepalive探测报文的选项
    if(setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, len) < 0) {
        perror("setsockopt");
        return -1;
    }

    struct sockaddr_in servaddr;

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (::bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(sock, 5) < 0) {
        perror("listen");
        return -1;
    }

    return sock;
}

int main() {
    int listensock; ;

    if ((listensock = initsetver(50005)) < 0) {
        cerr << "initsetver failed" << endl;
        return -1;
    }
    cout << "listen success on 50005" << endl;

    fd_set readfds; // 读事件集合，包括监听socket和已连接的socket
    int maxfd = listensock; // readfds中最大的socket描述符，设置成kListenSock是为了避免每次调用select都要重新设置

    FD_ZERO(&readfds); // 初始化readfds

    FD_SET(listensock, &readfds); // 将监听socket加入readfds

    while (1) {
        // 因为select会修改readfds，所以要保存一个副本，传一个副本给select
        fd_set tmpfds = readfds;

        // 第1步：调用select函数，等待事件发生
        int infds = select(maxfd + 1, &tmpfds, NULL, NULL, NULL); // 阻塞等待事件发生
        cout << "select infds: " << infds << endl;

        // 返回失败
        if (infds < 0) {
            perror("select");
            return -1;
        }

        // 超时
        if (infds == 0) {
            cout << "select timeout" << endl;
            continue;
        }

        // 检测到有事件发生的socket，包括监听socket和已连接的socket
        // 这里是客户端的socket，每次都要遍历整个集合，因为可能有多个socket都有事件发生
        for(int eventfd = 0; eventfd <= maxfd; ++eventfd) {
            // 如果当前socket没有事件发生，继续检测下一个socket
            if (!FD_ISSET(eventfd, &tmpfds)) {
                continue;
            }

            // 如果是监听socket，说明有新的连接请求
            if (eventfd == listensock) {
                struct sockaddr_in clientaddr;
                socklen_t len = sizeof(clientaddr);

                // 创建客户端连接socket
                int connfd = accept(listensock, (struct sockaddr*)&clientaddr, &len);
                if (connfd < 0) {
                    perror("accept");
                    return -1;
                }

                // 将新的连接socket加入readfds
                FD_SET(connfd, &readfds);

                // 更新maxfd
                if (connfd > maxfd) {
                    maxfd = connfd;
                }

                cout << "new connection from " << inet_ntoa(clientaddr.sin_addr) << ":" << ntohs(clientaddr.sin_port) << endl;
            } else {
                // 如果是已连接的socket，说明有数据可读
                char buf[1024] = {0};
                int n = read(eventfd, buf, sizeof(buf));
                if (n < 0) {
                    // 读取失败，关闭连接
                    perror("read");
                    return -1;
                } else if (n == 0) {
                    // 客户端关闭连接
                    cout << "client close" << endl;
                    close(eventfd);

                    // 从readfds中移除该socket
                    FD_CLR(eventfd, &readfds);

                    // 因为少了一个socket，需要重新计算maxfd
                    if (eventfd == maxfd) {
                        // 看看比maxfd小的socket中，哪个是最大的
                        for(int i = maxfd; i > 0; --i) {
                            if (FD_ISSET(i, &readfds)) {
                                maxfd = i;
                                break;
                            }
                        }
                        cout << "maxfd: " << maxfd << endl;
                    }
                } else {
                    // > 0，读取成功
                    cout << "recv: eventfd: " << eventfd << ", buf: " << buf << endl;
                    
                    // 把收到的报文原样返回
                    write(eventfd, buf, strlen(buf));
                }
            }
        }
    }
    return 0;
}

