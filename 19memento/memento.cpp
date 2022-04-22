class Memento
{
    string state;

public:
    Memento(const string &s) : state(s) {}
    string getState() const { return state; }
    void setState(const string &s) { state = s; }
};

class Originator
{
    string state;
    //...
public:
    Originator() {}
    Memento createMemento()
    {
        Memento m(state);
        return m;
    }
    void setMemento(const Memento &m)
    {
        state = m.getState();
    }
};

int main()
{
    Originator originator;

    // 捕获对象状态，存储到备忘录
    Memento mem = originator.createMemento();

    // ...改变originator状态

    // 从备忘录中恢复
    originator.setMemento(mem);
}