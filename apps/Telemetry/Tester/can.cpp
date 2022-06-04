#include "can.h"
#include "encoder.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <vector>
#include "legato.h"
#include <le_thread.h>
#include "interfaces.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/can.h>
#include <net/if.h>

void readCAN() {
  // Create a random set of data
  // Use the encoder function

  std::vector<int> data;
  //seed random number generator 
  srand(time(NULL));
  int x = (rand() % 19) + 1;

  for(int i = 0; i < x; i++)
  {
    int r = rand() % 10;
    data.push_back(r);
  }

  encode_data(0, data);
}

void runReadCAN()
{
  std::thread runReadThread(readCAN);
  runReadThread.join();
  printf("Joined threads\n");
}

int openPort(const char *port) 
{
  //Open start_can.sh
	struct ifreq ifr;
	struct sockaddr_can addr;

	int soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if(soc < 0) {
		LE_INFO("err0");
	    return (-1);
	}

	addr.can_family = AF_CAN;
	strcpy(ifr.ifr_name, port);
	if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0) {
		LE_INFO("err1");
	    return (-1);
	}

	addr.can_ifindex = ifr.ifr_ifindex;
	fcntl(soc, F_SETFL, O_NONBLOCK);
	if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0){
		LE_INFO("err2");
	    return (-1);
	}

	return soc;
}

int closePort(int soc) 
{
	close(soc);
	return 0;
}

