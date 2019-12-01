#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Adresat
{
    int id;
    string imie, nazwisko, telefon, mail, adres;
};

void DodajNowyKontakt(int iloscKontaktow, vector <Adresat> &nowy, int id)
{

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
    person.imie = imie;
    person.nazwisko = nazwisko;
    person.telefon = telefon;
    person.mail = mail;
    person.adres = adres;

    nowy.push_back(person);

    book.open("AdressBook.txt",ios::out | ios::app);
    book<<nowy[iloscKontaktow].id<<"|";
    book<<nowy[iloscKontaktow].imie<<"|";
    book<<nowy[iloscKontaktow].nazwisko<<"|";
    book<<nowy[iloscKontaktow].telefon<<"|";
    book<<nowy[iloscKontaktow].mail<<"|";
    book<<nowy[iloscKontaktow].adres<<"|"<<endl;
    book.close();
    cout<<"Nowy kontakt dodano pomyslnie.";
    Sleep(1500);
}

void SzukajImion (vector <Adresat> &lista)
{
    string imie;
    int countShow=0;
    cout<<"Podaj imie: ";
    cin>>imie;

    for(int i=0; i<lista.size(); i++)
    {
        if (lista[i].imie == imie)
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
void SzukajNazwisk (vector <Adresat> &lista)
{
    string nazwisko;
    int countShow=0;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;

    for(int i=0; i<lista.size(); i++)
    {
        if (lista[i].nazwisko == nazwisko)
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
void WyswietlWszystkie (vector <Adresat> &lista)
{
    int countShow=0;
    for(int i=0; i<lista.size(); i++)
    {
        countShow++;
        cout<<lista[i].id<<". ";
        cout<<lista[i].imie<<" "<<lista[i].nazwisko<<endl;
        cout<<"Tel. "<<lista[i].telefon<<endl<<"Adres e-mail: "<<lista[i].mail<<endl<<"Adres zamieszkania: "<<lista[i].adres<<endl<<endl;
    }
    if (countShow == 0)
    {
        cout<<"Twoja ksiazka adresowa jest przeciez pusta gluptasie ;)"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}

void usuwanieAdresata (vector <Adresat> &nowy, fstream &boook)
{
    int identification=0;
    int countShow=0;
    char answer;
    cout<<"Podaj ID adresata:";
    cin>>identification;

    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==identification)
        {
            countShow++;
            cout<<nowy[i].id<<". ";
            cout<<nowy[i].imie<<" "<<nowy[i].nazwisko<<endl;
            cout<<"Tel. "<<nowy[i].telefon<<endl<<"Adres e-mail: "<<nowy[i].mail<<endl<<"Adres zamieszkania: "<<nowy[i].adres<<endl;
            cout<<"Czy na pewno chcesz go usunac? Wcisnij -t- na tak, lub -n- na nie."<<endl;
            answer=getch();
            if(answer=='t')
            {
                nowy.erase(nowy.begin()+i);

                remove("AdressBook.txt");
                boook.open("AdressBook.txt",ios::out | ios::app);
                for (int j=0; j<nowy.size(); j++)
                {
                    boook<<nowy[j].id<<"|";
                    boook<<nowy[j].imie<<"|";
                    boook<<nowy[j].nazwisko<<"|";
                    boook<<nowy[j].telefon<<"|";
                    boook<<nowy[j].mail<<"|";
                    boook<<nowy[j].adres<<"|"<<endl;
                }
                boook.close();
            }
            else
            {
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

void changingName(vector <Adresat> &nowy, int personalID, fstream &boook)
{
    int countShow=0;
    string name;
    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==personalID)
        {
            countShow++;
            cout<<"Na jakie zmieniamy?"<<endl;
            cin>>name;
            nowy[i].imie=name;
            remove("AdressBook.txt");
            boook.open("AdressBook.txt",ios::out | ios::app);
            for (int j=0; j<nowy.size(); j++)
            {
                boook<<nowy[j].id<<"|";
                boook<<nowy[j].imie<<"|";
                boook<<nowy[j].nazwisko<<"|";
                boook<<nowy[j].telefon<<"|";
                boook<<nowy[j].mail<<"|";
                boook<<nowy[j].adres<<"|"<<endl;
            }
            boook.close();

        }
    }
    if (countShow == 0)
    {
        cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}
void changingSurname(vector <Adresat> &nowy, int personalID, fstream &boook)
{
    int countShow=0;
    string surname;
    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==personalID)
        {
            countShow++;
            cout<<"Na jakie zmieniamy?"<<endl;
            cin>>surname;
            nowy[i].nazwisko=surname;
            remove("AdressBook.txt");
            boook.open("AdressBook.txt",ios::out | ios::app);
            for (int j=0; j<nowy.size(); j++)
            {
                boook<<nowy[j].id<<"|";
                boook<<nowy[j].imie<<"|";
                boook<<nowy[j].nazwisko<<"|";
                boook<<nowy[j].telefon<<"|";
                boook<<nowy[j].mail<<"|";
                boook<<nowy[j].adres<<"|"<<endl;
            }
            boook.close();

        }
    }
    if (countShow == 0)
    {
        cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}

void changingNumber(vector <Adresat> &nowy, int personalID, fstream &boook)
{
    int countShow=0;
    string number;
    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==personalID)
        {
            countShow++;
            cout<<"Na jaki zmieniamy?"<<endl;
            cin.sync();
            getline(cin, number);
            nowy[i].telefon=number;
            remove("AdressBook.txt");
            boook.open("AdressBook.txt",ios::out | ios::app);
            for (int j=0; j<nowy.size(); j++)
            {
                boook<<nowy[j].id<<"|";
                boook<<nowy[j].imie<<"|";
                boook<<nowy[j].nazwisko<<"|";
                boook<<nowy[j].telefon<<"|";
                boook<<nowy[j].mail<<"|";
                boook<<nowy[j].adres<<"|"<<endl;
            }
            boook.close();

        }
    }
    if (countShow == 0)
    {
        cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}
void changingEmail(vector <Adresat> &nowy, int personalID, fstream &boook)
{
    int countShow=0;
    string email;
    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==personalID)
        {
            countShow++;
            cout<<"Na jaki zmieniamy?"<<endl;
            cin>>email;
            nowy[i].mail=email;
            remove("AdressBook.txt");
            boook.open("AdressBook.txt",ios::out | ios::app);
            for (int j=0; j<nowy.size(); j++)
            {
                boook<<nowy[j].id<<"|";
                boook<<nowy[j].imie<<"|";
                boook<<nowy[j].nazwisko<<"|";
                boook<<nowy[j].telefon<<"|";
                boook<<nowy[j].mail<<"|";
                boook<<nowy[j].adres<<"|"<<endl;
            }
            boook.close();

        }
    }
    if (countShow == 0)
    {
        cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}
void changingAdress(vector <Adresat> &nowy, int personalID, fstream &boook)
{
    int countShow=0;
    string address;
    for (int i=0; i<nowy.size(); i++)
    {
        if(nowy[i].id==personalID)
        {
            countShow++;
            cout<<"Na jaki zmieniamy?"<<endl;
            cin.sync();
            getline(cin, address);
            nowy[i].adres=address;
            remove("AdressBook.txt");
            boook.open("AdressBook.txt",ios::out | ios::app);
            for (int j=0; j<nowy.size(); j++)
            {
                boook<<nowy[j].id<<"|";
                boook<<nowy[j].imie<<"|";
                boook<<nowy[j].nazwisko<<"|";
                boook<<nowy[j].telefon<<"|";
                boook<<nowy[j].mail<<"|";
                boook<<nowy[j].adres<<"|"<<endl;
            }
            boook.close();

        }
    }
    if (countShow == 0)
    {
        cout<<"Ups. Cos poszlo nie tak. Czy jestes pewien, ze wprowadziles poprawne ID?"<<endl;
    }
    cout<<"Wcisnij klawisz by wrocic do menu glownego.";
    getch();
}

int main()
{
    vector <Adresat> adresaci(0);
    int idPrzyjaciela = 0;
    int iloscOsobWksiazceAdresowejPrzyjaciol = 0;
    char wyborMenuGlownego;
    char wyborMenuSzukaj;
    int editingID;
    string item;
    string liniaWczytujacaPliku;
    fstream book;
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
            person.id = atoi(nrID.c_str());
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

            adresaci.push_back(person);
            iloscOsobWksiazceAdresowejPrzyjaciol++;
            subsidiaryVector.clear();
        }
        else
        {
            book.close();
            break;
        }
    }
    book.close();
    while(1)
    {
        system("cls");
        cout<<"1. Dodaj adresata."<<endl;
        cout<<"2. Wyszukaj po imieniu."<<endl;
        cout<<"3. Wyszukaj po nazwisku."<<endl;
        cout<<"4. Wyswietl wsyzstkich adresatow."<<endl;
        cout<<"5. Usun adresata."<<endl;
        cout<<"6. Edytuj adresata."<<endl;
        cout<<"9. Zakoncz program."<<endl;
        cin>>wyborMenuGlownego;

        if (wyborMenuGlownego =='1')
        {
            DodajNowyKontakt(iloscOsobWksiazceAdresowejPrzyjaciol,adresaci,idPrzyjaciela);
            iloscOsobWksiazceAdresowejPrzyjaciol++;
        }
        else if (wyborMenuGlownego == '2')
        {
            SzukajImion(adresaci);
        }
        else if (wyborMenuGlownego == '3')
        {
            SzukajNazwisk(adresaci);
        }
        else if (wyborMenuGlownego == '4')
        {
            WyswietlWszystkie(adresaci);
        }
        else if (wyborMenuGlownego == '5')
        {
            system("cls");
            usuwanieAdresata(adresaci,book);
            iloscOsobWksiazceAdresowejPrzyjaciol--;
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
                    cout<<adresaci[i].id<<". ";
                    cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
                    cout<<"Tel. "<<adresaci[i].telefon<<endl<<"Adres e-mail: "<<adresaci[i].mail<<endl<<"Adres zamieszkania: "<<adresaci[i].adres<<endl<<endl;
                }
            }
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
                changingName(adresaci, editingID,book);
            }
            break;
            case '2':
            {
                changingSurname(adresaci, editingID,book);
            }
            break;
            case '3':
            {
                changingNumber(adresaci, editingID,book);
            }
            break;
            case '4':
            {
                changingEmail(adresaci, editingID,book);
            }
            break;
            case '5':
            {
                changingAdress(adresaci, editingID,book);
            }
            break;
            case '6':
                break;
            }
        }
        else if (wyborMenuGlownego == '9')
        {
            exit(0);
        }
    }
    return 0;
}




