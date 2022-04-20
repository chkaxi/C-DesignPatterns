//业务操作
class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

//主体类
class FileStream : public Stream
{
public:
    virtual char Read(int number)
    {
        //读文件流
    }
    virtual void Seek(int position)
    {
        //定位文件流
    }
    virtual void Write(char data)
    {
        //写文件流
    }
};

class NetworkStream : public Stream
{
public:
    virtual char Read(int number)
    {
        //读网络流
    }
    virtual void Seek(int position)
    {
        //定位网络流
    }
    virtual void Write(char data)
    {
        //写网络流
    }
};

//扩展操作
class CryptoStream : public Stream
{
    Stream *Stream; //...有继承又有组合

public:
    CryptoStream(Stream *stm) : stream(stm)
    {
    }

    virtual char Read(int number)
    {
        //额外的加密操作
        stream->Read(number); //读文件流
    }
    virtual void Seek(int position)
    {
        //额外的加密操作...
        stream->Seek(position); //定位文件流
        //额外的加密操作...
    }
    virtual void Write(byte data)
    {
        //额外的加密操作...
        stream->Write(data); //写文件流
        //额外的加密操作...
    }
};

class BufferedStream : public Stream
{

    Stream *stream; //...

public:
    BufferedStream(Stream *stm) : stream(stm)
    {
    }
    //...
};

void Process()
{
    //运行时装配
    FileStream *s1 = new FileStream();
    CryptoStream *s2 = new CryptoStream(s1);

    BufferedStream *s3 = new BufferedStream(s1);

    BufferedStream *s4 = new BufferedStream(s2);
}