#include <arpa/inet.h>
#include <poll.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

using namespace std;

// tcp客户端程序，使用poll实现

#define MAXFDS 1024

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
    if (setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, len) < 0) {
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
    // 初始化服务端的监听端口
    int listensock = initsetver(50005);
    if (listensock < 0) {
        cerr << "initsetver failed" << endl;
        return -1;
    }

    cout << "listensock: " << listensock << endl;

    int maxfd = 0;  // fds数组中需要监听的socket的最大值

    /**
     * struct pollfd {
     *  int fd;         // 需要监听的socket
     *  short events;   // 需要监听的事件
     *  short revents;  // 实际发生的事件
     * };
     */
    struct pollfd fds[MAXFDS];  // pollfd结构体数组，用于存放需要监听的socket

    // 初始化fds数组，将所有fd设置为-1
    for (auto& fd : fds) {
        // 为-1则忽略监听
        fd.fd = -1;
    }

    // 将listen socket加入fds数组
    fds[listensock].fd = listensock;  // 直接用listensock作为fds数组的下标

    /**
     * 监听读事件，数据可读，包括
     * 1. 新客户端连接
     * 2. 客户端发送数据，有数据可读
     * 3. 客户端关闭连接
     * 三种情况
     */
    fds[listensock].events = POLLIN;

    maxfd = listensock;

    while (1) {
        int infds = poll(fds, maxfd + 1, -1);  // -1表示阻塞等待, 0表示立即返回, >0表示等待时间
        if (infds < 0) {
            perror("poll");
            return -1;
        }

        // 超时
        if (infds == 0) {
            cout << "poll() timeout" << endl;
            continue;
        }

        // 检查有事情发生的socket，包括监听和客户端连接的socket
        for (int eventfd = 0; eventfd <= maxfd; ++eventfd) {
            if (fds[eventfd].fd == -1) {
                continue;
            }

            // 有事件发生，在这里是POLLIN事件
            if (fds[eventfd].revents > 0) {
                cout << "eventfd: " << eventfd << ", revents: " << fds[eventfd].revents << endl;

                // fds[eventfd].revents = 0;

                // 有新的客户端连接
                if (eventfd == listensock) {
                    struct sockaddr_in cliaddr;
                    socklen_t clilen = sizeof(cliaddr);

                    int connfd = accept(listensock, (struct sockaddr*)&cliaddr, &clilen);
                    if (connfd < 0) {
                        perror("accept");
                        return -1;
                    }

                    cout << "new client: " << inet_ntoa(cliaddr.sin_addr) << ":" << ntohs(cliaddr.sin_port) << endl;

                    // 将新的客户端连接的socket加入fds数组
                    fds[connfd].fd = connfd;
                    fds[connfd].events = POLLIN;

                    // 更新maxfd
                    if (connfd > maxfd) {
                        maxfd = connfd;
                        cout << "maxfd: " << maxfd << endl;
                    }
                } else {
                    // 有客户端发送数据
                    if (fds[eventfd].revents & POLLIN) {
                        cout << "before handel revents: " << fds[eventfd].revents << endl;
                        char buf[1024] = {0};
                        int n = read(eventfd, buf, sizeof(buf));
                        if (n < 0) {
                            perror("read");
                            return -1;
                        } else if (n == 0) {
                            // 客户端关闭连接
                            cout << "client close" << endl;
                            close(eventfd);
                            fds[eventfd].fd = -1;

                             // 更新maxfd
                            if (eventfd == maxfd) {
                                for (int i = maxfd; i >= 0; --i) {
                                    if (fds[i].fd != -1) {
                                        maxfd = i;
                                        break;
                                    }
                                }
                            }
                        } else {
                            cout << "recv: eventfd: " << eventfd << " size = " << strlen(buf) << ", buf: " << buf;
                            write(eventfd, buf, strlen(buf));
                        }
                        fds[eventfd].revents = 0b11111;
                        cout << "After handel revents: " << fds[eventfd].revents << endl << endl;
                    }
                }
            }
        }
    }

    return 0;
}