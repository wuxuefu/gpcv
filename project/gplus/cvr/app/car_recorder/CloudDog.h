﻿#ifndef CARDV_CLOUDDOG_H
#define CARDV_CLOUDDOG_H



#define ENUM_DUMMY4WORD(name)   E_##name = 0x10000000
#define ICON_PATH_DOG "/system/resource/dog_icon/"

        
#define TRANSPARENT_COLOR_DOG_24x24      0xc618  
#define TRANSPARENT_COLOR_DOG_32x56      0xbdf7
#define TRANSPARENT_COLOR_DOG_32x32      TRANSPARENT_COLOR_DOG_24x24
#define TRANSPARENT_COLOR_DOG_48x64      TRANSPARENT_COLOR_DOG_24x24
#define TRANSPARENT_COLOR_DOG_72x88      TRANSPARENT_COLOR_DOG_32x56
#define TRANSPARENT_COLOR_DOG_80x96      TRANSPARENT_COLOR_DOG_32x56
#define TRANSPARENT_COLOR_DOG_96x120     0xbefe


#ifndef NULL
#define NULL (void *)0
#endif

#if defined(__arm )

#define _ALIGNED(x) __align(x)
#define _PACKED_BEGIN __packed
#define _PACKED_END
#define _INLINE static __inline
#define _ASM_NOP __asm{nop;}
#define _SECTION(sec)
#define _CALLBACK()
#define _CALLBACK_SECTION(sec)
#define _MIPS_TODO 1
#define _DRV650_TODO 0
#define _STOPTRACE
#elif defined( __WIN32__)
#define _PACKED_BEGIN
#define _PACKED_END
#elif defined( __GNUC__)

#define _ALIGNED(x) __attribute__((aligned(x)))
#define _PACKED_BEGIN
#define _PACKED_END __attribute__ ((packed)) 
#define _INLINE static inline
#define _ASM_NOP __asm__("nop");
#define _SECTION(sec)          __attribute__ ((section (sec)))
#define _CALLBACK()            __attribute__ ((weak))
#define _CALLBACK_SECTION(sec) __attribute__ ((weak, section(sec)))
#define _MIPS_TODO 0
#define _DRV650_TODO 0
#define _STOPTRACE __attribute__((__no_instrument_function__))
#endif

#define __SYSTEM_32_BIT__ 1
#define __SYSTEM_64_BIT__ 2
#define __SYSTEM_USER_BIT__ 3
#define __SYSTEM_DATA_TYPEDEF__ __SYSTEM_USER_BIT__

#if (__SYSTEM_DATA_TYPEDEF__ == __SYSTEM_32_BIT__)
typedef unsigned long long  UINT64;     ///< Unsigned 64 bits data type
typedef signed long long    INT64;      ///< Signed 64 bits data type
typedef unsigned int       UINT32;     ///< Unsigned 32 bits data type
typedef signed int         INT32;      ///< Signed 32 bits data type
typedef unsigned short      UINT16;     ///< Unsigned 16 bits data type
typedef signed short        INT16;      ///< Signed 16 bits data type
typedef unsigned char       UINT8;      ///< Unsigned 8 bits data type
typedef signed char         INT8;       ///< Signed 8 bits data type
typedef float               FLOAT;      ///< Floating point integer
typedef unsigned int        UBITFIELD;  ///< Unsigned bit field
typedef signed int          BITFIELD;   ///< Signed bit field
typedef UINT32              BOOL;
#elif(__SYSTEM_DATA_TYPEDEF__ == __SYSTEM_64_BIT__)
typedef unsigned  long  UINT64;     ///< Unsigned 64 bits data type
typedef signed  long    INT64;      ///< Signed 64 bits data type
typedef unsigned int       UINT32;     ///< Unsigned 32 bits data type
typedef signed int         INT32;      ///< Signed 32 bits data type
typedef unsigned short      UINT16;     ///< Unsigned 16 bits data type
typedef signed short        INT16;      ///< Signed 16 bits data type
typedef unsigned char       UINT8;      ///< Unsigned 8 bits data type
typedef signed char         INT8;       ///< Signed 8 bits data type
typedef float               FLOAT;      ///< Floating point integer
typedef unsigned int        UBITFIELD;  ///< Unsigned bit field
typedef signed int          BITFIELD;   ///< Signed bit field
typedef UINT32              BOOL;
#else
#include "mach/typedef.h"
typedef UINT32              BOOL;
typedef SINT32              INT32;
typedef SINT16              INT16;
#endif

#ifndef ENABLE
#define ENABLE 		1
#endif
#ifndef DISABLE
#define DISABLE		0
#endif


typedef enum
{
    TYPE_SECURITY_BOOT=0x20,//安防开机
    TYPE_GPS_INFO = 0x10,//GPS 信息
    TYPE_FIXED_ALARM = 0x11,//固定报警信息
    TYPE_RADAR_ALARM = 0x12,//雷达报警信息
    TYPE_MENU_INFO = 0x13,//功能菜单信息获取
    TYPE_WEATHER = 0x18,//天气预报
    TYPE_COMPLAIN = 0x19,//投诉键协议
    ENUM_DUMMY4WORD(DATA_TYPES),
}DATA_TYPES;
typedef enum
{
    ALARM_RED_CAMERA_02 = 2,//闯红灯拍照
    ALARM_RED_NO_CAMERA_03 = 3,//闯红灯无拍照
    ALARM_FIXED_SPEED_12  = 12,//固定测速
    ALARM_INTERVAL_VELOCITY_20 = 20,//区间测速
    ALARM_INTERVAL_VELOCITY_STARTING_21=21,//区间测速起点
    ALARM_INTERVAL_VELOCITY_END_22 = 22,//区间测速终点
    ALARM_FLOW_VELOCITY_24 = 24,//流动测速
    ALARM_TEMPORARY_PARKING_BAN_70 = 70,//禁止临时停车
    ALARM_PROHIBITING_OFF_HEAD_71 = 71,//禁止掉头
    ALARM_PROHIBITED_LEFT_TURN_72 = 72,//禁止左转
    ALARM_PROHIBITED_RIGHT_TURN_73 = 73,//禁止右?    ALARM_ELECTRONIC_MONITORING_81 = 81,//电子监控
    ALARM_CAR_TRAFFIC_MONITORING_82 = 82,//汽车流量监控
    ALARM_DRIVING_BEHAVIOR_83 = 83,//驾驶行为
    ALARM_VIOLATION_84 = 84,//压实线,违规变道
    ALARM_BUS_LANES_85 = 85,//公交车专用车道
    ALARM_OCCUPANCY_SHUNT_86 = 86,//占用分流道
    ALARM_UNIDIRECTIONAL_RETROGRADE_87 = 87,//单向逆行
    ALARM_PROHIBITED_LINKS_88 = 88,//禁行路段
    ALARM_ILLEGAL_PARKING_89 = 89,//违章停车
    ALARM_SCHOOL_SECTIONS_90 = 90,//学校路段
    ALARM_SNOW_ROAD_SECTIONS_91 = 91,//冰雪路段
    ALARM_MOUNTAIN_ROAD_SECTIONS_91 = 92,//山地路段
    ALARM_ACCIDENT_MULTIPLE_93 = 93,//事故多发路段
    ALARM_ANXIOUS_TURN_94 = 94,//急转弯
    ALARM_CONTINUOUS_CURVE_95 = 95,//连续弯道
    ALARM_ANXIOUS_DOWNHILL_96 = 96,//急下坡
    ALARM_ROCKFALL_97 = 97,//落石
    ALARM_FOGGY_98 = 98,//多雾
    ALARM_MILITARY_CONTROL_99 = 99,//军事管制
    ALARM_GAS_STATION_101 = 101,//加油站
    ALARM_SERVICE_AREA_102 = 102,//服务?    ALARM_DAY_ROAD_LIGHTS_103 = 103,//全天候开头灯路段
    ALARM_FEE_STATION_108 = 108,//收费站
    ALARM_TUNNEL_110 = 110,//隧道
    ENUM_DUMMY4WORD(ALARM_TYPE_TABLE),
}ALARM_TYPE_TABLE;
typedef enum
{
    DOG_ICON_BACKGROUND=0,
    
    DOG_ICON_R_BAT_0,
    DOG_ICON_R_BAT_1,
    DOG_ICON_R_BAT_2,
    DOG_ICON_R_BAT_3,
    DOG_ICON_R_COMPASS_NULL,
    DOG_ICON_R_COMPASS_1,
    DOG_ICON_R_COMPASS_2,
    DOG_ICON_R_COMPASS_3,
    DOG_ICON_R_COMPASS_4,
    DOG_ICON_R_COMPASS_5,
    DOG_ICON_R_COMPASS_6,
    DOG_ICON_R_COMPASS_7,
    DOG_ICON_R_COMPASS_8,
    DOG_ICON_R_COMPASS_S1,
    DOG_ICON_R_COMPASS_S2,
    DOG_ICON_R_COMPASS_S3,
    DOG_ICON_R_COMPASS_S4,
    DOG_ICON_R_GPS_OFF,
    DOG_ICON_R_GPS_ON,
    DOG_ICON_R_GPS_NUM1,
    DOG_ICON_R_GPS_NUM2,
    DOG_ICON_R_GPS_NUM3,
    DOG_ICON_R_GPS_NUM4,
    DOG_ICON_R_GPS_NUM5,
    DOG_ICON_R_GPS_NUM6,
    DOG_ICON_R_GPS_NUM7,
    DOG_ICON_R_GPS_NUM8,
    DOG_ICON_R_GPS_NUM9,
    DOG_ICON_R_GPS_NUM10,
    DOG_ICON_R_GPS_NUM11,
    DOG_ICON_R_GPS_NUM12,
    DOG_ICON_R_GPS_NUM13,
    DOG_ICON_R_GPS_NUM14,
    DOG_ICON_R_GPS_NUM15,
    DOG_ICON_R_GPS_NUM16,
    DOG_ICON_R_GPS_NUM17,
    DOG_ICON_R_GPS_NUM18,
    DOG_ICON_R_GPS_NUM19,
    DOG_ICON_R_GPS_NUM20,
    DOG_ICON_R_NUM_0,
    DOG_ICON_R_NUM_1,
    DOG_ICON_R_NUM_2,
    DOG_ICON_R_NUM_3,
    DOG_ICON_R_NUM_4,
    DOG_ICON_R_NUM_5,
    DOG_ICON_R_NUM_6,
    DOG_ICON_R_NUM_7,
    DOG_ICON_R_NUM_8,
    DOG_ICON_R_NUM_9,
    DOG_ICON_RR_NUM_0,
    DOG_ICON_RR_NUM_1,
    DOG_ICON_RR_NUM_2,
    DOG_ICON_RR_NUM_3,
    DOG_ICON_RR_NUM_4,
    DOG_ICON_RR_NUM_5,
    DOG_ICON_RR_NUM_6,
    DOG_ICON_RR_NUM_7,
    DOG_ICON_RR_NUM_8,
    DOG_ICON_RR_NUM_9,
    DOG_ICON_R_RADAR_OFF,
    DOG_ICON_R_RADAR_ON,
    DOG_ICON_R_RADAR0_X,
    DOG_ICON_R_RADAR1_LA,
    DOG_ICON_R_RADAR2_KU,
    DOG_ICON_R_RADAR3_KA,
    DOG_ICON_R_RADAR4_K,
    DOG_ICON_R_SIGNAL_0,
    DOG_ICON_R_SIGNAL_1,
    DOG_ICON_R_SIGNAL_2,
    DOG_ICON_R_SIGNAL_3,
    DOG_ICON_R_SIGNAL_4,
    DOG_ICON_R_SPEED_10,
    DOG_ICON_R_SPEED_20,
    DOG_ICON_R_SPEED_30,
    DOG_ICON_R_SPEED_35,
    DOG_ICON_R_SPEED_40,
    DOG_ICON_R_SPEED_45,
    DOG_ICON_R_SPEED_50,
    DOG_ICON_R_SPEED_60,
    DOG_ICON_R_SPEED_70,
    DOG_ICON_R_SPEED_80,
    DOG_ICON_R_SPEED_90,
    DOG_ICON_R_SPEED_100,
    DOG_ICON_R_SPEED_110,
    DOG_ICON_R_SPEED_120,
    DOG_ICON_R_SPEED_W_NULL,
    DOG_ICON_R_WARNING_02,
    DOG_ICON_R_WARNING_20,
    DOG_ICON_R_WARNING_22,
    DOG_ICON_R_WARNING_70,
    DOG_ICON_R_WARNING_71,
    DOG_ICON_R_WARNING_72,
    DOG_ICON_R_WARNING_73,
    DOG_ICON_R_WARNING_81,
    DOG_ICON_R_WARNING_83,
    DOG_ICON_R_WARNING_84,
    DOG_ICON_R_WARNING_85,
    DOG_ICON_R_WARNING_87,
    DOG_ICON_R_WARNING_88,
    DOG_ICON_R_WARNING_89,
    DOG_ICON_R_WARNING_90,
    DOG_ICON_R_WARNING_91,
    DOG_ICON_R_WARNING_92,
    DOG_ICON_R_WARNING_93,
    DOG_ICON_R_WARNING_94,
    DOG_ICON_R_WARNING_95,
    DOG_ICON_R_WARNING_96,
    DOG_ICON_R_WARNING_97,
    DOG_ICON_R_WARNING_98,
    DOG_ICON_R_WARNING_99,
    DOG_ICON_R_WARNING_101,
    DOG_ICON_R_WARNING_102,
    DOG_ICON_R_WARNING_108,
    DOG_ICON_R_WARNING_110,
    DOG_ICON_RADAR_MAXSPEED,
    DOG_ICON_RADAR_MODE,
    DOG_ICON_RADAR_MUTE,
    DOG_ICON_RADAR_SPEED,
    DOG_ICON_RADAR_VER,
    DOG_ICON_RADAR_VOLUMEA,
    DOG_ICON_R_SPEED_POINTER_0,
    DOG_ICON_R_SPEED_POINTER_1,
    DOG_ICON_R_SPEED_POINTER_2,
    DOG_ICON_R_SPEED_POINTER_3,
    DOG_ICON_R_SPEED_POINTER_4,
    DOG_ICON_R_SPEED_POINTER_5,
    DOG_ICON_R_SPEED_POINTER_6,
    DOG_ICON_R_SPEED_POINTER_7,
    DOG_ICON_R_SPEED_POINTER_8,
    DOG_ICON_R_SPEED_POINTER_9,
    DOG_ICON_R_SPEED_POINTER_10,
    DOG_ICON_R_SPEED_POINTER_11,
    DOG_ICON_R_SPEED_POINTER_12,
    DOG_ICON_R_SPEED_POINTER_13,
    DOG_ICON_R_SPEED_POINTER_14,
    DOG_ICON_R_SPEED_POINTER_15,
    DOG_ICON_R_SPEED_POINTER_16,
    DOG_ICON_R_SPEED_POINTER_17,
    DOG_ICON_R_SPEED_POINTER_18,
    DOG_ICON_R_SPEED_POINTER_19,
    DOG_ICON_R_SPEED_POINTER_20,
    DOG_ICON_R_SPEED_POINTER_21,
    DOG_ICON_R_SPEED_POINTER_22,
    DOG_ICON_R_SPEED_POINTER_23,
    DOG_ICON_R_SPEED_POINTER_24,
    DOG_ICON_R_SPEED_POINTER_25,
    DOG_ICON_R_SPEED_POINTER_26,
    DOG_ICON_R_SPEED_POINTER_27,
    DOG_ICON_R_SPEED_POINTER_28,
    DOG_ICON_R_SPEED_POINTER_29,
    DOG_ICON_R_SPEED_POINTER_30,
    DOG_ICON_R_SPEED_POINTER_31,
    DOG_ICON_R_SPEED_POINTER_32,
    DOG_ICON_R_SPEED_POINTER_33,
    DOG_ICON_R_SPEED_POINTER_34,
    DOG_ICON_R_SPEED_POINTER_35,
    DOG_ICON_R_SPEED_POINTER_36,
    DOG_ICON_R_SPEED_POINTER_37,
    DOG_ICON_R_SPEED_POINTER_38,
    DOG_ICON_R_SPEED_POINTER_39,
    DOG_ICON_NUM_MAX,
}UI_DOG_ICON_NUM;

#ifndef offsetof
#define offsetof(type, field) ((UINT32)&(((type *)0)->field))
#endif
/*----大小端转换-----------------------------------------------------------------*/
#define endianSwap16(x) (((x&0xff)<< 8)|((x&0xff00)>>8))
#define endianSwap8(x)  (((x&0xf)<< 4)|((x&0xf0)>>4))
/*---------------------起始/结束字符--------------------------------------*/
#if defined( __WIN32__)
#pragma pack(1)
#endif



#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    UINT8 startString[3]; //0x41 0x54 0x55
	UINT16 length;
	UINT8  type;
}_PACKED_END START_PACKET,*PSTART_PACKET;



#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    UINT8  CheckSum;
    UINT8  endString[2];//0x0D 0x0A(0D 0A 不算长度,不算校验码)
}_PACKED_END END_PACKET,*PEND_PACKET;

/*----启动安防开机协议（电子狗<=行车记录仪）（type:0x20）---------------------------------*/
 #if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT16 status;//0 撤销安防    1 启动安防
    END_PACKET endData;
}_PACKED_END SECURITY_BOOT,*PSECURITY_BOOT; //65 84 85 8 0 32 0 1 19

/*----GPS 信息（电子狗→行车记录仪）（type:0x10）-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8  gpsStatus;//卫星状态 ‘A’or‘V’
    UINT32 latitude;//纬度*100000
    UINT8  latitudeHalf;//‘N’or‘S’
    UINT32 longitude;//经度*100000
    UINT8  longitudeHalf;// ‘W’or‘E’
    UINT8  speed;//实时速度
    UINT16 directionAngle;//方向角度2 实际行驶方向(0--360)
    UINT8  gpsNumber;//可用卫星数1
    UINT16 height;//海拔高度
    UINT16 year;
    UINT8  month;
    UINT8  day;
    UINT8  hour;
    UINT8  minute;
    UINT8  second;
    UINT8  gsmSignal; //GSM 信号强度 计算公式:level=Signal*(5-1)/31 + 1;  If(level>4)  Level = 4;
    UINT8  Astatus;//A 状态 保留
    UINT8  warning;//报警状态 1 0 表示无报警，1 表示报警中
    END_PACKET endData;
}_PACKED_END GPS_INFO,*PGPS_INFO;

/*----固定报警信息（电子狗→行车记录仪）（type:0x11）-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8  warningType;// 请见类型说明文档
    UINT16 distance;//与电子眼间的距离
    UINT8  speed;// ?? 限速值
    UINT8  currSpeed;//当前速度
    UINT16 direction ;// 方向角度
    UINT8  gpsAvailableNumber;//  可用卫星数
    UINT8  msg[100];// 报警内容 例如：有固定测速拍照,限速80公里 or 前方300米有闯红灯
    END_PACKET endData;
}_PACKED_END FIXED_ALARM,*PFIXED_ALARM;

/*----雷达报警信息（电子狗→行车记录仪）（type:0x12）-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8 channel;//雷达频段 0:NULL,0x40:Ka,0x20:K,0x10:X,0x80:La
    UINT8  intensity;// 0,1,2,3
    UINT16 frequency;//频率(GHz)*100
    UINT8  currSpeed;//当前速度
    UINT16 currDirection; //当前方向
    UINT8  gpsAvailableNumber;//  可用卫星数
    END_PACKET endData;
}_PACKED_END RADAR_ALARM,*PRADAR_ALARM;

/*----功能菜单信息获取（电子狗<=>行车记录仪）（type:0x13）-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8  muteSetting;//静音设置 0:静音关闭,为 1 静音开启,云狗静音
    UINT8  volume; //音量设置  1,2,3,4,5,6
    UINT8  silentSpeed;//雷达静音速度  0,10,20,30,40,50,60
    UINT8  speedSetting;//超速设置  80,90,100,110,120,130(关闭)
    UINT8  modeSetting;//模式设置  0,1,2
    UINT8  speedCompensation;//速度补偿  -10~10
    UINT8  trafficStatu;//路况播报设置  此协议暂无用，不做菜单
    UINT16 version;//版本号  182
    UINT8  IMEI_ID[8];//IMEI 号
    UINT8  id[6];//本机号码
    UINT8  defaultSetting;//恢复出厂设置  0
    END_PACKET endData;
}_PACKED_END MENU_INFO,*PMENU_INFO;

/*----天气预报（电子狗=>行车记录仪）（type:0x18）-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8 type;//保留
    UINT8 msg[40];/*文字描述
    (F1 6D 33 57 02 5E 20 00 32 00 36 00 2D 00 33 00 32 00 44 64 0F 6C A6 5E 20 00
    35 96 E8 96 20 00(深圳市 26-32 摄氏度 阵雨))
    */
    END_PACKET endData;
}_PACKED_END WEATHER,*PWEATHER;

/*----投诉键协议(电子狗<=行车记录仪) ( type:0x19)-------------------------------*/
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    START_PACKET startPack;
    UINT8 satus;//// 申请投诉
    END_PACKET endData;
}_PACKED_END COMPLAIN,*PCOMPLAIN;

#if defined( __WIN32__)
#pragma pack()
#endif



//////////////////////////////////////////////////////////////
//            BMP info Struct
/////////////////////////////////////////////////////////////

#ifndef RGB888_TO_RGB565
#define RGB888_TO_RGB565(color) ((((color) >> 19) & 0x1f) << 11) \
                                            |((((color) >> 10) & 0x3f) << 5) \
                                            |(((color) >> 3) & 0x1f)    
#endif
#define   WIDTHUINT8S(bits) (((bits)+31)/32*4)

  //14byte文件头
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    UINT32 bfSize;           //文件大小
    UINT16   bfReserved1; 	//保留字，不考虑
    UINT16   bfReserved2; 	//保留字，同上
    UINT32 bfOffBits;        //实际位图数据的偏移字节数，即前三个部分长度之和
}_PACKED_END BITMAPFILEHEADER,*PBITMAPFILEHEADER;
#if defined( __WIN32__)
#pragma pack()
#endif
//__attribute__((packed))的作用是告诉编译器取消结构在编译过程中的优化对齐

//40byte信息头
#if defined( __GNUC__)
typedef   struct
#else
typedef _PACKED_BEGIN  struct
#endif
{
    UINT32   biSize;         	//指定此结构体的长度，为40
    INT32    biWidth;       		//位图宽
    INT32    biHeight;       	//位图高
    UINT16    biPlanes;       	//平面数，为1
    UINT16    biBitCount;     	//采用颜色位数，可以是1，2，4，8，16，24，新的可以是32
    UINT32   biCompression;  	//压缩方式，可以是0，1，2，其中0表示不压缩
    UINT32   biSizeImage;    	//实际位图数据占用的字节数
    INT32    biXPelsPerMeter;	//X方向分辨率
    INT32    biYPelsPerMeter;	//Y方向分辨率
    UINT32   biClrUsed;      	//使用的颜色数，如果为0，则表示默认值(2^颜色位数)
    UINT32   biClrImportant; 	//重要颜色数，如果为0，则表示所有颜色都是重要的
}_PACKED_END BITMAPINFOHEADER,*PBITMAPINFOHEADER;
#if defined( __WIN32__)
#pragma pack()
#endif
typedef struct
{
    //public:
    UINT8     rgbBlue; //该颜色的蓝色分量
    UINT8     rgbGreen; //该颜色的绿色分量
    UINT8     rgbRed; //该颜色的红色分量
    UINT8     rgbReserved; //保留值
} RGBQUAD;

typedef struct
{
    int width;
    int height;
    int dataSize;
    UINT8 *pColorData;
    RGBQUAD *dataOfBmp;
    RGBQUAD *pRgb;//Palette
}LOAD_BMPBIT_STR;

extern void *openBmpFile(char *strFile);
extern UINT32 *getBimpFileHeadInfo(void);

//////////////////////////////////////////////////////////////////////////////////
//                      STRING INFO
/////////////////////////////////////////////////////////////////////////////////
typedef struct 
{
    INT32   x;
    INT32   y;
	INT32   dev_width;
	INT32   dev_height;
	UINT16  tran_color;
	UINT16  string_color;
	UINT16  background_color;

}UNICODE_STRING_INFO;
typedef struct __MOVE_CAPTION__
{
   int move_speed;
   int move_blank;
   char *string_addr;
   void (*callbak_func)(struct __MOVE_CAPTION__ *arg);
   UNICODE_STRING_INFO str_info;
   struct __MOVE_CAPTION__ *prev;
   struct __MOVE_CAPTION__ *next;
}MOVE_CAPTION;

///////////////////////////////////////////////////////////////////////////////////
/*
   函数名： getDataStruct()
   参 数 ：string==>串口获取到的字符串（数据包）
          type====>当前数据包类型
   返回值:返回当前数据包对应的结构体
   示例：
       string: 0x41,0x54,0x55,0x08,0x00,0x20,0x00,0x01,0x13,'\n'
       type:   <== 0x20
       return: <== SECURITY_BOOT (typedef struct SECURITY_BOOT)
*/
extern void *getDataStruct(char *string,DATA_TYPES *type);
extern BOOL  putDataStruct(void *m_struct,DATA_TYPES type);
extern BOOL  isCheckCurrSumError(void);
extern char *getCurrentIMIE_ID(void);
extern char *getCurrentPhone_ID(void);
extern void gp_string_draw_unicode(UINT16*frame_buff,UINT8 *character,UNICODE_STRING_INFO *str_info);

//cloudDog_app.c API display Dog Icon 
extern  void *cloudDog_task(int signo);
extern  void move_string_task(UINT16 *frame_buff,int isMove);

extern void *CloudDog_Thread(void *arg);
extern void move_string_init(void);

#endif
