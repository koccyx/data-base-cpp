#include "functions.h"

int main(){
    system("chcp 1251");
    system("cls");
    while (menue_numb != 0){
        char tr[100];
        cout << "[1] ����� ������\n";
        cout << "[2] ���� ������\n";
        cout << "[3] ����� ��������, ������� 2 �� 1 � ����� ���������\n";
        cout << "[4] ��������� ������ ��������\n";
        cout << "[5] �������� ������ ��������\n";
        cout << "[6] ����������\n";
        cout << "[7] ����������� ������ �� �����\n";
        cout << "[8] �������� ������ � ����\n";
        cout << "[9] ����������� ������ �� ��������� �����\n";
        cout << "[10] �������� ������ � �������� ����\n";
        cout << "[11] ������� ������ �� ���������� ����� � ��������\n";
        cout << "[0] ����� �� ���������\n";
        cin >> tr;
        menue_numb = numcheck_menue(tr);
        switch(menue_numb){
            case 1:
                vivod(people);
                system("cls");
                break;
            case 2:
                vvod(people);
                system("cls");
                break;
            case 3:
                spec(people);
                system("cls");
                break;
            case 4:
                change(people);
                system("cls");
                break;
            case 5:
                dels(people);
                system("cls");
                break;
            case 6:
                sort(people);
                system("cls");
                break;
            case 7:
                base_download(people);
                system("cls");
                len -= 1;
                break;
            case 8:
                base_upload(people, 0);
                system("cls");
                break;
            case 9:
                binary_download(people);
                system("cls");
                len -= 2;
                break; 
            case 10:
                binary_upload(people, 0);
                system("cls");
                break;
            case 11:
                binary_to_txt(people);
                system("cls");
                break;  
            case 0:
                system("cls");
                break;
            default:
                system("cls");
                break;
        }
    }
    safe_prgrs(people);
    system("cls");
    cout << "������ ��������� ��������, �� �����\n";
}
