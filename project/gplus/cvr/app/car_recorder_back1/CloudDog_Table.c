//#ifdef __CLOUDDOG_TABLE_C__
//#define __CLOUDDOG_TABLE_C__
#include "CloudDog.h"
#define X_POS 0
#define Y_POS 0
char cloudDogString[7][500]={ //0 启动安防开机协议
                     {0x41,0x54,0x55,0x08,0x00,0x20,0x00,0x01,0x13,'\n'},
                     //1 GPS 信息
                     {0x41,0x54,0x55,0x21,0x00,0x10,0x41,0x3A,0x0B,0x23,0x00, 0x4E,0x7A,0xCE,0xAD,0x00,0x45,0x1C,0x32,0x00,0x00,0x00,0x00, 0xDB,0x07,0x03,0x07,0x11,0x37,0x23,0x1F,0x01,0x00,0x11,'\n'},
                     //2 固定报警信息
                     {0x41,0x54,0x55,0x3C,0x00,0x11,0x02,0x4C,0x01,0x3C,0x2B,0x8A,0x00,0x00,0x4D,0x52,0xB9,0x65,0x33,0x00,0x30,0x00,0x30,0x00,0x73,0x7C,0x09,0x67,0xEF,0x95,0xA2,0x7E,0x6F,0x70,0xCD,0x62,0x67,0x71,0x2C,0x00,0x50,0x96,0x1F,0x90,0x36,0x00,0x30,0x00,0x6C,0x51,0xCC,0x91,0x2C,0x00,0xF7,0x8B,0xE8,0x6C,0x0F,0x61,0x63,'\n'},
                     //3 雷达报警信息
                     {0x41,0x54,0x55,0x0E,0x00,0x12,0x20,0x02,0xFF,0xFF,0x24,0x2C,0x00,0x00,0x7A,'\n'},
                     //4 功能菜单信息获取
                     {0x41,0x54,0x55,0x1E,0x00,0x13,0x00,0x06,0x32,0x78,0x01,0x0A,0x00,0xB6,0x00,0x53,0x96,0x75,0x30,0x30,0x35,0x75,0x08,0x31,0x14,0x72,0x36,0x89,0x04,0x00,0x76,'\n'},
                     //5 天气预报
                     {0x41,0x54,0x55,0x27,0x00,0x18,0xAA,0xF1,0x6D,0x33,0x57,0x02,0x5E,0x20,0x00,0x32,0x00,0x36,0x00,0x2D,0x00,0x33,0x00,0x32,0x00,0x44,0x64,0x0F,0x6C,0xA6,0x5E,0x20,0x00,0x35,0x96,0xE8,0x96,0x20,0x00,0xE5,'\n'},
                     //6 投诉键协议
                     {0x41,0x54,0x55,0x07,0x00,0x19,0x01,0x0B,0x0D,0x0A,'\n'},
                    };
//状态条开始位置 每个控件间距
#define STATUS_BAR_Y    3
#define STATUS_BAR_SPACE 40
//电池电量
#define BAT_X       		285
#define BAT_Y       		STATUS_BAR_Y
#define BAT_TRAN    		RGB888_TO_RGB565(0xc0c0c0)
//GPS数量
#define GPS_X       		100
#define GPS_Y       		STATUS_BAR_Y
#define GPS_TRAN    		RGB888_TO_RGB565(0xc0c0c0)
//GSM信号
#define SIGNAL_X        	10
#define SIGNAL_Y        	STATUS_BAR_Y
#define SIGNAL_TRAN     	RGB888_TO_RGB565(0xc0c0c0)

#define MENU_MAXSPEED_X     122
#define MENU_MAXSPEED_Y     STATUS_BAR_Y
#define MENU_MAXSPEED_TRAN  RGB888_TO_RGB565(0xc0c0c0)

//指南针
#define COMPASS_X      		167 
#define COMPASS_Y      		89
#define COMPASS_TRAN   		RGB888_TO_RGB565(0xbdbdbd)
//数字0-9 		
#define NUM_X       		144
#define NUM_Y       		186
#define NUM_TRAN    		RGB888_TO_RGB565(0xbdbdbd)
//雷达		
#define RADAR_X     		265 
#define RADAR_Y     		166
#define RADAR_TRAN  		RGB888_TO_RGB565(0x211919)
//超速警告
#define SPEED_X     		266
#define SPEED_Y     		40
#define SPEED_TRAN  		RGB888_TO_RGB565(0xc0c0c0)
//电子狗检测报警
#define WARNING_X       	266
#define WARNING_Y       	109
#define WARNING_TRAN    	RGB888_TO_RGB565(0xc0c0c0)
//车速指针
#define SPEED_POINTER_X     34
#define SPEED_POINTER_Y     79
#define SPEED_POINTER_TRAN  RGB888_TO_RGB565(0xffffff)


#define MENU_MODE_X         MENU_MAXSPEED_X+STATUS_BAR_SPACE
#define MENU_MODE_Y         MENU_MAXSPEED_Y
#define MENU_MODE_TRAN      MENU_MAXSPEED_TRAN

#define MENU_MUTE_X			MENU_MODE_X+STATUS_BAR_SPACE
#define MENU_MUTE_Y         MENU_MAXSPEED_Y
#define MENU_MUTE_TRAN      MENU_MAXSPEED_TRAN

#define MENU_SPEED_X		MENU_MUTE_X+STATUS_BAR_SPACE
#define MENU_SPEED_Y      	MENU_MAXSPEED_Y
#define MENU_SPEED_TRAN   	MENU_MAXSPEED_TRAN

#define MENU_VER_X			MENU_SPEED_X+STATUS_BAR_SPACE
#define MENU_VER_Y       	MENU_MAXSPEED_Y
#define MENU_VER_TRAN    	MENU_MAXSPEED_TRAN

#define MENU_VOLUMEA_X		MENU_VER_X+STATUS_BAR_SPACE
#define MENU_VOLUMEA_Y    	MENU_MAXSPEED_Y
#define MENU_VOLUMEA_TRAN 	MENU_MAXSPEED_TRAN

iconManager_t Icon_Manager_CloudDog[DOG_ICON_NUM_MAX]={
{"BACKGROUND.bin"      ,DOG_ICON_BACKGROUND            ,320,240,0    ,0    ,RGB888_TO_RGB565(0x00ff33) ,NULL   ,0  },


{"R_BAT_0.bin"			,DOG_ICON_R_BAT_0		,24	,24	,X_POS+BAT_X	,Y_POS+BAT_Y	,BAT_TRAN	,NULL	,0	},
{"R_BAT_1.bin"			,DOG_ICON_R_BAT_1		,24	,24	,X_POS+BAT_X	,Y_POS+BAT_Y	,BAT_TRAN	,NULL	,0	},
{"R_BAT_2.bin"			,DOG_ICON_R_BAT_2		,24	,24	,X_POS+BAT_X	,Y_POS+BAT_Y	,BAT_TRAN	,NULL	,0	},
{"R_BAT_3.bin"			,DOG_ICON_R_BAT_3		,24	,24	,X_POS+BAT_X	,Y_POS+BAT_Y	,BAT_TRAN	,NULL	,0	},

{"R_COMPASS_NULL.bin"	,DOG_ICON_R_COMPASS_NULL,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_1.bin"		,DOG_ICON_R_COMPASS_1	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_2.bin"		,DOG_ICON_R_COMPASS_2	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_3.bin"		,DOG_ICON_R_COMPASS_3	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_4.bin"		,DOG_ICON_R_COMPASS_4	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_5.bin"		,DOG_ICON_R_COMPASS_5	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_6.bin"		,DOG_ICON_R_COMPASS_6	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_7.bin"		,DOG_ICON_R_COMPASS_7	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_8.bin"		,DOG_ICON_R_COMPASS_8	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_S1.bin"		,DOG_ICON_R_COMPASS_S1	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_S2.bin"		,DOG_ICON_R_COMPASS_S2	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_S3.bin"		,DOG_ICON_R_COMPASS_S3	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},
{"R_COMPASS_S4.bin"		,DOG_ICON_R_COMPASS_S4	,64	,64	,X_POS+COMPASS_X	,Y_POS+COMPASS_Y	,COMPASS_TRAN	,NULL	,0	},

{"R_GPS_OFF.bin"		,DOG_ICON_R_GPS_OFF		,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_ON.bin"			,DOG_ICON_R_GPS_ON		,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM1.bmp"		,DOG_ICON_R_GPS_NUM1	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM2.bin"		,DOG_ICON_R_GPS_NUM2	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM3.bin"		,DOG_ICON_R_GPS_NUM3	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM4.bin"		,DOG_ICON_R_GPS_NUM4	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM5.bin"		,DOG_ICON_R_GPS_NUM5	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM6.bin"		,DOG_ICON_R_GPS_NUM6	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM7.bin"		,DOG_ICON_R_GPS_NUM7	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM8.bin"		,DOG_ICON_R_GPS_NUM8	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM9.bin"		,DOG_ICON_R_GPS_NUM9	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM10.bin"		,DOG_ICON_R_GPS_NUM10	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM11.bin"		,DOG_ICON_R_GPS_NUM11	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM12.bin"		,DOG_ICON_R_GPS_NUM12	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM13.bin"		,DOG_ICON_R_GPS_NUM13	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM14.bin"		,DOG_ICON_R_GPS_NUM14	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM15.bin"		,DOG_ICON_R_GPS_NUM15	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM16.bin"		,DOG_ICON_R_GPS_NUM16	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM17.bin"		,DOG_ICON_R_GPS_NUM17	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM18.bin"		,DOG_ICON_R_GPS_NUM18	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM19.bin"		,DOG_ICON_R_GPS_NUM19	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_GPS_NUM20.bin"		,DOG_ICON_R_GPS_NUM20	,24	,24	,X_POS+GPS_X	,Y_POS+GPS_Y	,GPS_TRAN	,NULL	,0	},
{"R_NUM_0.bin"			,DOG_ICON_R_NUM_0		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_1.bin"			,DOG_ICON_R_NUM_1		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_2.bin"			,DOG_ICON_R_NUM_2		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_3.bin"			,DOG_ICON_R_NUM_3		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_4.bin"			,DOG_ICON_R_NUM_4		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_5.bin"			,DOG_ICON_R_NUM_5		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_6.bin"			,DOG_ICON_R_NUM_6		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_7.bin"			,DOG_ICON_R_NUM_7		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_8.bin"			,DOG_ICON_R_NUM_8		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"R_NUM_9.bin"			,DOG_ICON_R_NUM_9		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_0.bin"			,DOG_ICON_RR_NUM_0		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_1.bin"			,DOG_ICON_RR_NUM_1		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_2.bin"			,DOG_ICON_RR_NUM_2		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_3.bin"			,DOG_ICON_RR_NUM_3		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_4.bin"			,DOG_ICON_RR_NUM_4		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_5.bin"			,DOG_ICON_RR_NUM_5		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_6.bin"			,DOG_ICON_RR_NUM_6		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_7.bin"			,DOG_ICON_RR_NUM_7		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_8.bin"			,DOG_ICON_RR_NUM_8		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},
{"RR_NUM_9.bin"			,DOG_ICON_RR_NUM_9		,16	,24	,X_POS+NUM_X	,Y_POS+NUM_Y	,NUM_TRAN	,NULL	,0	},

{"R_RADAR_OFF.bin"		,DOG_ICON_R_RADAR_OFF	,24	,24	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR_ON.bin"		,DOG_ICON_R_RADAR_ON	,24	,24	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR0_X.bin"		,DOG_ICON_R_RADAR0_X	,40	,32	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR1_LA.bin"		,DOG_ICON_R_RADAR1_LA	,40	,32	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR2_KU.bin"		,DOG_ICON_R_RADAR2_KU	,40	,32	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR3_KA.bin"		,DOG_ICON_R_RADAR3_KA	,40	,32	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
{"R_RADAR4_K.bin"		,DOG_ICON_R_RADAR4_K	,40	,32	,X_POS+RADAR_X	,Y_POS+RADAR_Y	,RADAR_TRAN	,NULL	,0	},
	
{"R_SIGNAL_0.bin"		,DOG_ICON_R_SIGNAL_0	,24	,24	,X_POS+SIGNAL_X	,Y_POS+SIGNAL_Y	,SIGNAL_TRAN	,NULL	,0	},
{"R_SIGNAL_1.bin"		,DOG_ICON_R_SIGNAL_1	,24	,24	,X_POS+SIGNAL_X	,Y_POS+SIGNAL_Y	,SIGNAL_TRAN	,NULL	,0	},
{"R_SIGNAL_2.bin"		,DOG_ICON_R_SIGNAL_2	,24	,24	,X_POS+SIGNAL_X	,Y_POS+SIGNAL_Y	,SIGNAL_TRAN	,NULL	,0	},
{"R_SIGNAL_3.bin"		,DOG_ICON_R_SIGNAL_3	,24	,24	,X_POS+SIGNAL_X	,Y_POS+SIGNAL_Y	,SIGNAL_TRAN	,NULL	,0	},
{"R_SIGNAL_4.bin"		,DOG_ICON_R_SIGNAL_4	,24	,24	,X_POS+SIGNAL_X	,Y_POS+SIGNAL_Y	,SIGNAL_TRAN	,NULL	,0	},

{"R_SPEED_10.bin"		,DOG_ICON_R_SPEED_10	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_20.bin"		,DOG_ICON_R_SPEED_20	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_30.bin"		,DOG_ICON_R_SPEED_30	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_35.bin"		,DOG_ICON_R_SPEED_35	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_40.bin"		,DOG_ICON_R_SPEED_40	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_45.bin"		,DOG_ICON_R_SPEED_45	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_50.bin"		,DOG_ICON_R_SPEED_50	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_60.bin"		,DOG_ICON_R_SPEED_60	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_70.bin"		,DOG_ICON_R_SPEED_70	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_80.bin"		,DOG_ICON_R_SPEED_80	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_90.bin"		,DOG_ICON_R_SPEED_90	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_100.bin"		,DOG_ICON_R_SPEED_100	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_110.bin"		,DOG_ICON_R_SPEED_110	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_120.bin"		,DOG_ICON_R_SPEED_120	,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},
{"R_SPEED_W_NULL.bin"	,DOG_ICON_R_SPEED_W_NULL,40	,40	,X_POS+SPEED_X	,Y_POS+SPEED_Y	,SPEED_TRAN	,NULL	,0	},

{"R_WARNING_02.bin"		,DOG_ICON_R_WARNING_02	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_20.bin"		,DOG_ICON_R_WARNING_20	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_22.bin"		,DOG_ICON_R_WARNING_22	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_70.bin"		,DOG_ICON_R_WARNING_70	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_71.bin"		,DOG_ICON_R_WARNING_71	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_72.bin"		,DOG_ICON_R_WARNING_72	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_73.bin"		,DOG_ICON_R_WARNING_73	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_81.bin"		,DOG_ICON_R_WARNING_81	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_83.bin"		,DOG_ICON_R_WARNING_83	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_84.bin"		,DOG_ICON_R_WARNING_84	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_85.bin"		,DOG_ICON_R_WARNING_85	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_87.bin"		,DOG_ICON_R_WARNING_87	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_88.bin"		,DOG_ICON_R_WARNING_88	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_89.bin"		,DOG_ICON_R_WARNING_89	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_90.bin"		,DOG_ICON_R_WARNING_90	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_91.bin"		,DOG_ICON_R_WARNING_91	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_92.bin"		,DOG_ICON_R_WARNING_92	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_93.bin"		,DOG_ICON_R_WARNING_93	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_94.bin"		,DOG_ICON_R_WARNING_94	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_95.bin"		,DOG_ICON_R_WARNING_95	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_96.bin"		,DOG_ICON_R_WARNING_96	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_97.bin"		,DOG_ICON_R_WARNING_97	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_98.bin"		,DOG_ICON_R_WARNING_98	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_99.bin"		,DOG_ICON_R_WARNING_99	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_101.bin"	,DOG_ICON_R_WARNING_101	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_102.bin"	,DOG_ICON_R_WARNING_102	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_108.bin"	,DOG_ICON_R_WARNING_108	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},
{"R_WARNING_110.bin"	,DOG_ICON_R_WARNING_110	,40	,32	,X_POS+WARNING_X	,Y_POS+WARNING_Y	,WARNING_TRAN	,NULL	,0	},

{"RADAR_MAXSPEED.bin"	,DOG_ICON_RADAR_MAXSPEED,32	,32	,X_POS+MENU_MAXSPEED_X	,Y_POS+MENU_MAXSPEED_Y	,MENU_MAXSPEED_TRAN	,NULL	,0	},
{"RADAR_MODE.bin"		,DOG_ICON_RADAR_MODE	,32	,32	,X_POS+MENU_MODE_X	,Y_POS+MENU_MODE_Y	,MENU_MODE_TRAN	,NULL	,0	},
{"RADAR_MUTE.bin"		,DOG_ICON_RADAR_MUTE	,32	,32	,X_POS+MENU_MUTE_X	,Y_POS+MENU_MUTE_Y	,MENU_MUTE_TRAN	,NULL	,0	},
{"RADAR_SPEED.bin"		,DOG_ICON_RADAR_SPEED	,32	,32	,X_POS+MENU_SPEED_X	,Y_POS+MENU_SPEED_Y	,MENU_SPEED_TRAN	,NULL	,0	},
{"RADAR_VER.bin"		,DOG_ICON_RADAR_VER		,32	,32	,X_POS+MENU_VER_X	,Y_POS+MENU_VER_Y	,MENU_VER_TRAN	,NULL	,0	},
{"RADAR_VOLUMEA.bin"	,DOG_ICON_RADAR_VOLUMEA	,32	,32	,X_POS+MENU_VOLUMEA_X	,Y_POS+MENU_VOLUMEA_Y	,MENU_VOLUMEA_TRAN	,NULL	,0	},

{"R_POINTER_0.bin"	,DOG_ICON_R_SPEED_POINTER_0		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_1.bin"	,DOG_ICON_R_SPEED_POINTER_1		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_2.bin"	,DOG_ICON_R_SPEED_POINTER_2		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_3.bin"	,DOG_ICON_R_SPEED_POINTER_3		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_4.bin"	,DOG_ICON_R_SPEED_POINTER_4		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_5.bin"	,DOG_ICON_R_SPEED_POINTER_5		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_6.bin"	,DOG_ICON_R_SPEED_POINTER_6		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_7.bin"	,DOG_ICON_R_SPEED_POINTER_7		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_8.bin"	,DOG_ICON_R_SPEED_POINTER_8		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_9.bin"	,DOG_ICON_R_SPEED_POINTER_9		,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_10.bin"	,DOG_ICON_R_SPEED_POINTER_10	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_11.bin"	,DOG_ICON_R_SPEED_POINTER_11	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_12.bin"	,DOG_ICON_R_SPEED_POINTER_12	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_13.bin"	,DOG_ICON_R_SPEED_POINTER_13	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_14.bin"	,DOG_ICON_R_SPEED_POINTER_14	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_15.bin"	,DOG_ICON_R_SPEED_POINTER_15	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_16.bin"	,DOG_ICON_R_SPEED_POINTER_16	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_17.bin"	,DOG_ICON_R_SPEED_POINTER_17	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_18.bin"	,DOG_ICON_R_SPEED_POINTER_18	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_19.bin"	,DOG_ICON_R_SPEED_POINTER_19	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_20.bin"	,DOG_ICON_R_SPEED_POINTER_20	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_21.bin"	,DOG_ICON_R_SPEED_POINTER_21	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_22.bin"	,DOG_ICON_R_SPEED_POINTER_22	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_23.bin"	,DOG_ICON_R_SPEED_POINTER_23	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_24.bin"	,DOG_ICON_R_SPEED_POINTER_24	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_25.bin"	,DOG_ICON_R_SPEED_POINTER_25	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_26.bin"	,DOG_ICON_R_SPEED_POINTER_26	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_27.bin"	,DOG_ICON_R_SPEED_POINTER_27	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_28.bin"	,DOG_ICON_R_SPEED_POINTER_28	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_29.bin"	,DOG_ICON_R_SPEED_POINTER_29	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_30.bin"	,DOG_ICON_R_SPEED_POINTER_30	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_31.bin"	,DOG_ICON_R_SPEED_POINTER_31	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_32.bin"	,DOG_ICON_R_SPEED_POINTER_32	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_33.bin"	,DOG_ICON_R_SPEED_POINTER_33	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_34.bin"	,DOG_ICON_R_SPEED_POINTER_34	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_35.bin"	,DOG_ICON_R_SPEED_POINTER_35	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_36.bin"	,DOG_ICON_R_SPEED_POINTER_36	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_37.bin"	,DOG_ICON_R_SPEED_POINTER_37	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_38.bin"	,DOG_ICON_R_SPEED_POINTER_38	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},
{"R_POINTER_39.bin"	,DOG_ICON_R_SPEED_POINTER_39	,88	,80	,X_POS+SPEED_POINTER_X	,Y_POS+SPEED_POINTER_Y	,SPEED_POINTER_TRAN	,NULL	,0	},


};
//#endif
