#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Adresat
{
    int id, userIdent;
    string imie, nazwisko, telefon, mail, adres;
};
struct User
{
    int identyficationNr;
    string login, password;
};

void DodajNowyKontakt(vector <Adresat> &nowy, int id, int userIdd)
{
    fstream book;
    int idIterator;
    Adresat person;
    string imie, nazwisko, telefon, mail, adres;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj telefon: ";
    cin.sync();
    getline(cin, telefon);
    cout<<"Podaj mail: ";
    cin>>mail;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    if(nowy.size()==0)
    {
        idIterator=0;
    }
    else
    {
        idIterator=nowy[nowy.size()-1].id;
    }

    person.id = idIterator+1;
    person.userIdent = userIdd;
    person.imie = imie;
    person.nazwisko = nazwisko;
    person.telefon = telefon;
    person.mail = mail;
    person.adres = adres;

    nowy.push_back(person);

    book.open("AdressBook.txt",ios::out | ios::app);
    book<<nowy[nowy.size()-1].id<<"|";
    book<<nowy[nowy.size()-1].userIdent<<"|";
    book<<nowy[nowy.size()-1].imie<<"|";
    book<<nowy[nowy.size()-1].nazwisko<<"|";
    book<<nowy[nowy.size()-1].telefon<<"|";
    book<<nowy[nowy.size()-1].mail<<"|";
    book<<nowy[nowy.size()-1].adres<<"|"<<endl;
    book.close();

    cout<<"Nowy kontakt dodano pomyslnie.";
    Sleep(1500);
}

void SzukajImion (vector <Adresat> &lista, int userID)
{
    string imie;
    int countShow=0;
    cout<<"Podaj imie: ";
    cin>>imie;

    for(int i=0; i<lista.size(); i++)
    {
        if (lista[i].imie == imie && lista[i].userIdent==userID)
        {
            countShow++;
            cout<<lista[i].id<<". ";
            cout<<lista[i].imie<<" "<<lista[i].nazwisko<<endl;
            cout<<"Tel. "<<lista[i].telefon<<endl<<"Adres e-mail: "<<lista[i].mail<<endl<<"Adres zamieszkania: "<<lista[i].adres<<endl<<endl;
        }
    }
    if(countShow == 0)
    {
        cout<<"Nie ma takiego imienia w twojej ksiazce."<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}
void SzukajNazwisk (vector <Adresat> &lista, int userID)
{
    string nazwisko;
    int countShow=0;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;

    for(int i=0; i<lista.size(); i++)
    {
        if (lista[i].nazwisko == nazwisko && lista[i].userIdent==userID)
        {
            countShow++;
            cout<<lista[i].id<<". ";
            cout<<lista[i].imie<<" "<<lista[i].nazwisko<<endl;
            cout<<"Tel. "<<lista[i].telefon<<endl<<"Adres e-mail: "<<lista[i].mail<<endl<<"Adres zamieszkania: "<<lista[i].adres<<endl<<endl;
        }
    }
    if(countShow == 0)
    {
        cout<<"Nie ma takiego nazwiska w twojej ksiazce."<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}
void WyswietlWszystkie (vector <Adresat> &lista, int userIddd)
{
    int countShow=0;
    for(int i=0; i<lista.size(); i++)
    {
        if(lista[i].userIdent==userIddd)
        {
            countShow++;
            cout<<lista[i].id<<". ";
            cout<<lista[i].imie<<" "<<lista[i].nazwisko<<endl;
            cout<<"Tel. "<<lista[i].telefon<<endl<<"Adres e-mail: "<<lista[i].mail<<endl<<"Adres zamieszkania: "<<lista[i].adres<<endl<<endl;
        }
    }
    if (countShow == 0)
    {
        cout<<"Twoja ksiazka adresowa jest przeciez pusta gluptasie ;)"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}

void usuwanieAdresata (vector <Adresat> &nowy, int userID)
{
    fstream boook, temporaryBook;
    string name;
    string liniaWczytujacaPliku;
    Adresat person;
    int identification=0;
    int countShow=0;
    char answer;
    cout<<"Podaj ID adresata:";
    cin>>identification;
    for(int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==identification && nowy[i].userIdent==userID)
        {
            countShow++;
            cout<<nowy[i].id<<". ";
            cout<<nowy[i].imie<<" "<<nowy[i].nazwisko<<endl;
            cout<<"Tel. "<<nowy[i].telefon<<endl<<"Adres e-mail: "<<nowy[i].mail<<endl<<"Adres zamieszkania: "<<nowy[i].adres<<endl<<endl;
            cout<<"Czy na pewno chcesz go usunac? Wcisnij -t- na tak, lub -n- na nie."<<endl;
        }
    }
    answer=getch();
    if(answer=='t')
    {
        boook.open("AdressBook.txt",ios::in);
        temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

        while(!boook.eof())
        {
            getline(boook,liniaWczytujacaPliku);
            if(!boook.eof())
            {
                string nrID, nrUserID, item;
                stringstream ss (liniaWczytujacaPliku);
                vector <string> subsidiaryVector(0);
                while (getline(ss, item, '|'))
                {
                    subsidiaryVector.push_back(item);
                }
                vector <string>::iterator itr = subsidiaryVector.begin();
                nrID = *itr;
                person.id = atoi(nrID.c_str());
                itr++;
                nrUserID = *itr;
                person.userIdent = atoi(nrUserID.c_str());
                itr++;
                person.imie = *itr;
                itr++;
                person.nazwisko = *itr;
                itr++;
                person.telefon = *itr;
                itr++;
                person.mail = *itr;
                itr++;
                person.adres = *itr;

                if (person.id==identification && person.userIdent==userID)
                {

                }
                else
                {
                    temporaryBook<<person.id<<"|";
                    temporaryBook<<person.userIdent<<"|";
                    temporaryBook<<person.imie<<"|";
                    temporaryBook<<person.nazwisko<<"|";
                    temporaryBook<<person.telefon<<"|";
                    temporaryBook<<person.mail<<"|";
                    temporaryBook<<person.adres<<"|"<<endl;
                }
                subsidiaryVector.clear();
            }
            else
            {
                boook.close();
                remove("AdressBook.txt");
                temporaryBook.close();
                rename("TemporaryAdressBook.txt", "AdressBook.txt");
                break;
            }
        }
    }

    if (countShow == 0)
    {
        cout<<"Cos ci sie pomylilo. Nie ma takiego adresata w twojej ksiazce."<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}

void changingPassword(vector <User> &userss, int userId)
{
    fstream boook, temporaryBook;
    string oldPass, newPass;
    string liniaWczytujacaPliku;
    User someUser;

    cout<<"Wpisz stare haslo:"<<endl;
    cin>>oldPass;
    cout<<"Wpisz stare haslo:"<<endl;
    cin>>newPass;


    if(oldPass==userss[userId-1].password)
    {
        boook.open("Users.txt",ios::in);
        temporaryBook.open("TemporaryUsers.txt",ios::out | ios::app);

        while(!boook.eof())
        {
            getline(boook,liniaWczytujacaPliku);
            if(!boook.eof())
            {
                string nrUserID, item;
                stringstream ss (liniaWczytujacaPliku);
                vector <string> subsidiaryVector(0);
                while (getline(ss, item, '|'))
                {
                    subsidiaryVector.push_back(item);
                }
                vector <string>::iterator itr = subsidiaryVector.begin();

                nrUserID = *itr;
                someUser.identyficationNr = atoi(nrUserID.c_str());
                itr++;
                someUser.login = *itr;
                itr++;
                someUser.password = *itr;

                if (someUser.identyficationNr==userId)
                {
                    temporaryBook<<someUser.identyficationNr<<"|";
                    temporaryBook<<someUser.login<<"|";
                    temporaryBook<<newPass<<"|"<<endl;
                }
                else
                {
                    temporaryBook<<someUser.identyficationNr<<"|";
                    temporaryBook<<someUser.login<<"|";
                    temporaryBook<<someUser.password<<"|"<<endl;
                }
                subsidiaryVector.clear();
            }
            else
            {
                boook.close();
                remove("Users.txt");
                temporaryBook.close();
                rename("TemporaryUsers.txt", "Users.txt");
                break;
            }
        }
        cout<<"Halo zostalo zaktualizowane."<<endl;
        Sleep(1500);
    }
    else
    {
        cout<<"Podano blednie stare haslo. Haslo nie uleglo zmianie."<<endl;
        Sleep(1500);
    }
}

void changingName(int personalID, int userID)
{
    fstream boook, temporaryBook;
    string name;
    string liniaWczytujacaPliku;
    Adresat person;

    cout<<"Na jakie zmieniamy?"<<endl;
    cin>>name;

    boook.open("AdressBook.txt",ios::in);
    temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

    while(!boook.eof())
    {
        getline(boook,liniaWczytujacaPliku);
        if(!boook.eof())
        {
            string nrID, nrUserID, item;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;

            if (person.id==personalID && person.userIdent==userID)
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<name<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            else
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            subsidiaryVector.clear();
        }
        else
        {
            boook.close();
            remove("AdressBook.txt");
            temporaryBook.close();
            rename("TemporaryAdressBook.txt", "AdressBook.txt");
            break;
        }
    }
}
void changingSurname(int personalID, int userID)
{
    fstream boook, temporaryBook;
    string surname;
    string liniaWczytujacaPliku;
    Adresat person;

    cout<<"Na jakie zmieniamy?"<<endl;
    cin>>surname;

    boook.open("AdressBook.txt",ios::in);
    temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

    while(!boook.eof())
    {
        getline(boook,liniaWczytujacaPliku);
        if(!boook.eof())
        {
            string nrID, nrUserID, item;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;

            if (person.id==personalID && person.userIdent==userID)
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<surname<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            else
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            subsidiaryVector.clear();
        }
        else
        {
            boook.close();
            remove("AdressBook.txt");
            temporaryBook.close();
            rename("TemporaryAdressBook.txt", "AdressBook.txt");
            break;
        }
    }
}

void changingNumber(int personalID, int userID)
{
    fstream boook, temporaryBook;
    string number;
    string liniaWczytujacaPliku;
    Adresat person;

    cout<<"Na jaki zmieniamy?"<<endl;
    cin.sync();
    getline(cin, number);

    boook.open("AdressBook.txt",ios::in);
    temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

    while(!boook.eof())
    {
        getline(boook,liniaWczytujacaPliku);
        if(!boook.eof())
        {
            string nrID, nrUserID, item;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;

            if (person.id==personalID && person.userIdent==userID)
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<number<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            else
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            subsidiaryVector.clear();
        }
        else
        {
            boook.close();
            remove("AdressBook.txt");
            temporaryBook.close();
            rename("TemporaryAdressBook.txt", "AdressBook.txt");
            break;
        }
    }
}
void changingEmail(int personalID, int userID)
{
    fstream boook, temporaryBook;
    string email;
    string liniaWczytujacaPliku;
    Adresat person;

    cout<<"Na jakie zmieniamy?"<<endl;
    cin>>email;

    boook.open("AdressBook.txt",ios::in);
    temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

    while(!boook.eof())
    {
        getline(boook,liniaWczytujacaPliku);
        if(!boook.eof())
        {
            string nrID, nrUserID, item;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;

            if (person.id==personalID && person.userIdent==userID)
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<email<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            else
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            subsidiaryVector.clear();
        }
        else
        {
            boook.close();
            remove("AdressBook.txt");
            temporaryBook.close();
            rename("TemporaryAdressBook.txt", "AdressBook.txt");
            break;
        }
    }
}
void changingAdress(int personalID, int userID)
{
    fstream boook, temporaryBook;
    string adress;
    string liniaWczytujacaPliku;
    Adresat person;

    cout<<"Na jakie zmieniamy?"<<endl;
    cin.sync();
    getline(cin, adress);

    boook.open("AdressBook.txt",ios::in);
    temporaryBook.open("TemporaryAdressBook.txt",ios::out | ios::app);

    while(!boook.eof())
    {
        getline(boook,liniaWczytujacaPliku);
        if(!boook.eof())
        {
            string nrID, nrUserID, item;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;

            if (person.id==personalID && person.userIdent==userID)
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<adress<<"|"<<endl;
            }
            else
            {
                temporaryBook<<person.id<<"|";
                temporaryBook<<person.userIdent<<"|";
                temporaryBook<<person.imie<<"|";
                temporaryBook<<person.nazwisko<<"|";
                temporaryBook<<person.telefon<<"|";
                temporaryBook<<person.mail<<"|";
                temporaryBook<<person.adres<<"|"<<endl;
            }
            subsidiaryVector.clear();
        }
        else
        {
            boook.close();
            remove("AdressBook.txt");
            temporaryBook.close();
            rename("TemporaryAdressBook.txt", "AdressBook.txt");
            break;
        }
    }
}

void registration (vector <User> &users)
{
    fstream data;
    string login, haslo;
    User newPerson;
    cout<<"Wprowadz swoj nowy login:"<<endl;
    cin>>login;
    cout<<"Wprowadz swoje nowe haslo:"<<endl;
    cin>>haslo;

    newPerson.identyficationNr=users.size()+1;
    newPerson.login=login;
    newPerson.password=haslo;

    users.push_back(newPerson);

    data.open("Users.txt",ios::out | ios::app);
    data<<users[users.size()-1].identyficationNr<<"|";
    data<<users[users.size()-1].login<<"|";
    data<<users[users.size()-1].password<<endl;
    data.close();
    cout<<"Nowego uzytkownika dodano pomyslnie.";
    Sleep(1500);
}

int logging(vector <User> &users)
{
    int idUsers = 0;
    string login, haslo;
    cout<<"Wprowadz swoj login:"<<endl;
    cin>>login;
    cout<<"Wprowadz swoje nowe haslo:"<<endl;
    cin>>haslo;
    for(int i=0; i<users.size(); i++)
    {
        if (users[i].login==login && users[i].password==haslo)
        {
            idUsers=users[i].identyficationNr;
            cout<<"Zalogowales sie poprawnie."<<endl;
            Sleep(1500);
            return idUsers;
        }
    }
    cout<<"Bledny login lub haslo."<<endl<<"Sprobuj ponownie"<<endl;
    Sleep(1500);
    return idUsers=0;
}

void loadingUsers (vector <User> &users)
{
    string liniaWczytujacaPliku;
    fstream file;
    string item;
    User person;

    file.open("Users.txt",ios::in);
    if(file.good() == false)
    {
        file.open("Users.txt",ios::out | ios::app);
    }
    while(!file.eof())
    {
        getline(file,liniaWczytujacaPliku);
        if(!file.eof())
        {
            string nrID;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
                cout<<item;
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.identyficationNr = atoi(nrID.c_str());
            itr++;
            person.login = *itr;
            itr++;
            person.password = *itr;
            users.push_back(person);
            subsidiaryVector.clear();
        }
        else
        {
            file.close();
            break;
        }
    }
    file.close();
}

void loadingAdressBook (vector <Adresat> &adresaci, int userID)
{
    string liniaWczytujacaPliku;
    fstream book;
    string item;
    Adresat person;

    book.open("AdressBook.txt",ios::in);
    if(book.good() == false)
    {
        book.open("AdressBook.txt",ios::out | ios::app);
    }
    while(!book.eof())
    {
        getline(book,liniaWczytujacaPliku);
        if(!book.eof())
        {
            string nrID, nrUserID;
            stringstream ss (liniaWczytujacaPliku);
            vector <string> subsidiaryVector(0);
            while (getline(ss, item, '|'))
            {
                subsidiaryVector.push_back(item);
                cout<<item;
            }
            vector <string>::iterator itr = subsidiaryVector.begin();
            nrID = *itr;
            person.id = atoi(nrID.c_str());
            itr++;
            nrUserID = *itr;
            person.userIdent = atoi(nrUserID.c_str());
            itr++;
            person.imie = *itr;
            itr++;
            person.nazwisko = *itr;
            itr++;
            person.telefon = *itr;
            itr++;
            person.mail = *itr;
            itr++;
            person.adres = *itr;
            if(person.userIdent==userID)
            {
                adresaci.push_back(person);
            }
            subsidiaryVector.clear();
        }
        else
        {
            book.close();
            break;
        }
    }
    book.close();
}

int main()
{
    vector <Adresat> adresaci(0);
    vector <User> users(0);
    int idPrzyjaciela = 0;
    int userId = 0;
    char wyborMenuGlownego, firstMenuChoose;
    char wyborMenuSzukaj;
    int editingID;
    int numberOfcounts = 0;

    loadingUsers(users);
    while(1)
    {
        system("cls");
        cout<<"1. Logowanie."<<endl;
        cout<<"2. Rejestracja."<<endl;
        cout<<"9. Zakoncz program."<<endl;
        cin>>firstMenuChoose;
        if (firstMenuChoose =='1')
        {
            userId=logging(users);
            loadingAdressBook(adresaci, userId);
            while(1)
            {
                if(userId>0)
                {
                    system("cls");
                    cout<<"1. Dodaj adresata."<<endl;
                    cout<<"2. Wyszukaj po imieniu."<<endl;
                    cout<<"3. Wyszukaj po nazwisku."<<endl;
                    cout<<"4. Wyswietl wsyzstkich adresatow."<<endl;
                    cout<<"5. Usun adresata."<<endl;
                    cout<<"6. Edytuj adresata."<<endl;
                    cout<<"7. Zmien haslo."<<endl;
                    cout<<"9. Wyloguj sie."<<endl;
                    cin>>wyborMenuGlownego;

                    if (wyborMenuGlownego =='1')
                    {
                        DodajNowyKontakt(adresaci,idPrzyjaciela, userId);
                    }
                    else if (wyborMenuGlownego == '2')
                    {
                        SzukajImion(adresaci, userId);
                    }
                    else if (wyborMenuGlownego == '3')
                    {
                        SzukajNazwisk(adresaci, userId);
                    }
                    else if (wyborMenuGlownego == '4')
                    {
                        WyswietlWszystkie(adresaci, userId);
                    }
                    else if (wyborMenuGlownego == '5')
                    {
                        usuwanieAdresata(adresaci, userId);
                    }
                    else if (wyborMenuGlownego == '6')
                    {
                        system("cls");
                        cout<<"Wpisz ID."<<endl;
                        cin>>editingID;
                        system("cls");
                        for (int i=0; i<adresaci.size(); i++)
                        {
                            if(adresaci[i].id==editingID)
                            {
                                numberOfcounts++;
                                cout<<adresaci[i].id<<". ";
                                cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
                                cout<<"Tel. "<<adresaci[i].telefon<<endl<<"Adres e-mail: "<<adresaci[i].mail<<endl<<"Adres zamieszkania: "<<adresaci[i].adres<<endl<<endl;

                                cout<<"Co zmieniamy?"<<endl;
                                cout<<"1 - imie"<<endl;
                                cout<<"2 - nazwisko"<<endl;
                                cout<<"3 - numer telefonu"<<endl;
                                cout<<"4 - email"<<endl;
                                cout<<"5 - adres"<<endl;
                                cout<<"6 - powrot do menu"<<endl;
                                cin>>wyborMenuSzukaj;
                                switch (wyborMenuSzukaj)
                                {
                                case '1':
                                {
                                    changingName(editingID, userId);
                                }
                                break;
                                case '2':
                                {
                                    changingSurname(editingID, userId);
                                }
                                break;
                                case '3':
                                {
                                    changingNumber(editingID, userId);
                                }
                                break;
                                case '4':
                                {
                                    changingEmail(editingID, userId);
                                }
                                break;
                                case '5':
                                {
                                    changingAdress(editingID, userId);
                                }
                                break;
                                case '6':
                                    break;
                                }
                            }
                        }
                        if (numberOfcounts==0)
                        {
                            cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
                            cout<<"Wcisnij klawisz by wrocic do menu glownego.";
                            getch();
                        }
                        numberOfcounts=0;
                    }
                    else if (wyborMenuGlownego == '7')
                    {
                        changingPassword(users, userId);
                        users.clear();
                        loadingUsers(users);
                    }
                    else if (wyborMenuGlownego == '9')
                    {
                        break;
                    }
                }

            }

        }
        else if (firstMenuChoose == '2')
        {
            registration(users);
        }
        else if (firstMenuChoose == '9')
        {
            exit(0);
        }
        adresaci.clear();
    }

    return 0;
}




