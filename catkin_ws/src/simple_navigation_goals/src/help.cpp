#include <ros/ros.h>
#include <iostream>
#include <unistd.h> 
#include<nav_msgs/Odometry.h>  
#include </home/kmakise/catkin_ws/src/simple_navigation_goals/include/util.h>
#include"simple_navigation_goals/msg209.h"
int fd;
Uart uart;
int main()
{
    fd = uart.UART0_Open(fd); //打开串口，返回文件描述符  
	int err = uart.UART0_Init(fd,115200,0,8,1,'N');  
	while(1)
	{
		send(uart,fd);
		usleep(100000); 
//		system("rosservice call /move_base/clear_costmaps");
	}
	return 0;
}
