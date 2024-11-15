#include "CustomCOM.h"

ParserHandle COM1_FrameParserState;//串口1帧解析器结构

/**
 * 帧解析器
 * @param parserHandle  解析器句柄
 * @param frameData
 * @param frameLen
 * @return
 */
uint8_t parseFrame(ParserHandle *parserHandle, const uint8_t *frameData, const size_t frameLen) {
    for (int i = 0; i < HEAD_LEN; ++i) {
        if (frameData[i] != parserHandle->frame.headData[i]) {
            return 0;
        }
    }
    for (int i = 0; i < TAIL_LEN; ++i) {
        if (frameData[frameLen - TAIL_LEN + i] != parserHandle->frame.tailData[i]) {
            return 0;
        }
    }
    //todo:校验
    uint8_t dataSize = frameLen - TAIL_LEN - CHECK_LEN - HEAD_LEN - DATA_LEN - TYPE_LEN;
    uint8_t dataStart = TAIL_LEN + HEAD_LEN + TYPE_LEN;
    uint8_t typeStart = HEAD_LEN + DATA_LEN;

    customReceiveComplete(&frameData[typeStart], TYPE_LEN, &frameData[dataStart], dataSize);

    return 1;
}


__attribute__((weak)) void
customReceiveComplete(const uint8_t *cmd, uint8_t cmdLen, const uint8_t *data, uint16_t dataLen) {

}


// 初始化解析器状态
void initParser(ParserHandle *parserHandle) {
    parserHandle->size = 0;
    parserHandle->frame = F_Frame;
}

