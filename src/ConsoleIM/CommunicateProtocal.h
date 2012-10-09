#pragma push(struct, 1)

typedef struct tagString
{
    unsigned int unLength;
    WCHAR szString[0];
} String;

typedef enum tagMessageType
{
    EMSG_Login,                 //登录命令
    EMSG_Logout,                //注销命令
    EMSG_HeartBeat,             //心跳命令
    EMSG_SendMessage,           //发送消息命令
    EMSG_RequestOnline,         //请求在线用户命令
    EMSG_ResponseOnline,        //回应请求在线命令
} MessageType;

typedef struct tagUserInfo
{
    ULONG ulIpv4;
    String strNickName;
} UserInfo;
typedef struct tagMessageHeader
{
    unsigned short nVersion;
    MessageType eMessageType;
    unsigned int nBodyLength;
} MessageHeader;

//定义登录协议，登录的时候需要发送请求的广播消息
typedef struct tagLoginBody
{
    UserInfo user;
} LoginBody;

typedef struct tagRequestOnlineBody
{
    UserInfo sender;
} RequestOnlineBody;

//定义回复的点到点消息
typedef struct tagResponseOnlineBody
{
    UserInfo user;
} ResponseOnlineBody;

typedef struct tagHeartBeatBody
{
    UserInfo user;
} HeartBeatBody;

typedef struct tagSendMessageBody
{
    UserInfo sender;
    String strMsg;
} SendMessageBody;

#pragma pop(struct)