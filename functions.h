#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstring>
#include <iomanip>
#include <typeinfo>
using namespace std;


//Глоб альные данные
struct Student{
    char name[20];
    char surname[20];
    char secondname[20];
    int course;
    char group[10];
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;
    int mark6;
};

struct Student people [100];
int len = 0;
int menue_numb = 1000;

//Подсобные функции
int numcheck(char tr[]){
    if(strlen(tr) == 1 && isdigit(tr[0]) == 1){
        return (int)tr[0] - 48;
    }
    else if(strlen(tr) == 2 && isdigit(tr[0]) == 1 && isdigit(tr[1]) == 1){
        return (((int)tr[0] - 48) * 10 + (int)tr[1] - 48);
    }
    else{
        system("cls");
        cout << "Пожалуйста введите число\n";
        system("pause");
        return 33;
    }
}
int numcheck_menue(char tr[]){
    if(strlen(tr) == 1 && isdigit(tr[0]) == 1){
        return (int)tr[0] - 48;
    }
    else if(strlen(tr) == 2 && isdigit(tr[0]) == 1 && isdigit(tr[1]) == 1){
        if (((int)tr[0] - 48) * 10 + (int)tr[1] - 48 > 11){
            system("cls");
            cout << "Пожалуйста введите число из списка\n";
            system("pause");
            return 33;
            }
        else{
            return (((int)tr[0] - 48) * 10 + (int)tr[1] - 48);
        }    
    }
    else{
        system("cls");
        cout << "Пожалуйста введите число\n";
        system("pause");
        return 33;
    }
}


void ramka(int t){
    if (t == 1){
        cout <<"|-------surname|" << "------name|" << "---secondname|" << "course|" << "group|"<< "mark1|" << "mark2|" << "mark3|" << "mark4|" << "mark5|" << "mark6|" << "\n";
    }
    else if (t == 0){
        cout << "|";
        for (int j = 0; j < 88; j++){
            cout << "-";
        }
        cout << "|" << "\n";
    }
}

bool lencheck(){
    if (len == 0){
        cout << "База данных не загружена в программу\n";
        system("pause");
        return 1;
    }
    else{
        return 0;
    }
}

void print(Student people[], int numb){
    cout << "|" <<  setw(14) << people[numb].surname << "|" ;
    cout << setw(10)  << people[numb].name << "|";
    cout << setw(13) << people[numb].secondname << "|" ;
    cout << setw(6) << people[numb].course << "|" ;
    cout << setw(5) << people[numb].group << "|";
    cout << setw(5) << people[numb].mark1 << "|";
    cout << setw(5) << people[numb].mark2 << "|";
    cout << setw(5) << people[numb].mark3 << "|";
    cout << setw(5) << people[numb].mark4 << "|" ;
    cout << setw(5) << people[numb].mark5 << "|" ;
    cout << setw(5) << people[numb].mark6 << "|" << endl;
}


void swp(int j){
    char temp [20];
    int tmp;
    strcpy(temp, people[j].name);
    people[j].name[0] = 0;
    strcpy(people[j].name, people[j+1].name);
    people[j+1].name[0] = 0;
    strcpy(people[j+1].name, temp);
    temp[0] = 0;

    strcpy(temp, people[j].surname);
    people[j].surname[0] = 0;
    strcpy(people[j].surname, people[j+1].surname);
    people[j+1].surname[0] = 0;
    strcpy(people[j+1].surname, temp);
    temp[0] = 0;

    strcpy(temp, people[j].secondname);
    people[j].secondname[0] = 0;
    strcpy(people[j].secondname, people[j+1].secondname);
    people[j+1].secondname[0] = 0;
    strcpy(people[j+1].secondname, temp);
    temp[0] = 0;

    tmp = people[j].course;
    people[j].course = people[j+1].course;
    people[j+1].course = tmp;

    strcpy(temp, people[j].group);
    people[j].group[0] = 0;
    strcpy(people[j].group, people[j+1].group);
    people[j+1].group[0] = 0;
    strcpy(people[j+1].group, temp);
    temp[0] = 0;

    tmp = people[j].mark1;
    people[j].mark1 = people[j+1].mark1;
    people[j+1].mark1 = tmp;

    tmp = people[j].mark2;
    people[j].mark2 = people[j+1].mark2;
    people[j+1].mark2 = tmp;

    tmp = people[j].mark3;
    people[j].mark3 = people[j+1].mark3;
    people[j+1].mark3 = tmp;

    tmp = people[j].mark4;
    people[j].mark4 = people[j+1].mark4;
    people[j+1].mark4 = tmp;

    tmp = people[j].mark5;
    people[j].mark5 = people[j+1].mark5;
    people[j+1].mark5 = tmp;

    tmp = people[j].mark6;
    people[j].mark6 = people[j+1].mark6;
    people[j+1].mark6 = tmp;
}


//Функции программ

void vvod(Student people[]){
    system("cls");
    int n;
    char tr[100];
    cout << "сколько человек вы хотите внести?\n";
    cin >> tr;
    n = numcheck(tr);
    if (n == 33){
        vvod(people);
        return;
    }



    for (int i = 0; i < n; i++){
        cout << "Введите имя\n";
        cin >> people[len].name;


        cout << "Введите фамилию\n";
        cin >> people[len].surname;
        
        
        cout << "Введите отчество\n";
        cin >> people[len].secondname;
        
        
        char tz[20];
        int nm = 33;
        while(nm == 33){
            cout << "Введите курс\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].course = nm;
        
        
        cout << "Введите группу\n";
        cin >> people[len].group;
    
    
        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 1\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark1 = nm;

        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 2\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark2 = nm;
    
    
        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 3\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark3 = nm;
    
    
        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 4\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark4 = nm;
    
    
        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 5\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark5 = nm;
    
    
        nm = 33;
        while(nm == 33){
            cout << "Введите оценку 6\n";
            cin >> tz;
            nm = numcheck(tz);
        }
        people[len].mark6 = nm;

        len++;
    }
    system("pause");
}  


void vivod(Student people[]){
    if (lencheck()){
        system("cls");
        return;
    }


    system("cls");
    ramka(1);
    for (int i = 0; i < len; i++){
        print(people, i);
    }
    ramka(0);
    system("pause");
}

void spec(Student people[]){
    if (lencheck()){
        system("cls");
        return;
    }


    system("cls");
    ramka(1);
    for (int i = 0; i < len; i++){
        if (people[i].mark1 == 2 || people[i].mark2 == 2 || people[i].mark3 == 2\
        || people[i].mark4 == 2 || people[i].mark5 == 2 || people[i].mark6 == 2){
            print(people, i);
        }
    }
    ramka(0);
    system("pause");
}

void change(Student people[]){
    if (lencheck()){
        system("cls");
        return;
    }

    system("cls");
    cout <<"|-№";
    ramka(1);
    for (int i = 0; i < len; i++){
        cout << "|" << i + 1;
        if(i < 9){
            cout << ' ';
        }
        print(people, i);
    }
    cout << "|--";
    ramka(0);
    cout << "Данные какого из учеников вы хотите изменить?";
    int j;
    cin >> j;
    j -= 1;
    if (j >= len || j < 0){
        system("cls");
        cout << "Введите число из списка\n";
        system("pause");
        change(people);
        return;
    }
    else{
        system("cls");
        cout << "Что именно вы хотите изменить?\n";
        int n;
        cout << "0 - все данные\n";
        cout << "1 - имя\n";
        cout << "2 - фамилия\n";
        cout << "3 - отчество\n";
        cout << "4 - курс\n";
        cout << "5 - группа\n";
        cout << "6 - оценка 1\n";
        cout << "7 - оценка 2\n";
        cout << "8 - оценка 3\n";
        cout << "9 - оценка 4\n";
        cout << "10 - оценка 5\n";
        cout << "11 - оценка 6\n";
        cin >> n;
        switch (n)
        {
        case 0:
            cout << "Введите имя\n";
            cin >> people[j].name;


            cout << "Введите фамилию\n";
            cin >> people[j].surname;
            
            
            cout << "Введите отчество\n";
            cin >> people[j].secondname;
            
            
            cout << "Введите курс\n";
            cin >> people[j].course;
            
            
            cout << "Введите группу\n";
            cin >> people[j].group;
        
        
            cout << "Введите оценку 1\n";
            cin >> people[j].mark1;


            cout << "Введите оценку 2\n";
            cin >> people[j].mark2;
        
        
            cout << "Введите оценку 3\n";
            cin >> people[j].mark3;
        
        
            cout << "Введите оценку 4\n";
            cin >> people[j].mark4;
        
        
            cout << "Введите оценку 5\n";
            cin >> people[j].mark5;
        

            cout << "Введите оценку 6\n";
            cin >> people[j].mark6;
            break;
        
        case 1:
            cout << "Введите имя\n";
            cin >> people[j].name;
            break;

        case 2:
            cout << "Введите фамилию\n";
            cin >> people[j].surname;
            break;

        case 3:
            cout << "Введите отчество\n";
            cin >> people[j].secondname;
            break;
        
        case 4:
            cout << "Введите курс\n";
            cin >> people[j].course;
            break;

        case 5:
            cout << "Введите группу\n";
            cin >> people[j].group;
            break;
        
        case 6:
            cout << "Введите оценку 1\n";
            cin >> people[j].mark1;
            break;

        case 7:
            cout << "Введите оценку 2\n";
            cin >> people[j].mark2;
            break;

        case 8:
            cout << "Введите оценку 3\n";
            cin >> people[j].mark3;
            break;

        case 9:
            cout << "Введите оценку 4\n";
            cin >> people[j].mark4;
            break;

        case 10:
            cout << "Введите оценку 5\n";
            cin >> people[j].mark5;
            break;

        case 11:
            cout << "Введите оценку 6\n";
            cin >> people[j].mark6;
            break;

        default:
            cout << "Ваше число не из списка";
            system("pause");
            break;
        }
    }
}


void dels(Student people[]){
    if (lencheck()){
        system("cls");
        return;
    }
    system("cls");
    cout <<"|-№";
    ramka(1);
    for (int i = 0; i < len; i++){
        cout << "|" << i + 1;
        if (i < 9){
            cout <<' ';
        }
        print(people, i);
    }
    cout << "|--";
    ramka(0);
    cout << "Данные какого из учеников вы хотите удалить?\n";
    int j;
    cin >> j;
    j -= 1;
    if (j >= len || j < 0){
        system("cls");
        cout << "Введите число из списка\n";
        system("pause");
        change(people);
        return;
    }
    else{
        for (int i = j; i < len; i++){
            people[i].name[0] = 0;
            strcpy(people[i].name, people[i+1].name);
            people[i].surname[0] = 0;
            strcpy(people[i].surname, people[i+1].surname);
            people[i].secondname[0] = 0;
            strcpy(people[i].secondname, people[i+1].secondname);
            people[i].group[0] = 0;
            strcpy(people[i].group, people[i+1].group);
            people[i].course = people[i+1].course;
            people[i].mark1 = people[i+1].mark1;
            people[i].mark2 = people[i+1].mark2;
            people[i].mark3 = people[i+1].mark3;
            people[i].mark4 = people[i+1].mark4;
            people[i].mark5 = people[i+1].mark5;
            people[i].mark6 = people[i+1].mark6;
        }
        len--;
    }
}


void sort(Student people[]){
    system("cls");
    if (lencheck()){
        system("cls");
        return;
    }
    system("cls");
    int n;
    cout << "По какому параметру вы хотите отсортировать базу данных?\n";
    cout << "[1] Имя\n";
    cout << "[2] Фамилия\n";
    cout << "[3] Отчество\n";
    cout << "[4] Курс\n";
    cout << "[5] Группа\n";
    cout << "[6] Оценка 1\n";
    cout << "[7] Оценка 2\n";
    cout << "[8] Оценка 3\n";
    cout << "[9] Оценка 4\n";
    cout << "[10] Оценка 5\n";
    cout << "[11] Оценка 6\n";
    cin >> n;


    switch (n)
    {
    case 1:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].name[0] > (int)people[j + 1].name[0]){
                    swp(j);
                }
            }    
        }    
        break;
    
    case 2:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].surname[0] > (int)people[j + 1].surname[0]){
                    swp(j);
                }
            }
        }
        break;

    case 3:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].secondname[0] > (int)people[j + 1].secondname[0]){
                    swp(j);
                }
            }
        }
        break;

    case 4:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if (people[j].course < people[j + 1].course){
                    swp(j);
                }
            }
        }
        break;

    case 5:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].group[0] > (int)people[j + 1].group[0]){
                    swp(j);
                }
            }
        }
        break;

    case 6:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark1 < (int)people[j + 1].mark1){
                    swp(j);
                }
            }
        }
        break;
    
    case 7:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark2 < (int)people[j + 1].mark2){
                    swp(j);
                }
            }
        }
        break;
    
    
    case 8:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark3 < (int)people[j + 1].mark3){
                    swp(j);
                }
            }
        }
        break;
    
    
    case 9:
        for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark4 < (int)people[j + 1].mark4){
                    swp(j);
                }
            }
        }
        break;
    
    
    case 10:
    for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark5 < (int)people[j + 1].mark5){
                    swp(j);
                }
            }
        }
        break;
    

    
    case 11:
    for (int i = 0; i < len - 1; i++){
            for (int j = 0; j < len - i - 1; j++){
                if ((int)people[j].mark6 < (int)people[j + 1].mark6){
                    swp(j);
                }
            }
        }
        break;
    

    default:
        cout << "Введите число из списка\n";
        system("pause");
        sort(people);
        break;
    }
}


void base_download(Student people[]){
    system("cls");
    ifstream fin;
    char ch[100];
    fin.open("base.txt", ios :: app);
    while(!fin.eof()){
        fin >> ch;
        strcpy(people[len].surname, ch);
        fin >> ch;
        strcpy(people[len].name, ch);
        fin >> ch;
        strcpy(people[len].secondname, ch);
        fin >> ch;
        people[len].course = (int)ch[0] - 48;
        fin >> ch;
        strcpy(people[len].group, ch);
        fin >> ch;
        people[len].mark1 = (int)ch[0] - 48;
        fin >> ch;
        people[len].mark2 = (int)ch[0] - 48;
        fin >> ch;
        people[len].mark3 = (int)ch[0] - 48;
        fin >> ch;
        people[len].mark4 = (int)ch[0] - 48;
        fin >> ch;
        people[len].mark5 = (int)ch[0] - 48;
        fin >> ch;
        people[len].mark6 = (int)ch[0] - 48;
        len++;
    }
    fin.close();
}

void base_upload(Student people[], int end){
    if (len == 0 && end == 0){
        system("cls");
        cout << "Введите данные\n";
        system("pause");
        return;
    }
    else if(len == 0 && end == 1){
        return;
    }
    ofstream fout;
    fout.open("base.txt", ios :: app);
    for(int i = 0; i < len ;i++){
        fout << people[i].surname << " ";
        fout << people[i].name << " ";
        fout << people[i].secondname << " ";
        fout << people[i].course << " ";
        fout << people[i].group << " ";
        fout << people[i].mark1 << " ";
        fout << people[i].mark2 << " ";
        fout << people[i].mark3 << " ";
        fout << people[i].mark4 << " ";
        fout << people[i].mark5 << " ";
        fout << people[i].mark6 << "\n";
    }
    fout.close();
}

void binary_upload(Student people[], int end){
    if (len == 0 && end == 0){
        system("cls");
        cout << "Введите данные\n";
        system("pause");
        return;
    }
    else if(len == 0 && end == 1){
        return;
    }
    ofstream fout("text.bin", ios::binary);
    for(int i = 0;i < len;i++){
        fout.write((char*)&people[i].surname, sizeof(people[i].surname));
        fout.write((char*)&people[i].name, sizeof(people[i].name));
        fout.write((char*)&people[i].secondname, sizeof(people[i].secondname));
        fout.write((char*)&people[i].course, sizeof(people[i].course));
        fout.write((char*)&people[i].group, sizeof(people[i].group));
        fout.write((char*)&people[i].mark1, sizeof(people[i].mark1));
        fout.write((char*)&people[i].mark2, sizeof(people[i].mark2));
        fout.write((char*)&people[i].mark3, sizeof(people[i].mark3));
        fout.write((char*)&people[i].mark4, sizeof(people[i].mark4));
        fout.write((char*)&people[i].mark5, sizeof(people[i].mark5));
        fout.write((char*)&people[i].mark6, sizeof(people[i].mark6));
    }
    fout.close();
    system("pause");
}

void binary_download(Student people[]){
    ifstream fin("text.bin", ios::binary);
    while(!fin.eof()){
        fin.read((char*)&people[len].surname,sizeof(people[len].surname));
        fin.read((char*)&people[len].name,sizeof(people[len].name));
        fin.read((char*)&people[len].secondname,sizeof(people[len].secondname));
        fin.read((char*)&people[len].course,sizeof(people[len].course));
        fin.read((char*)&people[len].group,sizeof(people[len].group));
        fin.read((char*)&people[len].mark1,sizeof(people[len].mark1));
        fin.read((char*)&people[len].mark2,sizeof(people[len].mark2));
        fin.read((char*)&people[len].mark3,sizeof(people[len].mark3));
        fin.read((char*)&people[len].mark4,sizeof(people[len].mark4));
        fin.read((char*)&people[len].mark5,sizeof(people[len].mark5));
        fin.read((char*)&people[len].mark6,sizeof(people[len].mark6));
        len++;
    }
    fin.close();
}
void binary_to_txt(Student people[]){
    struct Student temp[100];
    char ch[30];
    int num = 0;
    ifstream fin("base.txt", ios::app);
    while(!fin.eof()){
        fin >> ch;
        strcpy(temp[num].surname, ch);
        fin >> ch;
        strcpy(temp[num].name, ch);
        fin >> ch;
        strcpy(temp[num].secondname, ch);
        fin >> ch;
        temp[num].course = (int)ch[0] - 48;
        fin >> ch;
        strcpy(temp[num].group, ch);
        fin >> ch;
        temp[num].mark1 = (int)ch[0] - 48;
        fin >> ch;
        temp[num].mark2 = (int)ch[0] - 48;
        fin >> ch;
        temp[num].mark3 = (int)ch[0] - 48;
        fin >> ch;
        temp[num].mark4 = (int)ch[0] - 48;
        fin >> ch;
        temp[num].mark5 = (int)ch[0] - 48;
        fin >> ch;
        temp[num].mark6 = (int)ch[0] - 48;
        num++;
    }
    fin.close();
    ofstream fout("text.bin", ios::binary);
    for(int i = 0;i < num;i++){
        fout.write((char*)&temp[i].surname, sizeof(temp[i].surname));
        fout.write((char*)&temp[i].name, sizeof(temp[i].name));
        fout.write((char*)&temp[i].secondname, sizeof(temp[i].secondname));
        fout.write((char*)&temp[i].course, sizeof(temp[i].course));
        fout.write((char*)&temp[i].group, sizeof(temp[i].group));
        fout.write((char*)&temp[i].mark1, sizeof(temp[i].mark1));
        fout.write((char*)&temp[i].mark2, sizeof(temp[i].mark2));
        fout.write((char*)&temp[i].mark3, sizeof(temp[i].mark3));
        fout.write((char*)&temp[i].mark4, sizeof(temp[i].mark4));
        fout.write((char*)&temp[i].mark5, sizeof(temp[i].mark5));
        fout.write((char*)&temp[i].mark6, sizeof(temp[i].mark6));
    }
    fout.close();
    system("pause");
}

void safe_prgrs(Student people[]){
    system("cls");
    if (lencheck()){
        system("cls");
        return;
    }
    int tmp = 33;
    cout << "Вы хотите сохранить свой прогресс?\n";
    cout << "[1] ДА\n";
    cout << "[2] НЕТ\n";
    while (tmp != 1 or tmp != 2){
        cin >> tmp;
        if (tmp == 1){
            if(len > 0){
                base_upload(people, 1);
                binary_upload(people, 1);
            }
            return;
        }
        else if(tmp == 2){
            ofstream gi("base.txt");
            ofstream gb("text.bin");
            gi.close();
            gb.close();
            return;
        } 
        else{
            cout << "Введите число из списка";
        }
    }
}