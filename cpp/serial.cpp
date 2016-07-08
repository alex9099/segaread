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
/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */

#define BAUDRATE B115200
/* change this definition for the correct port */
#define MODEMDEVICE "/dev/ttyUSB0"
#define _POSIX_SOURCE 1 /* POSIX compliant source */

#define FALSE 0
#define TRUE 1

volatile int STOP=FALSE;

main()
{

  int fd,c, res;
  struct termios oldtio,newtio;
  char buf[255];
  std::string letter;
  std::string command;
  std::string tmp;
  std::string key;
  int count = 0;
  command = "xdotool keyup ";
/*
  Open modem device for reading and writing and not as controlling tty
  because we don't want to get killed if linenoise sends CTRL-C.
*/
 fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
 if (fd <0) {perror(MODEMDEVICE); exit(-1); }

 tcgetattr(fd,&oldtio); /* save current serial port settings */
 bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

/*
  BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
  CRTSCTS : output hardware flow control (only used if the cable has
            all necessary lines. See sect. 7 of Serial-HOWTO)
  CS8     : 8n1 (8bit,no parity,1 stopbit)
  CLOCAL  : local connection, no modem contol
  CREAD   : enable receiving characters
*/
 newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;

/*
  IGNPAR  : ignore bytes with parity errors
  ICRNL   : map CR to NL (otherwise a CR input on the other computer
            will not terminate input)
  otherwise make device raw (no other input processing)
*/
 newtio.c_iflag = IGNPAR | ICRNL;

/*
 Raw output.
*/
 newtio.c_oflag = 0;

/*
  ICANON  : enable canonical input
  disable all echo functionality, and don't send signals to calling program
*/
 newtio.c_lflag = ICANON;

/*
  initialize all control characters
  default values can be found in /usr/include/termios.h, and are given
  in the comments, but we don't need them here
*/
 newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
 newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
 newtio.c_cc[VERASE]   = 0;     /* del */
 newtio.c_cc[VKILL]    = 0;     /* @ */
 newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
 newtio.c_cc[VTIME]    = 0;     /* inter-character timer unused */
 newtio.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
 newtio.c_cc[VSWTC]    = 0;     /* '\0' */
 newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
 newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
 newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
 newtio.c_cc[VEOL]     = 0;     /* '\0' */
 newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
 newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
 newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
 newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
 newtio.c_cc[VEOL2]    = 0;     /* '\0' */

/*
  now clean the modem line and activate the settings for the port
*/
 tcflush(fd, TCIFLUSH);
 tcsetattr(fd,TCSANOW,&newtio);

/*
  terminal settings done, now handle input
  In this example, inputting a 'z' at the beginning of a line will
  exit the program.
*/
 while (STOP==FALSE) {     /* loop until we have a terminating condition */
 /* read blocks program execution until a line terminating character is
    input, even if more than 255 chars are input. If the number
    of characters read is smaller than the number of chars available,
    subsequent reads will return the remaining chars. res will be set
    to the actual number of characters actually read */
    res = read(fd,buf,255);
    buf[res]=0;             /* set end of string, so we can printf */
    //printf(":%s:%d\n", buf, res);
    if (buf[0]=='z') STOP=TRUE;
    //printf("%s", buf);
count = 1;
if (std::string(buf) == std::string("A\n")){
  key = "z ";
  letter = buf;

   //if (std::string(letter) != std::string(buf)){
             std::system(("xdotool keydown " + key).c_str());
     //}

    }
if (std::string(buf) == std::string("B\n")){
  key = "x " + key;
  letter = buf;

   //if (std::string(letter) != std::string(buf)){
             std::system(("xdotool keydown " + key).c_str());
     //}

    }
if (std::string(buf) == std::string("C\n")){
  key = "c "+ key;
  letter = buf;

  // if (std::string(letter) != std::string(buf)){
             std::system(("xdotool keydown " + key).c_str());
     //}

    }
if (std::string(buf) == std::string("START\n")){
  key = "q " + key;
     letter = buf;
   //if (std::string(letter) != std::string(buf)){
             std::system(("xdotool keydown " + key).c_str());
     //}


    }
if (std::string(buf) == std::string("UP\n")){
  key = "w " + key;
     letter = buf;
 //if (std::string(letter) != std::string(buf)){
 if (count == 0) {
   std::system(("xdotool keydown " + key).c_str());
count =1;
}



  //   }

              }

if (std::string(buf) == std::string("DOWN\n")){
  key = "s " + key;
     letter = buf;
   //if (std::string(letter) != std::string(buf)){
    if (count == 0) {
      std::system(("xdotool keydown " + key).c_str());
// }
count =1;
  }


    }
if (std::string(buf) == std::string("LEFT\n")){
  key = "a " + key;
  letter = buf;

   //if (std::string(letter) != std::string(buf)){
               if (count == 0) {
             std::system(("xdotool keydown " + key).c_str());
             count =1;
           }
     //}

  }
if (std::string(buf) == std::string("RIGHT\n")){
  key = "d " + key;
        letter = buf;
   //if (std::string(letter) != std::string(buf)){
            if (count == 0) {
             std::system(("xdotool keydown " + key).c_str());
             count = 1;

           }
   //}

 }

 if (std::string(buf) == std::string("DO\n")){
std::system(("xdotool keydown " + key).c_str());
key = "";
 }
  //       letter = buf;
// std::cout << std::string(letter) << " is not " << std::string(buf) << '\n';

// if (std::string(letter + "\n") != std::string(buf) ){
    // std::cout << std::string(letter) << " is not " << std::string(buf) << '\n';

//}
//std::cout << (letter + "\n").compare(buf) << std::endl;

 if (std::string(buf) == std::string("STOP\n")){

std::system(("xdotool keyup --clearmodifiers " + key).c_str());
key = "";
 count = 0;
std::cout << "Done" << std::endl;

}
}
 tcsetattr(fd,TCSANOW,&oldtio);
}
