#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

enum Specialty {
    Computer_Science_marker,
    Information_Technology,
    Philology,
    Publishing_and_printing
};

string studentStr[] = { "math", "physics", "computerScience" };

struct Student {
    string surname;
    int course;

    Specialty Student;

    int math;
    int physics;
    int computerScience;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void FindMarkers(Student* p, const int N);
void PrinnSurnames(Student* p, const int N);


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� �������� (N): ";
    cin >> N;
    cout << setw(5) << endl;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);
    FindMarkers(p, N);
    PrinnSurnames(p, N);


    delete[] p;

    return 0;
}

void Create(Student* p, const int N) {
    cin.get();
    cin.sync();

    cout << "���� ��������������" << endl;
    cout << "Computer_Science - 0" << endl;
    cout << "Information_Technology - 1" << endl;
    cout << "Philology - 2" << endl;
    cout << "Publishing_and_printing - 3" << endl;
    cout << setw(5) << endl;

    for (int i = 0; i < N; i++) {
        cout << "������� ����� " << i + 1 << ":" << endl;

        cout << setw(1) << "�������: ";
        getline(cin, p[i].surname);

        cout << "����: ";
        cin >> p[i].course;

        if (p[i].course > 6 || p[i].course < 1) {
            cout << "������������ ��� �����" << endl;
            return;
        }

        cout << setw(1) << "������������: ";
        int specialtyChoice;
        cin >> specialtyChoice;

        p[i].Student = static_cast<Specialty>(specialtyChoice);

        if (0 > p[i].Student && p[i].Student > 3)
        {
            cout << "������������ ��� ������������";
        }

        cout << "������ � ����������: ";
        int math;
        cin >> math;
        p[i].math = math;

        if (math < 0 && 5 < math)
        {
            cout << "������������ ��� ������" << endl;
        }

        cout << "������ � ������: ";
        int physics;
        cin >> physics;
        p[i].physics = physics;

        if (physics < 0 && 5 < physics)
        {
            cout << "������������ ��� ������" << endl;
        }

        cout << "������ � ��: ";
        int computerScience;
        cin >> computerScience;
        p[i].computerScience = computerScience;

        if (computerScience < 0 && 5 < computerScience)
        {
            cout << "������������ ��� ������" << endl;
        }

        cin.ignore();
        cout << setw(5) << endl;
    }
}

void Print(Student* p, const int N) {
    cout << "====================================================================================="
        << endl;
    cout << "| � |    �������   | ���� | ������������           | ���������� | Գ���� | �� |"
        << endl;
    cout << "-------------------------------------------------------------------------------------"
        << endl;

    string specialtyNames[] = {
        "Computer_Science",
        "Information_Technology",
        "Philology",
        "Publishing_and_printing"
    };

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].surname
            << "| " << setw(4) << right << p[i].course << " "
            << "| " << setw(23) << left << specialtyNames[p[i].Student];
        cout << "| " << setw(12) << right << p[i].math
            << "| " << setw(7) << right << p[i].physics
            << "| " << setw(2) << right << p[i].computerScience;
        cout << " |" << endl;
    }
    cout << "====================================================================================="
        << endl;
    cout << endl;
}

void FindMarkers(Student* p, const int N)
{
    int CountFives = 0;
    int CountFours = 0;
    int CountThree = 0;

    for (int i = 0; i < N; i++) {
        if (p[i].math == 5) {
            CountFives++;
        }

        if (p[i].math == 4) {
            CountFours++;
        }

        if (p[i].math == 3) {
            CountThree++;
        }
    }

    cout << "ʳ������ �'�����: " << CountFives << endl;
    cout << "ʳ������ �������: " << CountFours << endl;
    cout << "ʳ������ �����: " << CountThree << endl;
    cout << setw(10) << endl;
}


void PrinnSurnames(Student* p, const int N)
{
    cout << "��������, �� �������� ������ 5 � ������ � ����������:" << endl;
    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 5 && p[i].math == 5)
        {
            cout << p[i].surname << endl;
        }
    }
}