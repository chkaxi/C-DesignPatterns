class MainForm : public MainForm
{
    SplitterFactory *factory; // 工厂
public:
    MainForm(SplitterFactory *factory)
    {
        this->factory = factory;
    }

    void Button1_Click()
    {
        ISplitter *splitter = factory->CreateSplitter(); //多态创建
        splitter->split();
    }
};