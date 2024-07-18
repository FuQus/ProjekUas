#include <iostream>
#include <fstream> //Untuk membaca dan Menulis File
#include <string>
#include <dirent.h> //Untuk Operasi Filesystem

using namespace std;

bool isLoggedIn()
{
    string username, password;
    string un, pw; //

    cout << "Masukkan Username Anda :";
    cin >> username;
    cout << "Masukkan Password Anda :";
    cin >> password;

    ifstream read(username + ".txt"); //Membaca file
    getline(read, un); //Untuk Membaca Username yang kita masukkan
    getline(read, pw); //Untuk Membaca Password yang kita masukkanngit

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void displayRegisteredAccounts()
{
    cout << "Akun yang sudah terdaftar:" << endl;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) // Membuka direktori saat ini
    {
        while ((ent = readdir(dir)) != NULL) // Membaca setiap entri di direktori
        {
            string fileName = ent->d_name;
            if (fileName.find(".txt") != string::npos) // Hanya memproses file .txt
            {
                ifstream file(fileName);
                string username;
                getline(file, username);
                cout << "- " << username << endl;
            }
        }
        closedir(dir);
    }
    else
    {
        perror("Could not open directory");
    }
}
int main()
{
    int choice;

    cout << endl;
    cout << "------------------------"<< endl;
    cout << "Main Menu" <<endl;
    cout << "------------------------"<< endl;
    cout << "1.Register :"<< endl;
    cout << "2.Login :"<< endl;
    cout << "3.Tampilkan Akun Yang Sudah Register :" << endl;
    cout << "------------------------"<< endl;
    cout << endl;
    cout << "Apa Pilihanmu ? :";
    cin >> choice;

if(choice == 1)
    {
        string username, password;

        cout << "Registrasi :" << endl;
        cout << endl;
        cout << "Ketik Username :";
        cin >> username;
        cout << "Ketik Password :";
        cin >> password;

       ofstream file; //
       file.open(username +".txt"); 
       file << username << endl << password;
       file.close();
       cout << "Selamat Datang," << username << "!" << endl;
    }
    else if(choice == 2)
    {
        bool status = isLoggedIn();

        if(!status)
        {
            system("clear");
            cout << endl;
            cout << "Gagal untuk Login" << endl;
            main();
            return 0;
        }
        else
        {
            cout << "Login Berhasil" << endl;
            cout << eendl;    

            int choiceTwo;

            // Tampilan pada Dashboard
            cout << "Selamat Datang Kembali"<< endl;
            cout << endl;
            cout << "Bagaimana Keadaanmu Hari Ini?"<< endl;
            cout << "Tidak Antaran Hari ini"<< endl;
            cout << endl;
            cout << "1.Log Out"<< endl;
            cout << "2.Kembali ke Menu Awal"<< endl;
            cout << "Apa Pilihan mu :"<< endl;
            cin >> choiceTwo;

            if(choiceTwo == 1)
            {
                system("exit");
            }
            else if(choiceTwo == 2)
            {
                main();
            }
            return 1;
            
        }
        }
    else if (choice == 3)
    {
        displayRegisteredAccounts();
        main(); // Kembali ke menu utama setelah menampilkan akun
    }
    return 0;
}
