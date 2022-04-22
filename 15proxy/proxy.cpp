class ISubject
{
public:
    virtual void process();
};

// Proxy的设计 大部分用工具生成
class SubjectProxy : public ISubject
{
public:
    virtual void process()
    {
        //对RealSubject的一种间接访问
        //...
    }
};

class ClientApp
{
    ISubject *subject;

public:
    ClientApp()
    {
        subject = new SubjectProxy();
    }

    void DoTask()
    {
        //...
        subject->process();
        //...
    }
};