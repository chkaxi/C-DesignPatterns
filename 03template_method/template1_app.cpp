#include "template1_lib.cpp"

class Application
{
public:
    bool Step2()
    {
        //...
    }

    bool Step4()
    {
        //...
    }
};

int main()
{
    Library lib();
    Application app();

    lib.Step1();

    if (app.Step2())
    {
        lib.Step3();
    }

    for (int i = 0; i < 4; i++)
    {
        app.Step4();
    }

    lib.Step5();
}