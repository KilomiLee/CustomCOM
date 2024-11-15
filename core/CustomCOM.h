#ifndef KEYMLCONTROL_CUSTOMCOM_H
#define KEYMLCONTROL_CUSTOMCOM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>


/********************************************配置区域*********************************************/
/** 帧头--------------------自定义任意添加 *********************************************************/
#define HEAD_DATA           {0xCC, 0xDD}
/** 数据长度字节数------------自定义任意字节数 *******************************************************/
#define DATA_LEN            2
/** 命令类型字节数------------自定义任意字节数 *******************************************************/
#define TYPE_LEN            1
/** 数据区最大空间------------根据需要定义 **********************************************************/
#define MAX_DATA_SIZE       256
/** 校验字节数---------------自定义任意数量 *********************************************************/
#define CHECK_LEN           1
/** 帧尾--------------------自定义任意添加 *********************************************************/
#define TAIL_DATA           {0xEE, 0xEF}
/** 单帧最大长度--------------根据需要定义 **********************************************************/
#define MAX_FRAME_SIZE      256
/****************************************** 配置区域 *********************************************/

/*************************************数据长度是否包含帧尾******************************************/
#define IS_DATA_LEN_INCLUDE_TAIL     (1)
/*************************************数据长度是否包含校验******************************************/
#define IS_DATA_LEN_INCLUDE_CHECK    (1)

typedef enum {
    first = 0xA1,
    second = 0x84,
} enumType;

static const uint8_t FN_HeadData[] = HEAD_DATA;
static const uint8_t FN_TailData[] = TAIL_DATA;
#define HEAD_LEN    (sizeof(FN_HeadData) / sizeof(FN_HeadData[0]))
#define TAIL_LEN    (sizeof(FN_TailData) / sizeof(FN_TailData[0]))


typedef struct {
    uint8_t headData[HEAD_LEN];
    uint8_t lenData[DATA_LEN];
    uint8_t typData[TYPE_LEN];
    uint8_t Data[MAX_DATA_SIZE];
    uint8_t Check[CHECK_LEN];
    uint8_t tailData[TAIL_LEN];
} FrameFormat;
static const FrameFormat F_Frame = {HEAD_DATA, {0}, {0}, {0}, {0}, TAIL_DATA};


// 指令解析器状态
typedef struct {
    size_t size;
    FrameFormat frame;
} ParserHandle;

void customReceiveComplete(const uint8_t *cmd,uint8_t cmdLen, const uint8_t *data, uint16_t dataLen);

void initParser(ParserHandle *parserHandle);

uint8_t parseFrame(ParserHandle *parserHandle, const uint8_t *frameData, size_t frameLen);


#ifdef __cplusplus
}
#endif

#endif //KEYMLCONTROL_CUSTOMCOM_H
