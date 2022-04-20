class Message
{
protected:
    MessageImp *messageImp; //...
public:
    Message(MessageImp *mImp) : messageImp(mImp)
    {
    }
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriterText() = 0;
    virtual void Connect() = 0;

    virtual ~Message(){};
};

class MessageImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriterText() = 0;
    virtual void Connect() = 0;

    virtual ~MessageImp(){};
};

//平台实现

class PCMessageImp : public MessageImp
{
public:
    virtual void PlaySound()
    {
        //***
    }
    virtual void DrawShape()
    {
        //***
    }
    virtual void WriteText()
    {
        //**********
    }
    virtual void Connect()
    {
        //**********
    }
};

class MobileMessagerBImp : public MessageImp
{
public:
    virtual void PlaySound()
    {
        //==========
    }
    virtual void DrawShape()
    {
        //==========
    }
    virtual void WriteText()
    {
        //==========
    }
    virtual void Connect()
    {
        //==========
    }
};

//业务抽象
class MessageLite : public Message
{
public:
    MessageLite(MessageImp *mImp) : Message(mImp)
    {
    }
    virtual void Login(string username, string password)
    {
        messageImp->Connect();
        //...
    }
    virtual void SendMessage(string message)
    {

        messageImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        messageImp->DrawShape();
        //........
    }
};

class MessagePerfect : public Message
{
public:
    MessagePerfect(MessageImp *mImp) : Message(mImp)
    {
    }
    virtual void Login(string username, string password)
    {
        messageImp->PlaySound();
        //***
        messageImp->Connect();
        //...
    }
    virtual void SendMessage(string message)
    {

        messageImp->PlaySound();
        //********
        messageImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        messageImp->PlaySound();
        //********
        messageImp->DrawShape();
        //........
    }
};

void Process()
{
    // 运行时装配
    MessageImp *mImp = new PCMessageImp();
    Message *m = new MessageLite(mImp);
}