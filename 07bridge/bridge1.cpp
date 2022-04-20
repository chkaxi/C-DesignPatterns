class Message
{
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriterText() = 0;
    virtual void Connect() = 0;

    virtual ~Message(){};
};

//平台实现

class PCMessageBase : public Message
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

class MobileMessagerBase : public Messager
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
class PCMessageLite : public PCMessageBase
{
public:
    virtual void Login(string username, string password)
    {
        PCMessageBase::Connect();
        //...
    }
    virtual void SendMessage(string message)
    {

        PCMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        PCMessagerBase::DrawShape();
        //........
    }
};

class PCMessagePerfect : public PCMessageBase
{
public:
    virtual void Login(string username, string password)
    {
        PCMessageBase::PlaySound();
        //***
        PCMessageBase::Connect();
        //...
    }
    virtual void SendMessage(string message)
    {

        PCMessagerBase::PlaySound();
        //********
        PCMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        PCMessagerBase::PlaySound();
        //********
        PCMessagerBase::DrawShape();
        //........
    }
};

class MobileMessagerLite : public MobileMessagerBase
{
public:
    virtual void Login(string username, string password)
    {

        MobileMessagerBase::Connect();
        //........
    }
    virtual void SendMessage(string message)
    {

        MobileMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        MobileMessagerBase::DrawShape();
        //........
    }
};

class MobileMessagerPerfect : public MobileMessagerBase
{
public:
    virtual void Login(string username, string password)
    {

        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::Connect();
        //........
    }
    virtual void SendMessage(string message)
    {

        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::DrawShape();
        //........
    }
};

void Process()
{
    // 编译时装配
    Message *m = new MobileMessagerPerfect();
}