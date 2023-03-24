#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractUser
{
    private:

        string Name, Gender, Address, PhoneNumber, E_Mail, Degree;
        unsigned short int Age;
        unsigned int NumberOfBooks;

    public:

        virtual void ShowUserAttributes()
        {
            cout<<"\nName:\n"<<getName();
            cout<<"\n\nGender:\n"<<getGender();
            cout<<"\n\nAddress:\n"<<getAddress();
            cout<<"\n\nPhone Number:\n"<<getPhoneNumber();
            cout<<"\n\nE_Mail:\n"<<getE_Mail();
            cout<<"\n\nTitle:\n"<<getDegree();
            cout<<"\n\nAge:\n"<<getAge();
            cout<<"\n\nNumber of Books:\n"<<getNumberOfBooks();
        }

        void setName()
        {
            string name;

            cout<<"\nName:\n";
            cin>>name;

            Name = name;
        }

        string getName(){return Name;}

        void setGender()
        {
            string gender;

            cout<<"\nGender:\n";
            cin>>gender;

            Gender = gender;
        }

        string getGender(){return Gender;}

        void setAddress()
        {
            string address;

            cout<<"\nAddress:\n";
            cin>>address;

            Address = address;
        }

        string getAddress(){return Address;}

        void setPhoneNumber()
        {
            string phone_number;

            cout<<"\nPhone Number:\n";
            cin>>phone_number;

            PhoneNumber = phone_number;
        }

        string getPhoneNumber(){return PhoneNumber;}

        void setE_Mail()
        {
            string e_mail;

            cout<<"\nE_Mail:\n";
            cin>>e_mail;

            E_Mail = e_mail;
        }

        string getE_Mail(){return E_Mail;}

        void setDegree()
        {
            string degree;

            cout<<"\nDegree:\n";
            cin>>degree;

            Degree = degree;
        }

        string getDegree(){return Degree;}

        void setAge()
        {
            unsigned short int age;

            cout<<"\nAge:\n";
            cin>>age;

            Age = age;
        }

        unsigned short int getAge(){return Age;}

        void setNumberOfBooks()
        {
            NumberOfBooks = 0;
        }

        unsigned int getNumberOfBooks(){return NumberOfBooks;}

        void GetBook()
        {
            NumberOfBooks++;
        }

        AbstractUser()
        {
            setName();
            setGender();
            setAddress();
            setPhoneNumber();
            setE_Mail();
            setDegree();
            setAge();
            setNumberOfBooks();
        }
};

class Student: public AbstractUser
{
    private:

        string ID;

    public:

        void ShowUserAttributes()
        {
            AbstractUser::ShowUserAttributes();

            cout<<"\n\nID:\n"<<getID();
        }

        void setID()
        {
            string id;

            cout<<"\nID:\n";
            cin>>id;

            ID = id;
        }

        string getID(){return ID;}

        Student():AbstractUser()
        {
            setID();
        }
};

class Teacher: public AbstractUser
{
    private:

        string Department;

    public:

        void ShowUserAttributes()
        {
            AbstractUser::ShowUserAttributes();

            cout<<"\n\nDepartment:\n"<<getDepartment()<<endl;
        }

        void setDepartment()
        {
            string department;

            cout<<"\nDepartment:\n";
            cin>>department;

            Department = department;
        }

        string getDepartment(){return Department;}

        Teacher():AbstractUser()
        {
            setDepartment();
        }
};

class AbstractBook
{
    private:

        string Author, Title, Publisher;
        unsigned short int Year;

    public:

        virtual void ShowBookAttributes()
        {
            cout<<"\nAuthor:\n"<<getAuthor();
            cout<<"\n\nTitle:\n"<<getTitle();
            cout<<"\n\nPublisher:\n"<<getPublisher();
            cout<<"\n\nYear:\n"<<getYear();
        }

        void setAuthor()
        {
            string author;

            cout<<"\nAuthor:\n";
            cin>>author;

            Author = author;
        }

        string getAuthor(){return Author;}

        void setTitle()
        {
            string title;

            cout<<"\nTitle:\n";
            cin>>title;

            Title = title;
        }

        string getTitle(){return Title;}

        void setPublisher()
        {
            string publisher;

            cout<<"\nPublisher:\n";
            cin>>publisher;

            Publisher = publisher;
        }

        string getPublisher(){return Publisher;}

        void setYear()
        {
            unsigned short int year;

            cout<<"\nYear:\n";
            cin>>year;

            Year = year;
        }

        unsigned short int getYear(){return Year;}

        AbstractBook()
        {
            setAuthor();
            setTitle();
            setPublisher();
            setYear();
        }
};

class PrintedBook: public AbstractBook
{
    private:

        bool Status;

    public:

        void ShowBookAttributes()
        {
            AbstractBook::ShowBookAttributes();

            cout<<"\n\nTaken:\n";

            if(getStatus() == true)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }

        void setStatus()
        {
            Status = false;
        }

        bool getStatus(){return Status;}

        void Taken()
        {
            Status = true;
        }

        PrintedBook():AbstractBook()
        {
            setStatus();
        }
};

class OnlineBook: public AbstractBook
{
    private:

        string URL;

    public:

        void ShowBookAttributes()
        {
            AbstractBook::ShowBookAttributes();

            cout<<"\n\nURL:\n"<<getURL()<<endl;
        }

        void setURL()
        {
            string url;

            cout<<"\nURL:\n";
            cin>>url;

            URL = url;
        }

        string getURL(){return URL;}

        OnlineBook():AbstractBook(){setURL();}
};

class LibrarySystem
{
    public:

        void DisplayMainMenu(vector<Student>& Students, vector<Teacher>& Teachers, vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            unsigned short int option = 0;

            cout<<"\tIntegrated Library Management System\n";

            while(option != 4)
            {
                cout<<"\n1. Add\n2. Show\n3. Lend\n4. Exit\n\n";
                cin>>option;

                if(option == 1){MenuAdd(Students, Teachers, PrintedBooks, OnlineBooks);}
                else if(option == 2){MenuShow(Students, Teachers, PrintedBooks, OnlineBooks);}
                else if(option == 3){MenuLend(Students, Teachers, PrintedBooks, OnlineBooks);}
                else if(option != 4){cout<<"\nError\n";}
            }
        }

        void MenuAdd(vector<Student>& Students, vector<Teacher>& Teachers, vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return To Main Menu\n1. User\n2. Book\n\n";
                cin>>option;

                if(option == 1){MenuAddUser(Students, Teachers);}
                else if(option == 2){MenuAddBook(PrintedBooks, OnlineBooks);}
                else if(option != 0){cout<<"\nError\n";}
            }
        }

        void MenuAddUser(vector<Student>& Students, vector<Teacher>& Teachers)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return\n1. Student\n2. Teacher\n\n";
                cin>>option;

                if(option == 1)
                {
                    Student NewStudent = Student();
                    Students.push_back(NewStudent);
                }
                else if(option == 2)
                {
                    Teacher NewTeacher = Teacher();
                    Teachers.push_back(NewTeacher);
                }
                else if(option != 0)
                {
                    cout<<"\nError\n";
                }
            }
        }

        void MenuAddBook(vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return\n1. Printed Book\n2. Online Book\n\n";
                cin>>option;

                if(option == 1)
                {
                    PrintedBook NewPrintedBook = PrintedBook();
                    PrintedBooks.push_back(NewPrintedBook);
                }
                else if(option == 2)
                {
                    OnlineBook NewOnlineBook = OnlineBook();
                    OnlineBooks.push_back(NewOnlineBook);
                }
                else if(option != 0)
                {
                    cout<<"\nError\n";
                }
            }
        }

        void MenuShow(vector<Student>& Students, vector<Teacher>& Teachers, vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return To Main Menu\n1. Users\n2. Books\n\n";
                cin>>option;

                if(option == 1){MenuShowUsers(Students, Teachers);}
                else if(option == 2){MenuShowBooks(PrintedBooks, OnlineBooks);}
                else if(option != 0){cout<<"\nError\n";}
            }
        }

        void MenuShowUsers(vector<Student>& Students, vector<Teacher>& Teachers)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return\n1. Students\n2. Teachers\n\n";
                cin>>option;

                if(option == 1)
                {
                    if(Students.size() == 0)
                    {
                        cout<<"\nError\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < Students.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            Students[i].ShowUserAttributes();
                        }
                    }
                }
                else if(option == 2)
                {
                    if(Teachers.size() == 0)
                    {
                        cout<<"\nError\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < Teachers.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            Teachers[i].ShowUserAttributes();
                        }
                    }
                }
                else if(option != 0)
                {
                    cout<<"\nError\n";
                }
            }
        }

        void MenuShowBooks(vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            unsigned short int option = 3;

            while(option != 0)
            {
                cout<<"\n0. Return\n1. Printed Books\n2. Online Books\n\n";
                cin>>option;

                if(option == 1)
                {
                    if(PrintedBooks.size() == 0)
                    {
                        cout<<"\nError\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < PrintedBooks.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            PrintedBooks[i].ShowBookAttributes();
                        }
                    }
                }
                else if(option == 2)
                {
                    if(OnlineBooks.size() == 0)
                    {
                        cout<<"\nError\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < OnlineBooks.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            OnlineBooks[i].ShowBookAttributes();
                        }
                    }
                }
                else if(option != 0)
                {
                    cout<<"\nError\n";
                }
            }
        }

        void MenuLend(vector<Student>& Students, vector<Teacher>& Teachers, vector<PrintedBook>& PrintedBooks, vector<OnlineBook>& OnlineBooks)
        {
            if(PrintedBooks.size() == 0)
            {
                cout<<"\nError\n";
            }
            else
            {
                unsigned int counter = 0;

                for(unsigned int i = 0; i < PrintedBooks.size(); i++)
                {
                    if(PrintedBooks[i].getStatus() == true)
                    {
                        counter++;
                    }
                }
                if(counter == PrintedBooks.size())
                {
                    cout<<"\nNo Printed Books Available to Lend\n";
                }
                else
                {
                    unsigned short int option = 3;

                    while(option != 0)
                    {
                        cout<<"\n0. Return To Main Menu\n1. Lend for Student\n2. Lend for Teacher\n\n";
                        cin>>option;

                        if(option == 1)
                        {
                            if(Students.size() == 0)
                            {
                                cout<<"\nError\n";
                            }
                            else
                            {
                                unsigned int UserNumber, PrintedBookNumber;

                                cout<<"\nEnter the Number of the Student Requesting the Book\n"<<endl;
                                cin>>UserNumber;

                                while(UserNumber <= 0 || UserNumber > Students.size())
                                {
                                    cout<<"\nError\n\n";
                                    cin>>UserNumber;
                                }

                                cout<<"\nEnter the Number of the Book requested by the Student\n"<<endl;
                                cin>>PrintedBookNumber;

                                while(PrintedBookNumber <= 0 || PrintedBookNumber > PrintedBooks.size())
                                {
                                    cout<<"\nError\n\n";
                                    cin>>PrintedBookNumber;
                                }

                                if(PrintedBooks[PrintedBookNumber - 1].getStatus() == true)
                                {
                                    cout<<"\nThis Printed Book Was Already Taken\n";
                                }
                                else
                                {
                                    PrintedBooks[PrintedBookNumber - 1].Taken();
                                    Students[UserNumber - 1].GetBook();
                                }
                            }
                        }
                        else if(option == 2)
                        {
                            if(Teachers.size() == 0)
                            {
                                cout<<"\nError\n";
                            }
                            else
                            {
                                unsigned int UserNumber, PrintedBookNumber;

                                cout<<"\nEnter the Number of the Teacher Requesting the Book\n"<<endl;
                                cin>>UserNumber;

                                while(UserNumber <= 0 || UserNumber > Teachers.size())
                                {
                                    cout<<"\nError\n\n";
                                    cin>>UserNumber;
                                }

                                cout<<"\nEnter the Number of the Book requested by the Teacher\n"<<endl;
                                cin>>PrintedBookNumber;

                                while(PrintedBookNumber <= 0 || PrintedBookNumber > PrintedBooks.size())
                                {
                                    cout<<"\nError\n\n";
                                    cin>>PrintedBookNumber;
                                }

                                if(PrintedBooks[PrintedBookNumber - 1].getStatus() == true)
                                {
                                    cout<<"\nThis Printed Book Was Already Taken\n";
                                }
                                else
                                {
                                    PrintedBooks[PrintedBookNumber - 1].Taken();
                                    Teachers[UserNumber - 1].GetBook();
                                }
                            }
                        }
                        else if(option != 0)
                        {
                            cout<<"\nError\n\n";
                        }
                    }
                }
            }
        }
};

int main()
{
    vector<Student> Students;
    vector<Teacher> Teachers;
    vector<PrintedBook> PrintedBooks;
    vector<OnlineBook> OnlineBooks;

    LibrarySystem School;
    School.DisplayMainMenu(Students, Teachers, PrintedBooks, OnlineBooks);

    return 0;
}
