#pragma push(struct, 1)

typedef struct tagString
{
    unsigned int unLength;
    WCHAR szString[0];
} String;

typedef enum tagMessageType
{
    EMSG_Login,                 //��¼����
    EMSG_Logout,                //ע������
    EMSG_HeartBeat,             //��������
    EMSG_SendMessage,           //������Ϣ����
    EMSG_RequestOnline,         //���������û�����
    EMSG_ResponseOnline,        //��Ӧ������������
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

//�����¼Э�飬��¼��ʱ����Ҫ��������Ĺ㲥��Ϣ
typedef struct tagLoginBody
{
    UserInfo user;
} LoginBody;

typedef struct tagRequestOnlineBody
{
    UserInfo sender;
} RequestOnlineBody;

//����ظ��ĵ㵽����Ϣ
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