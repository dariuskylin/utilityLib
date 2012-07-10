/*
 * =====================================================================================
 *
 *       Filename:  client.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/09/2012 07:49:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"common.h"
using namespace std;
const char* local = "127.0.0.1";
int main()
{
    int sockfd,n;
    int port=PORT;
    char buff[BUFFERSIZE];
    char recv[BUFFERSIZE];
    struct sockaddr_in servaddr;
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket error");
        exit(1);
    }
    memset(buff,0,sizeof(buff));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if(inet_pton(AF_INET,local,&servaddr.sin_addr) < 0 ){
        perror("inet_pton error");
        exit(1);
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
        perror("connect error");
        exit(1);
    }
    memset(buff,0,sizeof(buff));
    memset(recv,0,sizeof(recv));
    int ret;
    while(1){
        memset(buff,0,sizeof(buff));
        memset(recv,0,sizeof(recv));
        if((fgets(buff,BUFFERSIZE,stdin)) == NULL){
            perror("fgets error");
            break;
        }
        if(write(sockfd,buff,strlen(buff)) < 0){
            perror("write error");
            exit(1);
        }
        if((ret = read(sockfd,recv,sizeof(recv))) <= 0){
            if(ret == 0){
                close(sockfd);
                cout<<"connection closed"<<endl;
                exit(0);
            }
            if(errno == EINTR){
                continue;
            }
            close(sockfd);
            perror("read error");
            exit(1);
        }
        cout<<">>"<<recv<<endl;
    }
    return 0;
}
