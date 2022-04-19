class Library{
public:
    // 稳定 template method
    void Run() {
        Step1();

        if (Step2()) {  // 变化 =》 虚函数多态调用
            Step3();
        }

        for (int i = 0; i < 4; i++) {
            Step4();    // 变化 =》 虚函数多态调用
        }

        Step5();
    }

    virtual ~Library(){}

protected:
    void Step1() {  // 稳定
        //...
    }

    void Step3() {  // 稳定
        //...
    }

    void Step5() {  // 稳定
        //...
    }

    virtual bool Step2() = 0;   // 变化
    virtual bool Step4() = 0;   // 变化
};