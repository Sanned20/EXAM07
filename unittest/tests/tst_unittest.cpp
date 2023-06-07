#include <QtTest>

// add necessary includes here

class unittest : public QObject
{
    Q_OBJECT

public:
    unittest();
    ~unittest();

private slots:
    void test_case1();

};

unittest::unittest()
{

}

unittest::~unittest()
{

}

void unittest::test_case1()
{

}



QTEST_APPLESS_MAIN(unittest)

#include "tst_unittest.moc"
