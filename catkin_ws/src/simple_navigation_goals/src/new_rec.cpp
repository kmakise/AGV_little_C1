/******************************************************************************
 * @file       new_rec.cpp
 * @author     zhangdong
 * @version    1.0.1
 * @date       2019/3/4
 * @brief      Amadeus system receiver application of ros node
 * @note       1.read file to frame buffer 
			   2.get x&a value from frame buffer and publish the x&a to msg209
*******************************************************************************
*/

//include file
#include <ros/ros.h>
#include <iostream>
#include </home/kmakise/catkin_ws/src/simple_navigation_goals/include/util.h>
#include "simple_navigation_goals/msg209.h"

//using
using namespace std;

//buffer and frame structure typedef
typedef struct
{
	char buffer[64];
	char  wt;
	char  rd;

}BufTypedef, *BufPointer;

typedef struct
{
	char frame[10];
	int  len;
	bool status;
	bool writing;

}FrameTypedef,*FramePointer;

//const variable
const char HEAD_CHAR = 0xff;
const char TAIL_CHAR = 0x3e;

//global variable
int    g_int_uartFD;                      //linux file descriptor         
int    g_int_buflen;                      //buffer length

//global structure
BufTypedef 			g_msgBuffer;
FrameTypedef 		g_msgFrame;

//global objects
Uart                            uart;	  //linux uart
ros::Publisher                  pub;	  //global publish object
simple_navigation_goals::msg209 puhmsg;   //publish xlinear angular

//Amadeus system receive setup function of ros node
void AmadeusUartRec_Setup(int argc, char **argv);
 //Amadeus system receive loop function of ros node		
void AmadeusUartRec_Loop(void);			     

/*node main -----------------------------------------------------------------*/
int main(int argc, char **argv)
{  
	AmadeusUartRec_Setup(argc,argv);
	while(1)
	{
		AmadeusUartRec_Loop();
	}
	return 0;
}  

/*buffer tool function body--------------------------------------------------*/

//buffer init
void structInit(BufPointer bp, FramePointer fp)
{
	for (int i = 0; i < 64; i++)
	{
		bp->buffer[i] = '\0';
		if (i < 10)
		{
			fp->frame[i] = '\0';
		}
	}
	bp->wt = 0;
	bp->rd = 0;
	fp->len = 0;
	fp->status = false;
	fp->writing = true;
}
//get char from file
void pushChar(BufPointer bp)
{
	static int num = 0;

	char rcv_buf[1];
	g_int_buflen = uart.UART0_Recv(g_int_uartFD, rcv_buf,1);	
	bp->buffer[bp->wt] = rcv_buf[0];
	bp->wt = (bp->wt + 1) & 0x3f;

	num = (num + 1) % 13;
}
//get frame form buffer
void getFrame(BufPointer bp,FramePointer fp)
{
	if (fp->status == false)
	{
		if (bp->buffer[bp->rd] == HEAD_CHAR)
		{
			fp->len = 0;
			fp->writing = true;
		}
		else if(bp->buffer[bp->rd] == TAIL_CHAR)
		{
			fp->status = true;
			fp->writing = false;
		}
		else if(fp->writing == true)
		{
			fp->frame[fp->len++] = bp->buffer[bp->rd];
		}
		if (bp->wt != bp->rd)
		{
			bp->buffer[bp->rd] = '\0';
			bp->rd = (bp->rd + 1) & 0x3f;
		}
	}
}
//get x&a value from frame
//void getXAValue(int * xlinear,int * )

/*node setup and loop -------------------------------------------------------*/

//node steup
void AmadeusUartRec_Setup(int argc, char **argv)
{
	cout<<"k.makise's receiver @ AmadeusSystem V2.93"<<endl;

	g_int_uartFD = uart.UART0_Open(g_int_uartFD);  
	uart.UART0_Init(g_int_uartFD,115200,0,8,1,'N');  

	ros::init(argc,argv,"new_rec");
	ros::NodeHandle nh;	

	pub = nh.advertise<simple_navigation_goals::msg209>("/car_run",10);

}
//node loop
void AmadeusUartRec_Loop(void)
{
	static int state = 0;
	pushChar(&g_msgBuffer);
	getFrame(&g_msgBuffer, &g_msgFrame);
	if (g_msgFrame.status == true)
	{
		g_msgFrame.status = 0;
		g_msgFrame.frame[g_msgFrame.len] = '\0';
		//printf("%02x,%02x\r\n",g_msgFrame.frame[1],g_msgFrame.frame[2]);
		g_msgFrame.frame[1] = (g_msgFrame.frame[1] > 150)?0:g_msgFrame.frame[1];
		g_msgFrame.frame[2] = (g_msgFrame.frame[2] > 150)?0:g_msgFrame.frame[2];
		puhmsg.RXlinear  = ((float)g_msgFrame.frame[1])/100;
		puhmsg.Rangular  = ((float)g_msgFrame.frame[2])/100;
		pub.publish(puhmsg);
		//cout<<g_msgFrame.len<<endl;
		//cout<<(int)g_msgFrame.frame[1]<<endl;
		//cout<<puhmsg.RXlinear<<","<<puhmsg.Rangular<<endl;
		//printf("%02x %02x %02x %02x %02xs\r\n",g_msgFrame.frame[0],g_msgFrame.frame[1],g_msgFrame.frame[2],g_msgFrame.frame[3],g_msgFrame.frame[4]);

	}
}






















