#include <iostream>
#include <fstream>
#include <sstream>
#include "outlet.h"

ostream& operator<<(ostream& os, const outlet& outlet) {//���������� ������ ��� ������� struct outlet
    const char* dayNames[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    os << "Name: " << outlet.name << endl;
    os << "Address: " << outlet.address.street << ", " << outlet.address.house_number << endl;
    os << "Phone Number: " << outlet.phone_number << endl;
    os << "Specialization: " << outlet.specialization << endl;
    os << "Working Days: " << endl;
    for (int i = 0; i < outlet.working_days.days.size(); i++) {
        os << dayNames[outlet.working_days.days[i]] << ": " << outlet.working_days.opens[i].hour << ":" <<
            outlet.working_days.opens[i].minute << " - " << outlet.working_days.closes[i].hour << ":" << outlet.working_days.closes[i].minute << endl;
    }
    os << endl;
    return os;
}

bool Time::operator==(const Time& other) const {//���������� ��������� ���������
    return hour == other.hour && minute == other.minute;
}

string start() {//����������� � ������������ ���� � ����� �� ��� ���, ���� �� ����� ����� ���� � ������������� �����
    string path;
    while (true) {
        cout << "Enter the file path..." << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        cout << "ERROR: Could not open file!\n" << endl;
    }
}

buyerGuide::buyerGuide(const vector<outlet>& o) {//����������� � ����������
    outlets = o;
}

ostream& operator<<(ostream& os, const buyerGuide& bg) {//���������� ������ ��� buyerGuide
    for (auto& o : bg.outlets) {
        cout << o;
    }
    return os;
}

buyerGuide::buyerGuide(const string& path) {
    ifstream infile(path);
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string name, street, specialization, phone_number, house_number;
        getline(iss, name, ',');//-----------------------------------|
        getline(iss, street, ',');//
        getline(iss, house_number, ',');// ������ ��������� ������
        getline(iss, phone_number, ',');//                           
        getline(iss, specialization, ',');//-------------------------|
        outlet o = { name, {street, stoi(house_number)}, stoi(phone_number), specialization, {} };//������ ������ "�������"
        string day_time;
        while (getline(iss, day_time, ',')) {//�������� � �����
            istringstream dt(day_time);
            string day, opens, closes;
            getline(dt, day, ':');
            Day currentDay;
            if (day == "Monday")
                currentDay = Monday;
            else if (day == "Tuesday")
                currentDay = Tuesday;
            else if (day == "Wednesday")
                currentDay = Wednesday;
            else if (day == "Thursday")
                currentDay = Thursday;
            else if (day == "Friday")
                currentDay = Friday;
            else if (day == "Saturday")
                currentDay = Saturday;
            else if (day == "Sunday")
                currentDay = Sunday;
            getline(dt, opens, '-');
            getline(dt, closes, '-');
            o.working_days.days.push_back(currentDay);
            o.working_days.opens.push_back({ stoi(opens.substr(0, 2)), stoi(opens.substr(3, 2)) });
            o.working_days.closes.push_back({ stoi(closes.substr(0, 2)), stoi(closes.substr(3, 2)) });
        }
        outlets.push_back(o);//���������� ����������� ������ � ������
    }
    infile.close();
}

buyerGuide::~buyerGuide() {//����������, ������ ������� ���������� ��������
    for (auto& outlet : outlets) {
        outlet.working_days.closes.clear();
        outlet.working_days.opens.clear();
        outlet.working_days.days.clear();
    }
    outlets.clear();
}

buyerGuide buyerGuide::show_24_outlets() {//���������� �������� ���������� 24/7
    vector<outlet> all_time_shops;
    cout << "24-Hour Retail Outlets:\n" << endl;
    for (const auto& outlet : outlets) {//���������� �� ���� �������� ������
        for (int i = 0; i < outlet.working_days.days.size(); i++) {
            if (outlet.working_days.opens[i] == outlet.working_days.closes[i]) {
                all_time_shops.push_back(outlet);
                break;
            }
        }
    }
    buyerGuide bg(all_time_shops);
    return bg;
}