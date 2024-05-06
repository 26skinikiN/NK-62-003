#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <Windows.h>
using namespace std;
struct Processor
{
    string manufacturer;
    string model;
    int price;
};
struct Videocard
{
    string manufacturer;
    string model;
    int price;
};
struct Motherboard
{
    string manufacturer;
    string model;
    int price;
};
// ФУНКЦИИ ДЛЯ ПРОЦЕССОРОВ
void writeProcessorsArrayToFile(Processor* arr_of_processors, int number_of_processors);// Запись в файл (если что-то было в файле, то исходные данные будут удалены): 
void writeEndFileProcessors(Processor new_processor); // Добавление в конец файла одной строки: 
void readFileProcessors(Processor* arr_of_processors, int& number_of_processors);// Чтение из файла в массив:
void generateProcessorsArray(Processor* arr_of_processors, int& number_of_processors); // Заполнение массива процессоров
void addProcessorsInArray(Processor* arr_of_processors, int& number_of_processors); // Добавление процессора в массив
void delProcessorsFromArray(Processor* arr_of_processors, int& number_of_processors); // Удаление процессора из массива
void showProcessorsArray(Processor* arr_of_processors, int number_of_processors);  // Вывод содержимого массива на экран
void sortProcessorsArray(Processor* arr_of_processors,int& number_of_processors);
void searchProcessorsInArray(Processor* arr_of_processors, int& number_of_processors);
// ФУНКЦИИ ДЛЯ ВИДЕОКАРТ
void writeVideoCardsArrayToFile(Videocard* arr_of_videocards, int number_of_videocards);
void writeEndFileVideoCards(Videocard new_videocard);
void readFileVideoCards(Videocard* arr_of_videocards, int& number_of_videocards);
void generateVideocardsArray(Videocard* arr_of_videocards, int& number_of_videocards);
void addVideocardsInArray(Videocard* arr_of_videocards, int& number_of_videocards);
void delVideocardsFromArray(Videocard* arr_of_videocards, int& number_of_videocards);
void showVideocardsArray(Videocard* arr_of_videocards, int number_of_videocards);
void sortVideocardsArray(Videocard* arr_of_videocards, int number_of_videocards);
void searchVideocardsInArray(Videocard* arr_of_videocards, int number_of_videocards);
// ФУНКЦИИ ДЛЯ МАТЕРИНСКИХ ПЛАТ
void writeMotherboardsArrayToFile(Motherboard* arr_of_motherboards, int number_of_motherboards);
void writeEndFileMotherboards(Motherboard new_motherboard);
void readFileMotherboards(Motherboard* arr_of_motherboards, int& number_of_motherboards);
void generateMotherboardsArray(Motherboard* arr_of_motherboards, int& number_of_motherboards);
void addMotherboardsInArray(Motherboard* arr_of_motherboards, int& number_of_motherboards);
void delMotherboardsFromArray(Motherboard* arr_of_motherboards, int& number_of_motherboards);
void showMotherboardsArray(Motherboard* arr_of_motherboards, int number_of_motherboards);
void sortMotherboardsArray(Motherboard* arr_of_motherboards, int number_of_motherboards);
void searchMotherboardsInArray(Motherboard* arr_of_motherboards, int number_of_motherboards);
// ПУТИ ДЛЯ ФАЙЛОВ
const string FILE_OF_PROCESSORS = "ProcessorList.txt"; //Путь к файлу
const string FILE_OF_VIDEOCARDS = "VideocardsList.txt";
const string FILE_OF_MOTHERBOARDS = "MotherboardList.txt";
const int FILE_SIZE = 100; //Максимальное количество элементов массива
const int secure_code = 223344;
// ФУНКЦИИ ГЛАВНОГО МЕНЮ
void Login();
void Registration();
void changeData();
void Administrator(Processor* arr_of_processors, int number_of_processors,
    Videocard* arr_of_videocards, int number_of_videocards,
    Motherboard* arr_of_motherboards, int number_of_motherboards);
void User(Processor* arr_of_processors, int number_of_processors,
    Videocard* arr_of_videocards, int number_of_videocards,
    Motherboard* arr_of_motherboards, int number_of_motherboards);
void checkRole(Processor* arr_of_processors, int number_of_processors, Videocard* arr_of_videocards, int number_of_videocards, Motherboard* arr_of_motherboards, int number_of_motherboards);
void main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251); // ввод данных в консоль на русском
    SetConsoleOutputCP(1251);
    
    Processor arr_of_processors[FILE_SIZE];
    int number_of_processors = 0;
    Videocard arr_of_videocards[FILE_SIZE];
    int number_of_videocards = 0;
    Motherboard arr_of_motherboards[FILE_SIZE];
    int number_of_motherboards = 0;
    generateProcessorsArray(arr_of_processors, number_of_processors);
    writeProcessorsArrayToFile(arr_of_processors, number_of_processors);
    generateVideocardsArray(arr_of_videocards, number_of_videocards);
    writeVideoCardsArrayToFile(arr_of_videocards, number_of_videocards);
    generateMotherboardsArray(arr_of_motherboards, number_of_motherboards);
    writeMotherboardsArrayToFile(arr_of_motherboards, number_of_motherboards);
    while (true) {
        cout << "-------------------------------------------------------------------------\n";
        cout << "----------------------    ГЛАВНОЕ МЕНЮ     ------------------------------\n";
        cout << "-------------------------------------------------------------------------\n";
        cout << "1)Войти\n2)Зарегистрироваться\n3)Выход.";
        switch (_getch())
        {
        case '1':
            system("cls");
            Login();
            cin.get();
            cin.get();
            system("cls");
            checkRole(arr_of_processors, number_of_processors,arr_of_videocards, number_of_videocards, arr_of_motherboards,number_of_motherboards);
            break;
        case '2':
            system("cls");
            Registration();
            break;
        case '3':
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "-----------------             ВЫХОД                  --------------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Вы действительно хотите завершить работу?\n1)Да.\n2)Нет.";
            if (_getch() == '1')
            {
                system("cls");
                cout << "\nБлагодарим за использование приложения! \n\n";
                exit(0);
            }else
            {
                system("cls");
                main();
            }
        default:
            system("cls");       
        }
    }
}
// АВТОРИЗАЦИЯ
void Login()
{
    int clear=0;
    string login, password, lg, p;
    cout << "-------------------------------------------------------------------------\n";
    cout << "-----------------             ВХОД                   --------------------\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    ifstream input("AccountData.txt");
    while (input >> lg >> p)
    {
        if (lg == login && p == password)

        {
            clear = 1;
            system("cls");
        }
    }
    input.close();
    if (clear == 1)
    {
        cout << "\nВход совершен успешно.\nЗдравствуйте, " << login << ".\nНажмите Enter для продолжения.";

    }
    else
    {
        cout << "\nОшибка! Введен неверный логин или пароль.\nНажмите Enter для возвращения в главное меню.\n";
        cin.get();
        cin.get();
        system("cls");
        main();
    }
}
void Registration()
{
    int check = 0;
    string login, password,lu, u, p;
    cout << "-------------------------------------------------------------------------\n";
    cout << "-----------------            РЕГИСТРАЦИЯ             --------------------\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "Введите логин: ";
    cin >> login;
    ifstream open("AccountData.txt");
    while (open >> lu)
    {
        if (lu == login )

        {
            check = 1;
        }
    }
    open.close();
    if (check == 1)
    {
        cout << "\nОшибка!\nПользователь с таким логином уже существует.\nНажмите Enter для повторной попытки.";
        cin.get();
        cin.get();
        system("cls");
        Registration();
    }
    else
    {
        cout << "Введите пароль: ";
        cin >> password;
        ofstream reg("AccountData.txt", ios::app);
        reg << login << ' ' << password << endl;
        system("cls");
        cout << "\nРегистрация прошла успешно.\nНажмите Enter для продолжения.";
        cin.get();
        cin.get();
        system("cls");
        main();
    }
}
void changeData()
{
    string login, password, lg, ps, user_new,pass_new;
    int clear=0;
    system("cls");
    cout << "Вы уверены что хотите изменить текущие данные?\n1)Да.\n2)Нет.";
    ifstream input("AccountData.txt");
    if (_getch() == '1')
    {
        system("cls");
        cout << "Введите старый логин: ";
        cin >> login;
        cout << "Введите старый пароль: ";
        cin >> password;
        while (input >> lg >> ps)
        {
            if (lg == login && ps == password)
            {
                clear = 1;
                system("cls");
            }
        }
        input.close();
        if (clear == 1)
        {
            cout << "\nУспешный ввод.\n";
            cout << "Введите новый логин: ";
            cin >> user_new;
            cout << "Введите новый пароль: ";
            cin >> pass_new;
            ofstream add("AccountData.txt", ios::app);
            add << user_new << ' ' << pass_new << endl;
            system("cls");
            cout << "\nСмена прошла успешно.\nНажмите Enter для выхода в главное меню.";
            cin.get();
            cin.get();
            main();
        }
        else
        {
            cout << "\nОшибка.\nНажмите Enter для повторной попытки.\n";
            cin.get();
            cin.get();
            changeData();
        }
    }
    else
    {
        system("cls");
        main();
    }
}
void checkRole(Processor* arr_of_processors, int number_of_processors, Videocard* arr_of_videocards, int number_of_videocards, Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    int check_code = 0;
    cout << "Выберите:\n1)Войти как администратор.\n2)Войти как пользователь.\n3)Изменить данные.\n";
    switch (_getch())
    {
    case '1':
        system("cls");
        cout << "\nВведите код доступа администратора: ";
        cin >> check_code;
        if (check_code == secure_code)
        {
            system("cls");
            cout << "Вход совершен успешно!\nЗдравстуйте, уважаемый администратор.\nНажмите Enter для продолжения.";
            cin.get();
            cin.get();
            system("cls");
            Administrator(arr_of_processors, number_of_processors,arr_of_videocards, number_of_videocards,
                arr_of_motherboards, number_of_motherboards);
        }
        else
        {
            cout << "\nВведен неверный код доступа!\nНажмите Enter для продолжения.\n";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        break;
    case '2':
        system("cls");
        cout << "\nЗдравстуйте, уважаемый пользователь.\nНажмите Enter для продолжения.";
        cin.get();
        system("cls");
        User(arr_of_processors, number_of_processors,
            arr_of_videocards, number_of_videocards,
            arr_of_motherboards, number_of_motherboards);
        break;
    case '3':
        system("cls");
        changeData();
        break;
    }
}
// МОДУЛЬ АДМИНИСТРАТОРА
void Administrator(Processor* arr_of_processors, int number_of_processors,Videocard* arr_of_videocards, int number_of_videocards,Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    while (true) {
        cout << "-------------------------------------------------------------------------\n";
        cout << "-----------------         МЕНЮ АДМИНИСТРАТОРА          ------------------\n";
        cout << "-------------------------------------------------------------------------\n";
        cout << "Выберите:\n1)Процессор.\n2)Видеокарта.\n3)Материнская плата.\n4)Главное меню.";
        switch (_getch())
        {
        case '1':// Работа с процессорами
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "-----------------            ПРОЦЕССОРЫ                 -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите:\n1)Просмотр деталей.\n2)Добавление детали.\n3)Удаление детали.\n4)Сортировка деталей.\n5)Назад.";
            switch (_getch())
            {
            case '1':
                system("cls");
                showProcessorsArray(arr_of_processors, number_of_processors);
                break;
            case '2':
                system("cls");
                addProcessorsInArray(arr_of_processors, number_of_processors);
                break;
            case'3':
                system("cls");
                delProcessorsFromArray(arr_of_processors, number_of_processors);
                break;
            case '4':
                system("cls");
                sortProcessorsArray(arr_of_processors, number_of_processors);
                break;
            default:
                system("cls");
            }
            break;
        case '2'://Работа с видеокаратми
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "-----------------            ВИДЕОКАРТЫ                 -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите:\n1)Просмотр деталей.\n2)Добавление детали.\n3)Удаление детали.\n4)Сортировка деталей.\n5)Назад.";
            switch (_getch())
            {
            case '1':
                system("cls");
                showVideocardsArray(arr_of_videocards, number_of_videocards);
                break;
            case '2':
                system("cls");
                addVideocardsInArray(arr_of_videocards, number_of_videocards);
                break;
            case'3':
                system("cls");
                delVideocardsFromArray(arr_of_videocards, number_of_videocards);
                break;
            case '4':
                system("cls");
                sortVideocardsArray(arr_of_videocards, number_of_videocards);
                break;
            default:
                system("cls");
            }
            break;
        case '3':// Работа с материнскими платами
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "--------------           МАТЕРИНСКИЕ ПЛАТЫ              -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите:\n1)Просмотр деталей.\n2)Добавление детали.\n3)Удаление детали.\n4)Сортировка деталей.\n5)Назад.";
            switch (_getch())
            {
            case '1':
                system("cls");
                showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
                break;
            case '2':
                system("cls");
                addMotherboardsInArray(arr_of_motherboards, number_of_motherboards);
                break;
            case'3':
                system("cls");
                delMotherboardsFromArray(arr_of_motherboards, number_of_motherboards);
                break;
            case '4':
                system("cls");
                sortMotherboardsArray(arr_of_motherboards, number_of_motherboards);
                break;
            default:
                system("cls");
            }
            break;
        default:
            system("cls");
            return;
        }
    }
}
// МОДУЛЬ ПОЛЬЗОВАТЕЛЯ
void User(Processor* arr_of_processors, int number_of_processors, Videocard* arr_of_videocards, int number_of_videocards, Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    while (true) {
        cout << "-------------------------------------------------------------------------\n";
        cout << "-----------------          МЕНЮ ПОЛЬЗОВАТЕЛЯ            -----------------\n";
        cout << "-------------------------------------------------------------------------\n";
        cout << "Выберите:\n1)Процессор.\n2)Видеокарта.\n3)Материнская плата.\n4)Главное меню.";
        switch (_getch())
        {
        case '1':// Работа с процессорами
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "-----------------            ПРОЦЕССОРЫ                 -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите действие:\n1)Просмотр деталей.\n2)Поиск детали.\n3)Сортировка деталей.\n4)Назад.";
            switch (_getch())
            {
            case '1':
                system("cls");
                showProcessorsArray(arr_of_processors, number_of_processors);
                break;
            case '2':
                system("cls");
                searchProcessorsInArray(arr_of_processors, number_of_processors);
                break;
            case'3':
                system("cls");
                sortProcessorsArray(arr_of_processors, number_of_processors);
                break;
            default:
                system("cls");
            }
            break;
        case '2'://Работа с видеокаратми
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "-----------------            ВИДЕОКАРТЫ                 -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите действие:\n1)Просмотр деталей.\n2)Поиск детали.\n3)Сортировка деталей.\n4)Назад.";
            switch (_getch())
            {
            case '1':
                system("cls");
                showVideocardsArray(arr_of_videocards, number_of_videocards);
                break;
            case '2':
                system("cls");
                searchVideocardsInArray(arr_of_videocards, number_of_videocards);
                break;
            case'3':
                system("cls");
                sortVideocardsArray(arr_of_videocards, number_of_videocards);
                break;
            default:
                system("cls");
            }
            break;
        case '3':// Работа с материнскими платами
            system("cls");
            cout << "-------------------------------------------------------------------------\n";
            cout << "--------------           МАТЕРИНСКИЕ ПЛАТЫ              -----------------\n";
            cout << "-------------------------------------------------------------------------\n";
            cout << "Выберите действие:\n1)Просмотр деталей.\n2)Поиск детали.\n3)Сортировка деталей.\n4)Назад.";

            switch (_getch())
            {
            case '1':
                system("cls");
                showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
                break;
            case '2':
                system("cls");
                searchMotherboardsInArray(arr_of_motherboards, number_of_motherboards);
                break;
            case'3':
                system("cls");
                sortMotherboardsArray(arr_of_motherboards, number_of_motherboards);
                break;
            default:
                system("cls");
            }
            break;
        default:
            system("cls");
            return;
        }
    }
}
// ПРОЦЕССОРЫ
void generateProcessorsArray(Processor* arr_of_processors, int& number_of_processors)
{
    number_of_processors = 6;
    arr_of_processors[0].manufacturer = "Intel";
    arr_of_processors[0].model = "I5";
    arr_of_processors[0].price = 340;
    arr_of_processors[1].manufacturer = "Asus";
    arr_of_processors[1].model = " R3";
    arr_of_processors[1].price = 270;
    arr_of_processors[2].manufacturer = "Intel";
    arr_of_processors[2].model = "I6";
    arr_of_processors[2].price = 353;
    arr_of_processors[3].manufacturer = "Intel";
    arr_of_processors[3].model = "I9";
    arr_of_processors[3].price = 960;
    arr_of_processors[4].manufacturer = "Asus";
    arr_of_processors[4].model = " R8";
    arr_of_processors[4].price = 650;
    arr_of_processors[5].manufacturer = "Asus";
    arr_of_processors[5].model = " R5";
    arr_of_processors[5].price = 420;
}
void addProcessorsInArray(Processor* arr_of_processors, int& number_of_processors) //добавление процессора, если не происходит выход за пределы массива 
{
    if (number_of_processors + 1 <= FILE_SIZE)
    {
        cout << "Введите название фирмы производителя: ";
        cin >> arr_of_processors[number_of_processors - 1].manufacturer;
        cout << "Введите название модели: ";
        cin >> arr_of_processors[number_of_processors - 1].model;
        cout << "Введите цену: ";
        cin >> arr_of_processors[number_of_processors - 1].price;
        if (arr_of_processors[number_of_processors].price <= 0)
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            system("cls");
            addProcessorsInArray(arr_of_processors,number_of_processors);
        }
        else
        {
        writeEndFileProcessors(arr_of_processors[number_of_processors - 1]);
        }
    }
    else cout << "Недостаточно памяти для добавления нового элемента!" << endl;
}
void delProcessorsFromArray(Processor* arr_of_processors, int& number_of_processors)
{
    int number_of_deleted_item;
    cout << "Певоначальный список:\n";
    showProcessorsArray(arr_of_processors, number_of_processors);
    cout << "Введите номер удаляемой записи: ";
    cin >> number_of_deleted_item;
    --number_of_deleted_item;
    if (number_of_deleted_item >= 0 && number_of_deleted_item < number_of_processors)
    {
        for (int i = number_of_deleted_item; i < number_of_processors - 1; i++) 
            arr_of_processors[i] = arr_of_processors[i + 1];

            --number_of_processors; writeProcessorsArrayToFile(arr_of_processors, number_of_processors);
    }
    else
    {
        cout << "Введен некорректный номер удалемой записи!\nНажмите Enter для повторной попытки." << endl;
        cin.get();
        cin.get();
        system("cls");
        delProcessorsFromArray(arr_of_processors, number_of_processors);
    }
    cout << "Удаление прошло успешно.\nНовый список:\n";
    showProcessorsArray(arr_of_processors, number_of_processors);
}
void showProcessorsArray(Processor* arr_of_processors, int number_of_processors)
{
    for (int i = 0; i < number_of_processors; i++) 
        cout << arr_of_processors[i].manufacturer << " " << arr_of_processors[i].model << " " << arr_of_processors[i].price << endl;
}
void writeProcessorsArrayToFile(Processor* arr_of_processors, int number_of_processors)
{
    ofstream fout(FILE_OF_PROCESSORS, ios::out /*ofstream::app*/); // Открыли файл для записи 
    for (int i = 0; i < number_of_processors; i++)
    {
        fout << arr_of_processors[i].manufacturer << " "
            << arr_of_processors[i].model << " " << arr_of_processors[i].price;
        if (i < number_of_processors - 1)
        {
            fout << endl;
        }
    } fout.close();
}
void writeEndFileProcessors(Processor new_processor)
{
    ofstream fadd(FILE_OF_PROCESSORS, ios::app); // Открыли файл для дозаписи 
    fadd << endl;
    fadd << new_processor.manufacturer << " "
        << new_processor.model << " " << new_processor.price;
    fadd.close();
}
void readFileProcessors(Processor* arr_of_processors, int& number_of_processors)
{
    ifstream fin(FILE_OF_PROCESSORS, ios::in); // Открыли файл для чтения
    if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            if (i < FILE_SIZE)
            {
                fin >> arr_of_processors[i].manufacturer >> arr_of_processors[i].model >> arr_of_processors[i].price;

                i++;
            }
            else
            {
                cout << "Недостаточно памяти для чтения всех данных!" << endl; break;
            }
        }
        number_of_processors = i;
    }
    fin.close(); //Закрыли файл 
}
void sortProcessorsArray(Processor* arr_of_processors, int& number_of_processors)
{
    cout << "\nВыберите:\n1)Сортировать по названию модели.\n2)Сортировать по цене.\n3)Сортировать по названию фирмы-производителя.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
            for (int i = 0; i < number_of_processors - 1; i++)
            {
                for (int j = 0; j < number_of_processors - i - 1; j++)
                {
                    if (arr_of_processors[j].model < arr_of_processors[j + 1].model)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Processor temp = arr_of_processors[j];
                        arr_of_processors[j] = arr_of_processors[j + 1];
                        arr_of_processors[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
        }
        break;
    case '2':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
            for (int i = 0; i < number_of_processors - 1; i++)
            {
                for (int j = 0; j < number_of_processors - i - 1; j++)
                {
                    if (arr_of_processors[j].price < arr_of_processors[j + 1].price)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Processor temp = arr_of_processors[j];
                        arr_of_processors[j] = arr_of_processors[j + 1];
                        arr_of_processors[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
        }
        break;
    case'3':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
            for (int i = 0; i < number_of_processors - 1; i++)
            {
                for (int j = 0; j < number_of_processors - i - 1; j++)
                {
                    if (arr_of_processors[j].manufacturer > arr_of_processors[j + 1].manufacturer)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Processor temp = arr_of_processors[j];
                        arr_of_processors[j] = arr_of_processors[j + 1];
                        arr_of_processors[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showProcessorsArray(arr_of_processors, number_of_processors);
        }
        break;
    default:
        system("cls");
    }
}
void searchProcessorsInArray(Processor* arr_of_processors, int& number_of_processors)
{
    int item = 0;
        string name_of_find_item;
        int min_of_find_price, max_of_find_price;
    system("cls");
    cout << "Выберите:\n1)Поиск по названию фирмы-производителя.\n2)Поиск по названию модели.\n3)Поиск по цене.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");
        cout << "Введите название искомой фирмы-производителя: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_processors; i++) {
           if (name_of_find_item == arr_of_processors[i].manufacturer)
           {
               item++;
           }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_processors; i++) {
                if (name_of_find_item == arr_of_processors[i].manufacturer)
                {
                    cout << arr_of_processors[i].manufacturer << " " << arr_of_processors[i].model << " " << arr_of_processors[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '2':
        system("cls");
        cout << "Введите название искомой модели: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_processors; i++) {
            if (name_of_find_item == arr_of_processors[i].model)
            {
                item++;
            }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_processors; i++) {
                if (name_of_find_item == arr_of_processors[i].model)
                {
                    cout << arr_of_processors[i].manufacturer << " " << arr_of_processors[i].model << " " << arr_of_processors[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '3':
        system("cls");
        cout << "Введите минимальную цену: ";
        cin >> min_of_find_price;
        if (min_of_find_price <= 0) 
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            searchProcessorsInArray(arr_of_processors, number_of_processors);
        }
        else 
        {
             cout << "Введите максимальную цену: ";
             cin >> max_of_find_price;
             if (max_of_find_price <= 0)
             {
                 cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
                 cin.get();
                 cin.get();
                 searchProcessorsInArray(arr_of_processors, number_of_processors);
             }
             else {
                 for (int i = 0; i < number_of_processors; i++)
                 {
                     if (min_of_find_price <= arr_of_processors[i].price && max_of_find_price >= arr_of_processors[i].price)
                     {
                         item++;
                     }
                 }
                 if (item != 0)
                 {
                     cout << "\nНайдены подходящие элементы:\n";
                     for (int i = 0; i < number_of_processors; i++) {
                         if (min_of_find_price <= arr_of_processors[i].price && max_of_find_price >= arr_of_processors[i].price)
                         {
                             cout << arr_of_processors[i].manufacturer << " " << arr_of_processors[i].model << " " << arr_of_processors[i].price << endl;
                         }
                     }
                 }
                 else {
                     cout << "\nПодходящие элементы не найдены.\n";
                 }
             }
        }
        break;
    default:
        system("cls");
    }
}
// ВИДЕОКАРТЫ
void generateVideocardsArray(Videocard* arr_of_videocards, int& number_of_videocards)
{
    number_of_videocards = 6;
    arr_of_videocards[0].manufacturer = "Nvidia";
    arr_of_videocards[0].model = "RTX3070";
    arr_of_videocards[0].price = 2105;
    arr_of_videocards[1].manufacturer = "Nvidia";
    arr_of_videocards[1].model = "RTX3060";
    arr_of_videocards[1].price = 1641;
    arr_of_videocards[2].manufacturer = "Nvidia";
    arr_of_videocards[2].model = "RTX4080";
    arr_of_videocards[2].price = 4725;
    arr_of_videocards[3].manufacturer = "Nvidia";
    arr_of_videocards[3].model = "RTX4070";
    arr_of_videocards[3].price = 3346;
    arr_of_videocards[4].manufacturer = "Nvidia";
    arr_of_videocards[4].model = "RTX3060";
    arr_of_videocards[4].price = 1278;
    arr_of_videocards[5].manufacturer = "Nvidia";
    arr_of_videocards[5].model = "RTX4090";
    arr_of_videocards[5].price = 6388;
}
void addVideocardsInArray(Videocard* arr_of_videocards, int& number_of_videocards)
{
    if (number_of_videocards + 1 <= FILE_SIZE)
    {
        cout << "Введите название фирмы производителя: ";
        cin >> arr_of_videocards[number_of_videocards - 1].manufacturer; cout << "Введите название модели: ";
        cin >> arr_of_videocards[number_of_videocards - 1].model; cout << "Введите цену: ";
        cin >> arr_of_videocards[number_of_videocards - 1].price;
        if (arr_of_videocards[number_of_videocards].price <= 0)
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            system("cls");
            addVideocardsInArray(arr_of_videocards,number_of_videocards);
        }
        else
        {

            writeEndFileVideoCards(arr_of_videocards[number_of_videocards - 1]);
        }
    }
    else cout << "Недостаточно памяти для добавления нового элемента!" << endl;
}
void delVideocardsFromArray(Videocard* arr_of_videocards, int& number_of_videocards)
{
    int number_of_deleted_item;
    cout << "Певоначальный список:\n";
    showVideocardsArray(arr_of_videocards, number_of_videocards);
    cout << "Введите номер удаляемой записи: ";
    cin >> number_of_deleted_item;
    // пользователь мыслит с 1, но индексы нумеруются с 0:
    number_of_deleted_item--;
    if (number_of_deleted_item >= 0 && number_of_deleted_item < number_of_videocards)
    {
        for (int i = number_of_deleted_item; i < number_of_videocards - 1; i++) arr_of_videocards[i] = arr_of_videocards[i + 1];

        number_of_videocards--; writeVideoCardsArrayToFile(arr_of_videocards, number_of_videocards);
    }
    else
    {
        cout << "Введен некорректный номер удалемой записи!\nНажмите Enter для повторной попытки." << endl;
        cin.get();
        cin.get();
        system("cls");
        delVideocardsFromArray(arr_of_videocards, number_of_videocards);
    }
    cout << "Удаление прошло успешно.\nНовый список:\n";
    showVideocardsArray(arr_of_videocards, number_of_videocards);
}
void showVideocardsArray(Videocard* arr_of_videocards, int number_of_videocards)
{
    for (int i = 0; i < number_of_videocards; i++) cout << arr_of_videocards[i].manufacturer << " " << arr_of_videocards[i].model << " " << arr_of_videocards[i].price << endl;
}
void writeVideoCardsArrayToFile(Videocard* arr_of_videocards, int number_of_videocards)
{
    ofstream fout(FILE_OF_VIDEOCARDS, ios::out /*ofstream::app*/); // Открыли файл для записи 
    for (int i = 0; i < number_of_videocards; i++)
    {
        fout << arr_of_videocards[i].manufacturer << " "
            << arr_of_videocards[i].model << " " << arr_of_videocards[i].price;
        if (i < number_of_videocards - 1)
        {
            fout << endl;
        }
    } fout.close();
}
void writeEndFileVideoCards(Videocard new_videocard)
{
    ofstream fadd(FILE_OF_VIDEOCARDS, ios::app); // Открыли файл для дозаписи 
    fadd << endl;
    fadd << new_videocard.manufacturer << " "
        << new_videocard.model << " " << new_videocard.price;
    fadd.close();
}
void readFileVideoCards(Videocard* arr_of_videocards, int& number_of_videocards)
{
    ifstream fin(FILE_OF_VIDEOCARDS, ios::in); // Открыли файл для чтения
    if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            if (i < FILE_SIZE)
            {
                fin >> arr_of_videocards[i].manufacturer >> arr_of_videocards[i].model >> arr_of_videocards[i].price;

                i++;
            }
            else
            {
                cout << "Недостаточно памяти для чтения всех данных!" << endl; break;
            }
        }
        number_of_videocards = i;
    }
    fin.close(); //Закрыли файл 
}
void sortVideocardsArray(Videocard* arr_of_videocards, int number_of_videocards)
{
    cout << "\nВыберите:\n1)Сортировать по названию модели.\n2)Сортировать по цене.\n3)Сортировать по названию фирмы-производителя.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
            for (int i = 0; i < number_of_videocards - 1; i++)
            {
                for (int j = 0; j < number_of_videocards - i - 1; j++)
                {
                    if (arr_of_videocards[j].model < arr_of_videocards[j + 1].model)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Videocard temp = arr_of_videocards[j];
                        arr_of_videocards[j] = arr_of_videocards[j + 1];
                        arr_of_videocards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
        }
        break;
    case '2':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
            for (int i = 0; i < number_of_videocards - 1; i++)
            {
                for (int j = 0; j < number_of_videocards - i - 1; j++)
                {
                    if (arr_of_videocards[j].price < arr_of_videocards[j + 1].price)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Videocard temp = arr_of_videocards[j];
                        arr_of_videocards[j] = arr_of_videocards[j + 1];
                        arr_of_videocards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
        }
        break;
    case'3':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
            for (int i = 0; i < number_of_videocards - 1; i++)
            {
                for (int j = 0; j < number_of_videocards - i - 1; j++)
                {
                    if (arr_of_videocards[j].manufacturer > arr_of_videocards[j + 1].manufacturer)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Videocard temp = arr_of_videocards[j];
                        arr_of_videocards[j] = arr_of_videocards[j + 1];
                        arr_of_videocards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showVideocardsArray(arr_of_videocards, number_of_videocards);
        }
        break;
    default:
        system("cls");
    }
}
void searchVideocardsInArray(Videocard* arr_of_videocards, int number_of_videocards) 
{
    int item = 0;
    string name_of_find_item;
    int min_of_find_price, max_of_find_price;
    system("cls");
    cout << "Выберите:\n1)Поиск по названию фирмы-производителя.\n2)Поиск по названию модели.\n3)Поиск по цене.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");

        cout << "Введите название искомой фирмы-производителя: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_videocards; i++) {
            if (name_of_find_item == arr_of_videocards[i].manufacturer)
            {
                item++;
            }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_videocards; i++) {
                if (name_of_find_item == arr_of_videocards[i].manufacturer)
                {
                    cout << arr_of_videocards[i].manufacturer << " " << arr_of_videocards[i].model << " " << arr_of_videocards[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '2':
        system("cls");
        cout << "Введите название искомой модели: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_videocards; i++) {
            if (name_of_find_item == arr_of_videocards[i].model)
            {
                item++;
            }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_videocards; i++) {
                if (name_of_find_item == arr_of_videocards[i].model)
                {
                    cout << arr_of_videocards[i].manufacturer << " " << arr_of_videocards[i].model << " " << arr_of_videocards[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '3':
        system("cls");
        cout << "Введите минимальную цену: ";
        cin >> min_of_find_price;
        if (min_of_find_price <= 0)
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            searchVideocardsInArray(arr_of_videocards, number_of_videocards);
        }
        else
        {
            cout << "Введите максимальную цену: ";
            cin >> max_of_find_price;
            if (max_of_find_price <= 0)
            {
                cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
                cin.get();
                cin.get();
                searchVideocardsInArray(arr_of_videocards, number_of_videocards);
            }
            else {
                for (int i = 0; i < number_of_videocards; i++)
                {
                    if (min_of_find_price <= arr_of_videocards[i].price && max_of_find_price >= arr_of_videocards[i].price)
                    {
                        item++;
                    }
                }
                if (item != 0)
                {
                    cout << "\nНайдены подходящие элементы:\n";
                    for (int i = 0; i < number_of_videocards; i++) {
                        if (min_of_find_price <= arr_of_videocards[i].price && max_of_find_price >= arr_of_videocards[i].price)
                        {
                            cout << arr_of_videocards[i].manufacturer << " " << arr_of_videocards[i].model << " " << arr_of_videocards[i].price << endl;
                        }
                    }
                }
                else {
                    cout << "\nПодходящие элементы не найдены.\n";
                }
            }
        }
        break;
    default:
        system("cls");

    }
}
// МАТЕРИНСКИЕ ПЛАТЫ
void generateMotherboardsArray(Motherboard* arr_of_motherboards, int& number_of_motherboards)
{
    number_of_motherboards = 6;
    arr_of_motherboards[0].manufacturer = "Gigabyte";
    arr_of_motherboards[0].model = "B550";
    arr_of_motherboards[0].price = 402;
    arr_of_motherboards[1].manufacturer = "ASRocker";
    arr_of_motherboards[1].model = "K660";
    arr_of_motherboards[1].price = 425;
    arr_of_motherboards[2].manufacturer = "ASRocker";
    arr_of_motherboards[2].model = "K760";
    arr_of_motherboards[2].price = 508;
    arr_of_motherboards[3].manufacturer = "Gigabyte";
    arr_of_motherboards[3].model = "B450";
    arr_of_motherboards[3].price = 198;
    arr_of_motherboards[4].manufacturer = "Gigabyte";
    arr_of_motherboards[4].model = "B660";
    arr_of_motherboards[4].price = 425;
    arr_of_motherboards[5].manufacturer = "MsiMager";
    arr_of_motherboards[5].model = "R350";
    arr_of_motherboards[5].price = 567;
}
void addMotherboardsInArray(Motherboard* arr_of_motherboards, int& number_of_motherboards) //добавление процессора, если не происходит выход за пределы массива 
{
    if (number_of_motherboards + 1 <= FILE_SIZE)
    {
        cout << "Введите название фирмы производителя: ";
        cin >> arr_of_motherboards[number_of_motherboards - 1].manufacturer; 
        cout << "Введите название модели: ";
        cin >> arr_of_motherboards[number_of_motherboards - 1].model; 
        cout << "Введите цену: ";
        cin >> arr_of_motherboards[number_of_motherboards - 1].price;
        if (arr_of_motherboards[number_of_motherboards].price <= 0) 
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            system("cls");
            addMotherboardsInArray(arr_of_motherboards, number_of_motherboards);
        }
        else 
        {
            writeEndFileMotherboards(arr_of_motherboards[number_of_motherboards - 1]);
        }

        
    }
    else cout << "Недостаточно памяти для добавления нового элемента!" << endl;
}
void delMotherboardsFromArray(Motherboard* arr_of_motherboards, int& number_of_motherboards)
{
    int number_of_deleted_item;
    cout << "Певоначальный список:\n";
    showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
    cout << "Введите номер удаляемой записи: ";
    cin >> number_of_deleted_item;
    // пользователь мыслит с 1, но индексы нумеруются с 0:
    number_of_deleted_item--;
    if (number_of_deleted_item >= 0 && number_of_deleted_item < number_of_motherboards)
    {
        for (int i = number_of_deleted_item; i < number_of_motherboards - 1; i++) arr_of_motherboards[i] = arr_of_motherboards[i + 1];

        number_of_motherboards--; writeMotherboardsArrayToFile(arr_of_motherboards, number_of_motherboards);
    }
    else
    {
        cout << "Введен некорректный номер удалемой записи!\nНажмите Enter для повторной попытки." << endl;
        cin.get();
        cin.get();
        system("cls");
        delMotherboardsFromArray(arr_of_motherboards, number_of_motherboards);
    }
    cout << "Удаление прошло успешно.\nНовый список:\n";
    showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
}
void showMotherboardsArray(Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    for (int i = 0; i < number_of_motherboards; i++) cout << arr_of_motherboards[i].manufacturer << " " << arr_of_motherboards[i].model << " " << arr_of_motherboards[i].price << endl;
}
void writeMotherboardsArrayToFile(Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    ofstream fout(FILE_OF_MOTHERBOARDS, ios::out /*ofstream::app*/); // Открыли файл для записи 
    for (int i = 0; i < number_of_motherboards; i++)
    {
        fout << arr_of_motherboards[i].manufacturer << " "
            << arr_of_motherboards[i].model << " " << arr_of_motherboards[i].price;
        if (i < number_of_motherboards - 1)
        {
            fout << endl;
        }
    } fout.close();
}
void writeEndFileMotherboards(Motherboard new_motherboard)
{
    ofstream fadd(FILE_OF_MOTHERBOARDS, ios::app); // Открыли файл для дозаписи 
    fadd << endl;
    fadd << new_motherboard.manufacturer << " "
        << new_motherboard.model << " " << new_motherboard.price;
    fadd.close();
}
void readFileMotherboards(Motherboard* arr_of_motherboards, int& number_of_motherboards)
{
    ifstream fin(FILE_OF_MOTHERBOARDS, ios::in); // Открыли файл для чтения
    if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            if (i < FILE_SIZE)
            {
                fin >> arr_of_motherboards[i].manufacturer >> arr_of_motherboards[i].model >> arr_of_motherboards[i].price;

                i++;
            }
            else
            {
                cout << "Недостаточно памяти для чтения всех данных!" << endl; break;
            }
        }
        number_of_motherboards = i;
    }
    fin.close(); //Закрыли файл 
}
void sortMotherboardsArray(Motherboard* arr_of_motherboards, int number_of_motherboards)
{
    cout << "\nВыберите:\n1)Сортировать по названию модели.\n2)Сортировать по цене.\n3)Сортировать по названию фирмы-производителя.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
            for (int i = 0; i < number_of_motherboards - 1; i++)
            {
                for (int j = 0; j < number_of_motherboards - i - 1; j++)
                {
                    if (arr_of_motherboards[j].model < arr_of_motherboards[j + 1].model)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Motherboard temp = arr_of_motherboards[j];
                        arr_of_motherboards[j] = arr_of_motherboards[j + 1];
                        arr_of_motherboards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
        }
        break;
    case '2':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
            for (int i = 0; i < number_of_motherboards - 1; i++)
            {
                for (int j = 0; j < number_of_motherboards - i - 1; j++)
                {
                    if (arr_of_motherboards[j].price < arr_of_motherboards[j + 1].price)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Motherboard temp = arr_of_motherboards[j];
                        arr_of_motherboards[j] = arr_of_motherboards[j + 1];
                        arr_of_motherboards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
        }
        break;
    case'3':
        system("cls");
        {
            cout << "\nПервоначальный список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
            for (int i = 0; i < number_of_motherboards - 1; i++)
            {
                for (int j = 0; j < number_of_motherboards - i - 1; j++)
                {
                    if (arr_of_motherboards[j].manufacturer > arr_of_motherboards[j + 1].manufacturer)
                    {
                        // Меняем местами элементы в паре (arr[j], arr[j+1])
                        Motherboard temp = arr_of_motherboards[j];
                        arr_of_motherboards[j] = arr_of_motherboards[j + 1];
                        arr_of_motherboards[j + 1] = temp;
                    }
                }
            }
            cout << "\nНовый список:\n";
            showMotherboardsArray(arr_of_motherboards, number_of_motherboards);
        }
        break;
    default:
        system("cls");
    }
}
void searchMotherboardsInArray(Motherboard* arr_of_motherboards, int number_of_motherboards) 
{
    int item = 0;
    string name_of_find_item;
    int min_of_find_price, max_of_find_price;
    system("cls");
    cout << "Выберите:\n1)Поиск по названию фирмы-производителя.\n2)Поиск по названию модели.\n3)Поиск по цене.\n4)Назад.";
    switch (_getch())
    {
    case '1':
        system("cls");

        cout << "Введите название искомой фирмы-производителя: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_motherboards; i++) {
            if (name_of_find_item == arr_of_motherboards[i].manufacturer)
            {
                item++;
            }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_motherboards; i++) {
                if (name_of_find_item == arr_of_motherboards[i].manufacturer)
                {
                    cout << arr_of_motherboards[i].manufacturer << " " << arr_of_motherboards[i].model << " " << arr_of_motherboards[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '2':
        system("cls");
        cout << "Введите название искомой модели: ";
        cin >> name_of_find_item;
        for (int i = 0; i < number_of_motherboards; i++) {
            if (name_of_find_item == arr_of_motherboards[i].model)
            {
                item++;
            }
        }
        if (item != 0)
        {
            cout << "\nНайдены подходящие элементы:\n";
            for (int i = 0; i < number_of_motherboards; i++) {
                if (name_of_find_item == arr_of_motherboards[i].model)
                {
                    cout << arr_of_motherboards[i].manufacturer << " " << arr_of_motherboards[i].model << " " << arr_of_motherboards[i].price << endl;
                }
            }
        }
        else {
            cout << "\nПодходящие элементы не найдены.\n";
        }
        break;
    case '3':
        system("cls");
        cout << "Введите минимальную цену: ";
        cin >> min_of_find_price;
        if (min_of_find_price <= 0)
        {
            cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
            cin.get();
            cin.get();
            searchMotherboardsInArray(arr_of_motherboards,number_of_motherboards);
        }
        else
        {
            cout << "Введите максимальную цену: ";
            cin >> max_of_find_price;
            if (max_of_find_price <= 0)
            {
                cout << "\nОшибка!\nВведено недопустимое значение.\nНажмите Enter для повторной попытки.";
                cin.get();
                cin.get();
                searchMotherboardsInArray(arr_of_motherboards, number_of_motherboards);
            }
            else {
                for (int i = 0; i < number_of_motherboards; i++)
                {
                    if (min_of_find_price <= arr_of_motherboards[i].price && max_of_find_price >= arr_of_motherboards[i].price)
                    {
                        item++;
                    }
                }
                if (item != 0)
                {
                    cout << "\nНайдены подходящие элементы:\n";
                    for (int i = 0; i < number_of_motherboards; i++) {
                        if (min_of_find_price <= arr_of_motherboards[i].price && max_of_find_price >= arr_of_motherboards[i].price)
                        {
                            cout << arr_of_motherboards[i].manufacturer << " " << arr_of_motherboards[i].model << " " << arr_of_motherboards[i].price << endl;
                        }
                    }
                }
                else {
                    cout << "\nПодходящие элементы не найдены.\n";
                }
            }
        }
        break;
    default:
        system("cls");

    }
}