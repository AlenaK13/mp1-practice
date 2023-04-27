#include "userSide.h"
#include "fileProcessing.h"

std::string switch_form(EducationalForm form) {
    std::string name_form;
    switch (form) {
    case DNEV:
        name_form = "�������";
        break;
    case VECHER:
        name_form = "��������";
        break;
    case ZAOCH:
        name_form = "�������";
        break;
    }
    return name_form;
}

std::string main_entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2") && (in != "0")) {
        std::cout << "�� ���������� ����, ���������� ��� ���, �������� �����������!\n";
        getline(std::cin, in);
    }
    return in;
}

std::string entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2")) {
        std::cout << "�� ���������� ����, ���������� ��� ���, �������� �����������!\n";
        getline(std::cin, in);
    }
    return in;
}

// University info:

void about_univercity(Univ_database_t& unsdata) {
    std::string in;
    University_t curr_univ;
    int univ_ind;
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ���������� ���� - ������� 1;\n������������� � ����������� ������ � ���������� ���� - ������� 2;\n";
    in = entering_mode();

    if (in == "1") {
        int cost, score, code;
        std::string name;
        std::cout << "�� ������� '�� � ���������� ����'\n������� �������� ����:\n";
        
        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "���� � ����� ��������� ��� � ����, ���������� ��� ���\n";
        } while (code == -1);
        cost = curr_univ.ComputeAverageCost();
        score = curr_univ.ComputeAverageScore();

        std::cout << curr_univ;
        std::cout << "������� ���� ��� ����������� �� ����: " << score << "\n";
        std::cout << "������� ��������� �������� �� ���� : " << cost << "\n\n";
    }
    else if (in == "2") {
        std::string name;
        Spec_t s;
        int code;
        std::cout << "�� ������� '������������� � ����������� ������ � ���������� ����'\n������� �������� ����:\n";
        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "���� � ����� ��������� ��� � ����, ���������� ��� ���\n";
        } while (code == -1);

        int min_score;
        std::string name_form, spec_name;
        curr_univ.SearchMinScoreSpeciality(spec_name, min_score, name_form);
        std::cout << "����������� ���� ��� ����������� � ���� " << curr_univ.name << ": " << min_score << "\n";
        std::cout << "��� �������������:  " << spec_name << ", ����� ��������: " << name_form << std::endl;
    }
}

// Specialty at a university:
int check_existing_spec(Univ_database_t& unsdata, std::string name_spec) {
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                return 1;
            }
        }
    }
    return 0;
}

void getting_spec(Univ_database_t& unsdata, std::string& name_spec) {
    getline(std::cin, name_spec);
    while (!check_existing_spec(unsdata, name_spec)) {
        std::cout << "����� ������������� �� ������� �� � ������ ���� �� ����� ����, ���������� ��� ���\n";
        getline(std::cin, name_spec);
    }
}

void print_all_about_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    std::string name_form;
    EducationalForm edForm;
    std::cout << "������������� " << spec_arr[0].name << " ������������ � ��������� ������� �����:\n";

    for (int i = 0; i < c; i++) {
        std::cout << names_univs[i] << ":\n";
        std::cout << "  � ���� ���� �� ���� ������������� ������������ " << spec_arr[i].n_form << " ����:\n";
        for (int z = 0; z < spec_arr[i].n_form; z++) {
            edForm = spec_arr[i].forms[z];
            name_form = switch_form(edForm);
            std::cout << "    " << name_form << "::��������� ����� : " << spec_arr[i].examScores[z];
            std::cout << "; ��������� �������� : " << spec_arr[i].costs[z] << " \n";
        }
    }
}

void print_min_score_for_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    int min = 1000;
    std::string name_form, name_univ;
    EducationalForm edForm;

    for (int i = 0; i < c; i++) {
        for (int z = 0; z < spec_arr[i].n_form; z++) {
            if (spec_arr[i].examScores[z] < min) {
                min = spec_arr[i].examScores[z];
                edForm = spec_arr[i].forms[z];
                name_form = switch_form(edForm);
                name_univ = names_univs[i];
            }
        }
    }

    std::cout << "�� ��������� ������������� ����������� ��������� ���� �� ����� �� ����������: " << min << ". ���: ";
    std::cout << name_univ << ", ����� ��������: " << name_form << std::endl;
}

int get_specs(Univ_database_t& unsdata, std::string name_spec, Spec_t** specs, std::string** names_univs) {
    int count = 0;
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                count++;
            }
        }
    }
    *specs = new Spec_t[count];
    *names_univs = new std::string[count];
    int ind = 0;
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                *specs[ind] = unsdata[i].specs[j];
                *names_univs[ind] = unsdata[i].name;
                ind++;
            }
        }
    }
    return count;
}

void about_spec(Univ_database_t& unsdata) {
    std::string in;
    int count_such_specs;
    Spec_t* specs;
    std::string* names_univ;
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ������������� - ������� 1;\n����������� ���� �� ������������� ����� ����� - ������� 2;\n";
    in = entering_mode();

    /*if (in == "1") {
        printf("�� ������� '�� � �������������'\n������� �������� �������������:\n");
        getting_spec(unsdata, c, in);
        int count_such_specs = get_specs(unsdata, c, in, &specs, &names_univ);
        print_all_about_spec(specs, count_such_specs, names_univ);
    }
    else if (in == "2")
    {
        printf("�� ������� '����������� ���� �� ������������� ����� �����'\n������� �������� �������������:\n");
        getting_spec(unsdata, c, in);
        int count_such_specs = get_specs(unsdata, c, in, &specs, &names_univ);
        print_min_score_for_spec(specs, count_such_specs, names_univ);
    }*/
}

void working_with_user(Univ_database_t& unsdata) {
    int end = 1;
    std::cout << "��� �� �� ������ ������?\n";
    while (end) {
        std::string in;

        std::cout << "���� ���������� ���������� � ���������� ���� - ������� 1, ���� � ���������� ������������� - 2;\n";
        std::cout << "���� �� ������ ��� ����������� ���������� � ������ ��������� ������ - ������� 0;\n\n";
        in = main_entering_mode();

        if (in == "1") {
            about_univercity(unsdata);
        }
        else if (in == "2") {
            about_spec(unsdata);

        }
        else if (in == "0") {
            std::cout << "�������, ��� ������� ���, �� ������ ������!\n";
            end = 0;
        }
        std::cout << "\n";
    }
}