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
int check_index_univ(University_t* uns, int c, std::string name_univ) {
    int i;
    for (i = 0; i < c; i++) {
        if (name_univ == uns[i].name) {
            return i;
        }
    }
    throw 1;
}

int getting_univ(University_t* uns, int c, std::string& name) {
    int ind = -1;
    do {
        getline(std::cin, name);
        try {
            ind = check_index_univ(uns, c, name);
        }
        catch (int ex) {
            std::cout << "������ ���� ���, ���������� ��� ���\n";
        }
    } while (ind == -1);
    return ind;
}

void print_all_about_univ(University_t* uns, int c, std::string& name_univ, int ind) {
    int i, j, sum_costs = 0, sum_examRes = 0, count = 0;
    std::cout << "���������� � ���� " << name_univ << ":\n";
    std::cout << "��� " << name_univ << " ����� " << uns[ind].n_spec << " ��������������:\n";

    for (i = 0; i < uns[ind].n_spec; i++) {
        std::cout << "   " << uns[ind].specs[i].name << std::endl;
    }

    for (i = 0; i < uns[ind].n_spec; i++) {
        for (j = 0; j < uns[ind].specs[i].n_form; j++) {
            sum_costs += uns[ind].specs[i].costs[j];
            sum_examRes += uns[ind].specs[i].examScores[j];
            count++;
        }
    }

    std::cout << "������� ���� ��� ����������� �� ����: " << double(sum_examRes) / count << std::endl;
    std::cout << "������� ��������� �������� �� ���� : " << double(sum_costs) / count << "\n\n";
}

void print_minimal_spec(University_t* uns, int c, std::string name_univ, int ind) {
    int min = 1000;
    EducationalForm edForm;
    std::string name_form;
    std::string name_spec;

    for (int i = 0; i < uns[ind].n_spec; i++) {
        for (int j = 0; j < uns[ind].specs[i].n_form; j++) {
            if (uns[ind].specs[i].examScores[j] < min) {
                min = uns[ind].specs[i].examScores[j];
                edForm = uns[ind].specs[i].forms[j];
                name_spec = uns[ind].specs[i].name;
            }
        }
    }
    switch (edForm)
    {
    case 0: name_form = "�������";
    case 1: name_form = "��������";
    case 2: name_form = "�������";
    }
    std::cout << "����������� ���� ��� ����������� � ���� " << name_univ << ": " << min << std::endl;
    std::cout << "��� " << name_form << " ����� �������� �� �������������: " << name_spec << "\n";
}

void about_univercity(University_t* uns, int c) {
    std::string in;
    int univ_ind;
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ���������� ���� - ������� 1;\n������������� � ����������� ������ � ���������� ���� - ������� 2;\n";
    in = entering_mode();
    
    if (in == "1") {
        std::cout << "�� ������� '�� � ���������� ����'\n������� �������� ����:\n";
        univ_ind = getting_univ(uns, c, in);
        print_all_about_univ(uns, c, in, univ_ind);
    }
    else if (in == "2") {
        std::cout << "�� ������� '������������� � ����������� ������ � ���������� ����'\n������� �������� ����:\n";
        univ_ind = getting_univ(uns, c, in);
        print_minimal_spec(uns, c, in, univ_ind);
    }
}

 // Specialty at a university:
int check_existing_spec(University_t* uns, int c, std::string name_spec) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < uns[i].n_spec; j++) {
            if (uns[i].specs[j].name == name_spec){
                return 1;
            }
        }
    }
    return 0;
}

void getting_spec(University_t* uns, int c, std::string& name_spec) {
    getline(std::cin ,name_spec);
    while (!check_existing_spec(uns, c, name_spec)) {
        std::cout << "����� ������������� �� ������� �� � ������ ���� �� ����� ����, ���������� ��� ���\n";
        getline(std::cin, name_spec);
    }
}

void print_all_about_spec(University_t* uns, int c, std::string name_spec) {
    std::string name_form;
    EducationalForm edForm;
    std::cout << "������������� " << name_spec << " ������������ � ��������� ������� �����:\n";

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < uns[i].n_spec; j++)  {
            if (uns[i].specs[j].name == name_spec) {
                std::cout << uns[i].name << ":\n";
                std::cout << "  � ���� ���� �� ���� ������������� ������������ " << uns[i].specs[j].n_form << " ����:\n";
                for (int z = 0; z < uns[i].specs[j].n_form; z++) {
                    edForm = uns[i].specs[j].forms[z];
                    name_form = switch_form(edForm);
                    std::cout << "    " << name_form << "::��������� ����� : " << uns[i].specs[j].examScores[z];
                    std::cout << "; ��������� �������� : " << uns[i].specs[j].costs[z] << " \n";
                }
            }
        }
    }
}

void print_min_score_for_spec(University_t* uns, int c, std::string name_spec) {
    int min = 1000;
    std::string name_form, name_univ;
    EducationalForm edForm;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < uns[i].n_spec; j++) {
            if (uns[i].specs[j].name == name_spec) {
                for (int z = 0; z < uns[i].specs[j].n_form; z++) {
                    if (uns[i].specs[j].examScores[z] < min) {
                        min = uns[i].specs[j].examScores[z];
                        edForm = uns[i].specs[j].forms[z];
                        name_form = switch_form(edForm);
                        name_univ = uns[i].name;
                    }
                }

            }
        }
    }
    std::cout << "�� ��������� ������������� ����������� ��������� ���� �� ����� �� ����������: " << min << ". ���: ";
    std::cout << name_univ << ", ����� ��������: " << name_form << std::endl;
}

void about_spec(University_t* uns, int c) {
    std::string in;
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ������������� - ������� 1;\n����������� ���� �� ������������� ����� ����� - ������� 2;\n";
    in = entering_mode();

    if (in == "1") {
        printf("�� ������� '�� � �������������'\n������� �������� �������������:\n");
        getting_spec(uns, c, in);
        print_all_about_spec(uns, c, in);
    }
    else if (in == "2")
    {
        printf("�� ������� '����������� ���� �� ������������� ����� �����'\n������� �������� �������������:\n");
        getting_spec(uns, c, in);
        print_min_score_for_spec(uns, c, in);
    }
}

void working_with_user(University_t* uns, int c) {
    int end = 1;
    std::cout << "��� �� �� ������ ������?\n";
    while (end) {
        std::string in;

        std::cout << "���� ���������� ���������� � ���������� ���� - ������� 1, ���� � ���������� ������������� - 2;\n";
        std::cout << "���� �� ������ ��� ����������� ���������� � ������ ��������� ������ - ������� 0;\n\n";
        in = main_entering_mode();

        if (in == "1") {
            about_univercity(uns, c);
        }
        else if (in == "2") {
            about_spec(uns, c);

        }
        else if (in == "0") {
            std::cout << "�������, ��� ������� ���, �� ������ ������!\n";
            end = 0;
        }
        std::cout << "\n";
    }
}