#ifndef _OUTLET_H
#define _OUTLET_H
#include  <string>
#include <vector>
using namespace std;

enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Time {
    int hour;
    int minute;
    bool operator==(const Time& other) const;
};

struct address {
    string street;
    int house_number;
};

// ��������� ��� �������� ������� ���� ��������
struct workingDays {
    vector<Day> days;
    vector<Time> opens;
    vector<Time> closes;
};

class outlet {//�����, ������� ������ �������� � �������� �����
public:
    outlet(string name, address address, int number, string specialization, workingDays wd);
    ~outlet();
    workingDays* getWD();
private:
    string name;
    address address_;
    int phone_number;
    string specialization;
    workingDays working_days;
    friend ostream& operator<<(ostream& os, const outlet& outlet);
};

class buyerGuide {//�����, ������� ������ ��� ���� �������� �����
public:
    buyerGuide(const string& filename);
    buyerGuide(const vector<outlet>& o);
    ~buyerGuide();
    buyerGuide show_24_outlets();
    friend ostream& operator<<(ostream& os, const buyerGuide& bg);
private:
    vector<outlet> outlets;
};

string start();
#endif // !_OUTLET_H