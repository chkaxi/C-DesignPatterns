// 具体观察者
class MainForm : public Form, public IProgress
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;

    ProgressBar *progressBar;

public:
    void Button1_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        ConsoleNotifier cn;

        FileSplitter splitter(filePath, number);

        splitter.addIprogress(this); //订阅通知
        splitter.addIprogress(&cn);  //订阅通知

        splitter.split();

        splitter.removeIprogress(this);
    }

    virtual void DoProgress(float value)
    {
        progressBar->setValue(value);
    }
};

// 具体观察者
class ConsoleNotifier : public Iprogress
{
public:
    virtual void DoProgress(float value)
    {
        cout << ".";
    }
};