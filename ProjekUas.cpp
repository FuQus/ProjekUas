#include <iostream>
#include <fstream> //Untuk membaca dan Menulis File
#include <string>
#include <dirent.h> //Untuk Operasi Filesyste

using namespace std;

bool isloggedin()
{
    string username, pasword;
    sring un, pw; //

    cout << "Masukkan Username Anda :";
    cint >> username;
    cout << "Masukkan Password Anda :";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}