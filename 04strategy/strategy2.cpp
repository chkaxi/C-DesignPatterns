class Context;
class StrategyFactory;

class TaxStrategy
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStrategy() {}
};

class CNTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &constext)
    {
        //...
    }
};

class USTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &constext)
    {
        //...
    }
};

// 扩展
class FRTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &constext)
    {
        //...
    }
};

class SalesOrder
{
private:
    TaxStrategy *strategy;

public:
    SalesOrder(StrategyFactory *strategyFactory)
    {
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder()
    {
        delete this->strategy;
    }

public:
    double CalculateTax()
    {
        //...
        Context context();
        double val = strategy->Calculate(context);
        //...
    }
};