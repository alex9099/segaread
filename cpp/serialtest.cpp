#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<strings.h>
#include<cstdlib>
#include<string.h>
#include<unistd.h>


int main(){

    int fd = open("/dev/ttyUSB0", O_RDONLY | O_NOCTTY);
    if (fd == -1)
    {
        /* Could not open the port. */
        perror("open_port: Unable to open /dev/ttyS0 - ");
    }

    char buffer[32];
    int n = read(fd, buffer, sizeof(buffer));
    if (n < 0){fputs("read failed!\n", stderr);}
    std::cout << buffer << std::endl;
    std::cout << fd << std::endl;


}
