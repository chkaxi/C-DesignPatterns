#include "template2_lib.cpp"
class Application : public Library {
public:
    virtual bool Step2(){
        //... 子类重写
    }

    virtual bool Step4(){
        //... 子类重写
    }
};

int main() {
    Library* pLib = new Application();
    pLib->Run();
    delete pLib;
}