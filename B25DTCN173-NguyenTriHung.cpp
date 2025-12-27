#include <iostream>
#include <string>

using namespace std;


class Classroom {
private:
    string classId;
    string className;
    string major;
    string classType;

public:
    string getClassId() {
        return classId;
    }

    void input() {
        cout << "Nhap ma lop: ";
        cin >> classId;
        cin.ignore();

        cout << "Nhap ten lop (khong dau): ";
        getline(cin, className);

        cout << "Nhap chuyen nganh (khong dau): ";
        getline(cin, major);

        cout << "Nhap loai lop (CNTT/Ngoai ngu): ";
        getline(cin, classType);
    }

    void display() {
        cout << classId << " | "
             << className << " | "
             << major << " | "
             << classType << endl;
    }

    void update() {
        cin.ignore();
        cout << "Nhap ten lop moi: ";
        getline(cin, className);

        cout << "Nhap chuyen nganh moi: ";
        getline(cin, major);

        cout << "Nhap loai lop moi: ";
        getline(cin, classType);
    }
};


class Student {
private:
    string studentId;
    string fullName;
    string dateOfBirth;
    string email;
    string phoneNumber;

public:
    string getStudentId() {
        return studentId;
    }

    void input() {
        cout << "Nhap ma sinh vien: ";
        cin >> studentId;
        cin.ignore();

        cout << "Nhap ho ten (khong dau): ";
        getline(cin, fullName);

        cout << "Nhap ngay sinh: ";
        getline(cin, dateOfBirth);

        cout << "Nhap email: ";
        getline(cin, email);

        cout << "Nhap so dien thoai: ";
        getline(cin, phoneNumber);
    }

    void display() {
        cout << studentId << " | "
             << fullName << " | "
             << dateOfBirth << " | "
             << email << " | "
             << phoneNumber << endl;
    }

    void update() {
        cin.ignore();
        cout << "Nhap ho ten moi: ";
        getline(cin, fullName);

        cout << "Nhap ngay sinh moi: ";
        getline(cin, dateOfBirth);

        cout << "Nhap email moi: ";
        getline(cin, email);

        cout << "Nhap so dien thoai moi: ";
        getline(cin, phoneNumber);
    }
};


class Manager {
public:
    virtual void add() = 0;
    virtual void display() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
};


class ClassroomManager : public Manager {
private:
    Classroom classroomList[50];
    int totalClassroom = 0;

public:
    void add() {
        classroomList[totalClassroom].input();
        totalClassroom++;
    }

    void display() {
        if (totalClassroom == 0) {
            cout << "Khong co lop hoc nao\n";
            return;
        }

        for (int i = 0; i < totalClassroom; i++) {
            classroomList[i].display();
        }
    }

    void remove() {
        if (totalClassroom == 0) {
            cout << "Khong co lop hoc de xoa\n";
            return;
        }

        string id;
        cout << "Nhap ma lop can xoa: ";
        cin >> id;

        for (int i = 0; i < totalClassroom; i++) {
            if (classroomList[i].getClassId() == id) {
                for (int j = i; j < totalClassroom - 1; j++) {
                    classroomList[j] = classroomList[j + 1];
                }
                totalClassroom--;
                cout << "Da xoa lop hoc\n";
                return;
            }
        }
        cout << "Khong tim thay lop\n";
    }

    void update() {
        if (totalClassroom == 0) {
            cout << "Khong co lop hoc de cap nhat\n";
            return;
        }

        string id;
        cout << "Nhap ma lop can cap nhat: ";
        cin >> id;

        for (int i = 0; i < totalClassroom; i++) {
            if (classroomList[i].getClassId() == id) {
                classroomList[i].update();
                return;
            }
        }
        cout << "Khong tim thay lop\n";
    }
};


class StudentManager : public Manager {
private:
    Student studentList[100];
    int totalStudent = 0;

public:
    void add() {
        studentList[totalStudent].input();
        totalStudent++;
    }

    void display() {
        if (totalStudent == 0) {
            cout << "Khong co sinh vien nao\n";
            return;
        }

        for (int i = 0; i < totalStudent; i++) {
            studentList[i].display();
        }
    }

    void remove() {
        if (totalStudent == 0) {
            cout << "Khong co sinh vien de xoa\n";
            return;
        }

        string id;
        cout << "Nhap ma sinh vien can xoa: ";
        cin >> id;

        for (int i = 0; i < totalStudent; i++) {
            if (studentList[i].getStudentId() == id) {
                for (int j = i; j < totalStudent - 1; j++) {
                    studentList[j] = studentList[j + 1];
                }
                totalStudent--;
                cout << "Da xoa sinh vien\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien\n";
    }

    void update() {
        if (totalStudent == 0) {
            cout << "Khong co sinh vien de cap nhat\n";
            return;
        }

        string id;
        cout << "Nhap ma sinh vien can cap nhat: ";
        cin >> id;

        for (int i = 0; i < totalStudent; i++) {
            if (studentList[i].getStudentId() == id) {
                studentList[i].update();
                return;
            }
        }
        cout << "Khong tim thay sinh vien\n";
    }
};


void subMenu(Manager* manager) {
    int choice;
    do {
        cout << "\n1. Hien thi";
        cout << "\n2. Them";
        cout << "\n3. Xoa";
        cout << "\n4. Cap nhat";
        cout << "\n0. Quay lai";
        cout << "\nChon: ";
        cin >> choice;

        if (choice == 1) manager->display();
        else if (choice == 2) manager->add();
        else if (choice == 3) manager->remove();
        else if (choice == 4) manager->update();
		else cout << "\nChon lai sai roi!!!!!\n";

    } while (choice != 0);
}



//main
int main() {
    ClassroomManager classroomManager;
    StudentManager studentManager;
    int choice;

    do {
        cout << "\nHE THONG RIKKEI EDU";
        cout << "\n1. Quan ly lop hoc";
        cout << "\n2. Quan ly sinh vien";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        cin >> choice;

        if (choice == 1) subMenu(&classroomManager);
        else if (choice == 2) subMenu(&studentManager);
		else cout << "\nChon lai sai roi!!!!!\n";
		
		
    } while (choice != 0);






    return 0;
}

