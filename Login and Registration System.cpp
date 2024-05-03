#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class login {
private:
    string USERNAME, PASSWORD, NAME, FNAME;

public:
    login() : USERNAME(""), PASSWORD(""), NAME(""), FNAME("") {}

    void get_username(string gun) {
        USERNAME = gun;
    }

    void get_password(string pwd) {
        PASSWORD = pwd;
    }

    void get_name(string name) {
        NAME = name;
    }

    void get_fname(string fname) {
        FNAME = fname;
    }

    string getgun() {
        return USERNAME;
    }

    string getpwd() {
        return PASSWORD;
    }

    string getname() {
        return NAME;
    }

    string getfname() {
        return FNAME;
    }
};

void Login() {
    system("cls");
    string gun, pwd;
    cout << "\n\n\t\tLogin" << endl << endl;
    cout << "\n\tEnter your Username: ";
    cin >> gun;

    cout << "\n\tEnter your Password: ";
    cin >> pwd;

    ifstream infile("login.txt");
    if (!infile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string username, password, name, fname;
        char delimiter;
        ss >> name >> delimiter >> fname>> delimiter >> username >> delimiter >> password;

        if (username == gun && password == pwd) {
            found = true;
            for (int i;i=0;i++){
            	cout<<"\n\\t."<<endl;
            	
			}
            Sleep(800);
            system("cls");
            cout << "\n\tWelcome "<<name;
            break;
        }
        
    }
    if (!found) {
        cout << "\n\tError: Incorrect Username or password" << endl;
    }

    infile.close();

   Sleep(3000);
}

void Signup() {
    string name, fname, pwd, gun;
    login log;

    system("cls");
    cout << "\n\n\t\tSignup" << endl << endl;

    cout << "\n\tEnter your Name: ";
    cin >> name;
    log.get_name(name);

    cout << "\n\tEnter your Father Name: ";
    cin >> fname;
    log.get_fname(fname);
    	
    cout << "\n\tEnter your Username: ";
    cin >> gun;
    log.get_username(gun);
     
    start:

    cout << "\n\tEnter your Password: ";
    cin >> pwd;
    if (pwd.length() >= 8) {
        log.get_password(pwd);
    } else {
        cout << "\n\t8 digits password must contain" << endl;
        goto start;
    }

    ofstream outfile("login.txt", ios::app);
    if (!outfile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    outfile << log.getname() << " : " << log.getfname() << " : " << log.getgun() << " : " << log.getpwd() << " : " << endl << endl;
    cout << "\n\tLogin successfully!" << endl;

    outfile.close();

    Sleep(3000);
}

int main() {
    int choice;
    bool exit = false;

    while (!exit) {
        system("cls");
        cout << "\n\n\t\tREGISTRATION FORM" << endl;
        cout << endl;
        cout << "\n\t1. Login" << endl;
        cout << "\n\t2. Signup" << endl;
        cout << "\n\t3. Exit" << endl;
        cout << "\n\n\tEnter Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Login();
                break;

            case 2:
                Signup();
                break;

            case 3:
                exit = true;
                break;

            default:
                cout << "\n\tInvalid choice. Please try again." << endl;
                Sleep(2000);
                break;
        }
    }

    return 0;
}
