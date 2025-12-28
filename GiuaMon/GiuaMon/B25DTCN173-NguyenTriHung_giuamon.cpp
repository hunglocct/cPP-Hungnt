#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee() {
        id = 0;
        name = "";
        salary = 0;
    }

    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void input(int id) {
        this->id = id;
        cout << "Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
    }

    void printInfo() {
        cout << "ID: " << id
             << " - Ten: " << name
             << " - Luong: " << salary << endl;
    }

    int getId() { return id; }
    string getName() { return name; }
    float getSalary() { return salary; }

    void setSalary(float salary) {
        this->salary = salary;
    }
};




class EmployeeManager {
private:
    Employee list[100];
    int total;
    int nextId;

public:
    EmployeeManager() {
        total = 0;
        nextId = 3001;
        loadFromFile();
    }

    void saveToFile() {
        ofstream file("qlnv.txt");
        for (int i = 0; i < total; i++) {
            file << list[i].getId() << "|"
                 << list[i].getName() << "|"
                 << list[i].getSalary() << endl;
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file("qlnv.txt");
        if (!file.is_open()) 
		return;

        int id;
        float salary;
        string name;
        char ch;

        while (file >> id) {
            file >> ch;
            getline(file, name, '|');
            file >> salary;

            list[total++] = Employee(id, name, salary);
            if (id >= nextId) nextId = id + 1;
        }
        file.close();
    }

    void addEmployee() {
        list[total].input(nextId);
        total++;
        nextId++;
        saveToFile();
        cout << "Them nhan vien thanh cong\n";
    }

    void showAll() {
        if (total == 0) {
            cout << "Khong co nhan vien nao\n";
            return;
        }
        for (int i = 0; i < total; i++) {
            list[i].printInfo();
        }
    }

    void updateSalaryById() {
        if (total == 0) {
            cout << "Danh sach rong\n";
            return;
        }

        int id;
        float salary;
        cout << "Nhap ma nhan vien: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (list[i].getId() == id) {
                cout << "Nhap luong moi: ";
                cin >> salary;
                list[i].setSalary(salary);
                saveToFile();
                cout << "Cap nhat thanh cong\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien\n";
    }

    void deleteById() {
        if (total == 0) {
            cout << "Danh sach rong\n";
            return;
        }

        int id;
        cout << "Nhap ma nhan vien: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (list[i].getId() == id) {
                for (int j = i; j < total - 1; j++) {
                    list[j] = list[j + 1];
                }
                total--;
                saveToFile();
                cout << "Xoa thanh cong\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n----- MENU -----\n";
            cout << "1. Them nhan vien\n";
            cout << "2. Hien thi danh sach\n";
            cout << "3. Cap nhat luong\n";
            cout << "4. Xoa nhan vien\n";
            cout << "5. Thoat\n";
            cout << "Chon: ";
            cin >> choice;

            switch (choice) {
                case 1: addEmployee(); 
					break;
                case 2: showAll(); 
					break;
                case 3: updateSalaryById(); 
					break;
                case 4: deleteById(); 
					break;
                case 5: cout << "Thoat chuong trinh\n"; 
					break;
                default: cout << "Chon sai roi\n";
            }
        } while (choice != 5);
    }
};
//main
int main() {
    EmployeeManager manager;
    manager.menu();
    
    
    
    return 0;
}

