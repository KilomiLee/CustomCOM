<span style="font-size:36px;">**MCU的自定义帧解析器**</span>  
  
  
<span style="font-size:24px;">
  1. 修改宏定义即可简单部署 <br>
  2. 协议组成部分的字段长度可以任意添加或删减
</span>  
<br>
<br>
<br>

# 配置使用教程
<span style="font-size:16px;">
1. 将Custom.h和Custom.c复制到项目内<br>
  <br>
2. 在Custom.h中根据自己需要配置以下内容<br>
</span>



```C
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
```

<span style="font-size:16px;">
3. 在项目包含的任意地方实现以下功能执行函数<br>
 ---cmd-返回的命令字地址,cmdLen-命令字长度,data-数据地址,dataLen-数据长度<br>
</span>

```C
__attribute__((weak)) void
customReceiveComplete(const uint8_t *cmd, uint8_t cmdLen, const uint8_t *data, uint16_t dataLen) {
	switch (cmd[0]){
    case 0x01:
    break;
    case 0x02:
    break;
    default:
    break;
    }
}
```

<span style="font-size:16px;">
4. 使用解析器<br>
  在数据接收完一帧数据后调用以下函数即可<br>
  parserHandle-解析器句柄, frameData-数据帧地址,frameLen-数据帧长度
</span>

```C
uint8_t parseFrame(ParserHandle *parserHandle, const uint8_t *frameData, const size_t frameLen)
```
<br>
<span style="font-size:20px;">注:</span>  
<span style="font-size:16px;">
目前校验没有示例,所以校验位不做判断,随便填什么都可以,有机会我会添加个默认的校验方式,后续也会在添加几个在keil或者Clion或者VScode的测试工程
</span>

