#ifndef KEYMLCONTROL_CUSTOMCOM_H
#define KEYMLCONTROL_CUSTOMCOM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>


/********************************************��������*********************************************/
/** ֡ͷ--------------------�Զ���������� *********************************************************/
#define HEAD_DATA           {0xCC, 0xDD}
/** ���ݳ����ֽ���------------�Զ��������ֽ��� *******************************************************/
#define DATA_LEN            2
/** ���������ֽ���------------�Զ��������ֽ��� *******************************************************/
#define TYPE_LEN            1
/** ���������ռ�------------������Ҫ���� **********************************************************/
#define MAX_DATA_SIZE       256
/** У���ֽ���---------------�Զ����������� *********************************************************/
#define CHECK_LEN           1
/** ֡β--------------------�Զ���������� *********************************************************/
#define TAIL_DATA           {0xEE, 0xEF}
/** ��֡��󳤶�--------------������Ҫ���� **********************************************************/
#define MAX_FRAME_SIZE      256
/****************************************** �������� *********************************************/

/*************************************���ݳ����Ƿ����֡β******************************************/
#define IS_DATA_LEN_INCLUDE_TAIL     (1)
/*************************************���ݳ����Ƿ����У��******************************************/
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


// ָ�������״̬
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
