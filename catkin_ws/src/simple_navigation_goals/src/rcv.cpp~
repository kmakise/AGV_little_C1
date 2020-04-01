#include <rcv.h>

/***********************************************************
*名称:                                         find_header
*功能:                           寻找协议标头，返回索引值
*参数:                           agreement_buf:      协议缓冲区
*  								  begin:                     从什么位置开始寻找
*                                    buf_size:                 缓冲区大小
*返回值:                       标头的下标
*上一次修改时间:        2018/9/3   14:23
*修改时间:                   2018/9/3   14:23
*修改人:                       张嘉皓
************************************************************/
int find_header(char* agreement_buf,int* begin,int buf_size)
{
	for(;*begin<buf_size;(*begin)++)
	 {
		if(agreement_buf[(*begin)] == HEAD && agreement_buf[(*begin)+1] == SENSOR_FLAG)					
		{
			return *begin;		
		}
		
		if(agreement_buf[(*begin)] == HEAD && agreement_buf[(*begin)+1] == ODOM_FLAG)					
		{
			return *begin;		
		}
				
	}
	return 666;
}
	
/***********************************************************************
*名称:                                   check_legal
*功能:                         检查解析出的协议是否合法,如合法将协议填充进发送缓冲区
*参数:     
-----------------------------------------------------------------------------------------------------------------------
*				                    @agreement:     解析出的协议
*								    @size: 		 	       解析协议大小
*   								@publish_msg:  发送缓冲区
-----------------------------------------------------------------------------------------------------------------------
*返回值:  
*                                    @COMPLETE:   解析成功
*									  @ERROR:          解析失败
----------------------------------------------------------------------------------------------------------------------
*上一次修改时间:        2018/9/5   15:17
*修改时间:                   2018/9/10  10:57
----------------------------------------------------------------------------------------------------------------------
*修改人:                       张嘉皓
***********************************************************************/
int check_legal(char* agreement,int size,char* publish_msg)
{
	//如果当前协议符合里程计标准
	if(size == ODOM_SIZE && agreement[1] == ODOM_FLAG)
	{
		return SUCCESS;	
	}
	else if(size == SENSOR_SIZE && agreement[1] == SENSOR_FLAG) 
	{
		unsigned int checksum = (agreement[2]&0xff^agreement[3]&0xff)+(agreement[4]&0xff^agreement[5]&0xff)+
													 (((agreement[6]&0xff^agreement[7]&0xff)^(agreement[8]&0xff^agreement[9]&0xff))+
													 ((agreement[10]&0xff^agreement[11]&0xff)^(agreement[12]&0xff^agreement[13]&0xff)));
		if((agreement[14]&0xff) == ((checksum>>8)&0xff) && (agreement[15]&0xff) == (checksum&0xff))
		{
			cout<<"校验位："<<checksum<<endl;
			return SUCCESS;	
		}
		printf("(checksum>>8)&0xff：%d\n",(checksum>>8)&0xff);
		printf("协议[15]&0xff：%d\n",agreement[15]&0xff);
		return ERROR;
	}
	//如果不符合两种规则则判断为无效消息
	else
	{
		if(agreement[1] == SENSOR_FLAG)  
		{
			printf("丢失数据长度为%d\n",size);
			return SENSOR_ERROR;
		}
		else
		{
			return ERROR;
		}
		return ERROR;
	}
}
/*-----------------------------------------------------华丽的分割线--------------------------------------------------*/
int check_legal(char* agreement,int size)
{
	//如果当前协议符合里程计标准
	if(size == ODOM_SIZE && agreement[1] == ODOM_FLAG)
	{
		return SUCCESS;	
	}
	else if(size == SENSOR_SIZE && agreement[1] == SENSOR_FLAG)
	{
		unsigned int checksum = (agreement[2]&0xff^agreement[3]&0xff)+(agreement[4]&0xff^agreement[5]&0xff)+
													 (((agreement[6]&0xff^agreement[7]&0xff)^(agreement[8]&0xff^agreement[9]&0xff))+
													 ((agreement[10]&0xff^agreement[11]&0xff)^(agreement[12]&0xff^agreement[13]&0xff)));
		if((agreement[14]&0xff) == ((checksum>>8)&0xff) && (agreement[15]&0xff) == (checksum&0xff))
		{
			cout<<"校验位："<<checksum<<endl;
			return SUCCESS;	
		}
		printf("(checksum>>8)&0xff：%d\n",(checksum>>8)&0xff);
		printf("协议[15]&0xff：%d\n",agreement[15]&0xff);
		return ERROR;
	}
	//如果不符合两种规则则判断为无效消息
	else
	{
		if(agreement[1] == SENSOR_FLAG)  
		{
			return SENSOR_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
}

/*********************************************************************
*名称:                                      save2temporary_buf
*功能:                               将不完整的协议存入临时缓冲区
*参数:                               
*------------------------------------------------------------------------------------------------------------------
*										 @temp:                           临时缓冲区结构体 
*------------------------------------------------------------------------------------------------------------------
*										 @agreement_buf:           协议缓冲区
*										 @agreement_buf_sub:   协议缓冲区当前的下标            ============>     后期优化成结构体


*										 @agreement_size:          协议缓冲区大小
*------------------------------------------------------------------------------------------------------------------
*										 @half:								  断数据标志位
--------------------------------------------------------------------------------------------------------------------
*返回值:                          @COMPLETE:                   拼接完成
--------------------------------------------------------------------------------------------------------------------
*上一次修改时间:            2018/9/4     13:40
*修改时间:                       2018/9/10  10:57
--------------------------------------------------------------------------------------------------------------------
*修改人:                           张嘉皓     注:当前代码参数过多，后期考虑改为结构体
*********************************************************************/
int save2temporary_buf(int* temp_sub,char* temp_buf,const char* agreement_buf,int agreement_buf_sub,int agreement_size,int* half)
{
	if(*temp_sub != 0)
	{
		printf("开始拼接数据下标不为0！\n");
		exit(0);
	}
	for(;agreement_buf_sub<agreement_size;agreement_buf_sub++)
	{
		temp_buf[*temp_sub] = agreement_buf[agreement_buf_sub];
		(*temp_sub)++;		
	}
	*half = 1;
	return COMPLETE;
}

/*************************************************************************
*名称:                                                  link2temporary_buf
*功能:                                               连接临时缓冲区(断数据)
*参数:                                        
*------------------------------------------------------------------------------------------------------------------------
*                                        @temp:                    临时缓冲区结构体
*------------------------------------------------------------------------------------------------------------------------
*										 @agreement_buf:           协议缓冲区
*										 @agreement_buf_sub:   协议缓冲区当期的下标            ============>     后期优化成结构体
*										 @agreement_size:          协议缓冲区大小
*									 	 @publish_msg:               发送缓冲区
*------------------------------------------------------------------------------------------------------------------------
*										 @half:								  断数据标志位
--------------------------------------------------------------------------------------------------------------------------
*返回值:                           
*										  SUCCESS:           拼接成功
*										  ERROR:               拼接失败
--------------------------------------------------------------------------------------------------------------------------
*上一次修改时间:            2018/9/5    15:13  
*修改时间:                       2018/9/10  10:57
--------------------------------------------------------------------------------------------------------------------------
*修改人:                           张嘉皓     注:当前代码参数过多，后期考虑改为结构体
*************************************************************************/
int link2temporary_buf(int* temp_sub,char* temp_buf,const char* agreement_buf,int* agreement_buf_sub,int agreement_size,int* half,char* publish_msg)
{
	/*************************如产品化此处应加入拼接下标监测机制*************************/
	
	/*************************如产品化此处应加入拼接下标监测机制*************************/



	/*************************进行数据拼接**************************/
	bool success = true;
	while(success)
	{	
		success = (agreement_buf[*agreement_buf_sub] != END );       		//如果没有找到结束标志，则继续寻找
		if(temp_buf[1] == SENSOR_FLAG && *temp_sub < SENSOR_SIZE -1)		//如果没符合规范，则继续寻找
		{
			success = true;
		}
		temp_buf[*temp_sub] = agreement_buf[(*agreement_buf_sub)];
		(*agreement_buf_sub)++;
		(*temp_sub)++;
	}
	//temp->buf[*(temp->sub)] = agreement_buf[*agreement_buf_sub];
	/*************************进行数据拼接**************************/

	//将临时缓冲区的数据赋值给发送缓冲	区
	memcpy(publish_msg,temp_buf,(*temp_sub));
	
	int size = *temp_sub;
	/*************************恢复默认**************************/
	*temp_sub = 0;
	*half   		   = 0;
	/*************************恢复默认**************************/
	
	return check_legal(publish_msg,size,publish_msg);;
}


/***********************************************************
*名称:                                    analysis_buffer 
*功能:                          将缓冲区的內容拼接成字符串
*参数:                           agreement_buf:       协议缓冲区
*									  begin:                       从什么位置开始寻找
*								      buf_size:                   缓冲区大小
*								      publish_msg:           解析好的协议  
*返回值:                        当前下标
*上一次修改时间:        2018/9/3   14:23
*修改时间:                   2018/9/10  10:57  
*修改人:                       张嘉皓
***********************************************************/
int analysis_buffer(char* agreement_buf,int* begin,int buf_size,char* publish_msg)
{
	/*********************************************拼接缓冲区数据***********************************************/
	static int        half                              = 0;    														//临时缓冲区开启标志位  0:关闭  1:开启
	static int        temporary_buf_size    = 0;   													    //临时缓冲区大小
	static char*   temporary_buf           = (char*)malloc(sizeof(char*)*20);    //临时缓冲区
	int temporary_sub;																							//记录断数据标头  注:断数据==>协议接收一半的数据
	/*********************************************拼接缓冲区数据***********************************************/
/*	struct temporary temp;
	/***************************************结构体与拼接缓冲区建立连接*****************************************/
/*	temp.buf = 	temporary_buf;
	temp.sub = &temporary_buf_size;
	/***************************************结构体与拼接缓冲区建立连接*****************************************/

	//断数据拼接0
	if(half)
	{
		return link2temporary_buf(&temporary_buf_size,temporary_buf,agreement_buf,begin,buf_size,&half,publish_msg);
	}	

	*begin                      = find_header(agreement_buf,begin,buf_size);          	  //寻找协议头下标
	if(*begin == 666)
	{
		return COMPLETE;
	}
	temporary_sub        = *begin;																				  //如果出现断数据,记录标头位置				
	int pub_sub             = 0;			                                                                                  //publish_msg的下标
	bool success = true;
	//找到标尾结束循环
	while(success)
	{
		success = (agreement_buf[*begin] != END);
		if(publish_msg[1] == SENSOR_FLAG && pub_sub < SENSOR_SIZE -1)
		{
			success = true;
		}
		if(publish_msg[1] == ODOM_FLAG && pub_sub < ODOM_SIZE -1)
		{
			success = true;
		}
		//如果当前下标已到结尾还未找到结束标志打开断数据标志位并存储不完整消息至临时缓冲区
		if(*begin == buf_size)
		{
			return save2temporary_buf(&temporary_buf_size,temporary_buf,agreement_buf,temporary_sub,buf_size,&half);
		}
		publish_msg[pub_sub] = agreement_buf[*begin];
		pub_sub++;
		(*begin)++;
	}
	//publish_msg[pub_sub] = agreement_buf[*begin];
	temporary_sub = 0;	
	return check_legal(publish_msg,pub_sub);
}


