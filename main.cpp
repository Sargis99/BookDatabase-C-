#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
using namespace std;
class Entry
{
public:
    string name, author, year;
    Entry(string x, string y,string z)
    {
        name=x;
        author =y;
        year =z;
    }
};
class Book
{
public:
    list<Entry> a;
    int n;
    Book()
    {
        n=0;
    }
    bool add(string name, string author, string year) {

        a.emplace_back(Entry(name,author,year));
        n++;
        return true;
    }
    bool del(string x)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            auto it1 = next(a.begin(),i);
            if (it1->name.compare(x)==0) break;
        }

        if (i == n) return false;
        for (int j = i; j < n-1; j++)
        {
            auto it = next(a.begin(),j);
            auto it1 = next(a.begin(),j+1);
            it = it1;
        }
        auto it1 = next(a.begin(),n-1);
        it1->name ="";
        it1->author ="";
        it1->year = "";
        n -= 1;
        return true;
    }
    string getinfo(string name)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            auto it1 = next(a.begin(),i);
            if (it1->name.compare(name)==0) break;
        }
        auto it = next(a.begin(),i);
        string k= it->author+" "+it->year;
        return k;
    }
    bool write()
    {
        fstream fs;
        fs.open ("names.txt", ios::out | ios::trunc);

        for (int i = 0; i < n; i++)
        {
            auto it = next(a.begin(),i);
            fs <<it->name;
            fs <<"  ";
            fs <<it->author;
            fs <<" ";
            fs <<it->year;
            fs <<endl;
        }
        fs.close();

        return true;
    }
    void View()
    {
        for(int j=0;j<n;j++)
        {
            auto it1 = next(a.begin(),j);

            cout << it1->name << " "<< it1->author << " " << it1->year << endl;
        }
    }
};
class Reading
{
private:
  vector<string> split(string str,string sep){
        char* cstr=const_cast<char*>(str.c_str());
        char* current;
        std::vector<std::string> arr;
        current=strtok(cstr,sep.c_str());
        while(current!=NULL){
            arr.push_back(current);
            current=strtok(NULL,sep.c_str());
        }
        return arr;
    }
public:
    int n;
    list<Entry> a;
    list<string> s;
    string str;
    Reading(){}
    void Read()
    {
        int l=0;
        ifstream infile;
        infile.open ("names.txt");

        while( getline(infile,str ))
        {
            s.push_back(str);
            l++;
        }

        n=l;
    }
    void Create()
    {

       for (list<string>::iterator it=s.begin(); it != s.end(); ++it)
            {

                vector<string> arr;
                arr = split(*it, "  ");
                a.emplace_back(Entry(arr[0], arr[1], arr[2]));

        }
    }
    bool add(string name, string author, string year)
    {
        a.emplace_back(Entry(name,author,year));
        n++;
        return true;
    }
    bool del(string x)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            auto it1 = next(a.begin(),i);
            if (it1->name.compare(x)==0) break;
        }

        if (i == n) return false;
        for (int j = i; j < n-1; j++)
        {
            auto it = next(a.begin(),j);
            auto it1 = next(a.begin(),j+1);
            it = it1;
        }
        auto it1 = next(a.begin(),n-1);
        it1->name ="";
        it1->author ="";
        it1->year = "";
        n -= 1;
        return true;
    }
    string getinfo(string name)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            auto it1 = next(a.begin(),i);
            if (it1->name.compare(name)==0) break;
        }
        auto it = next(a.begin(),i);
        string k= it->author+" "+it->year;
        return k;
    }
    bool write()
    {
        fstream fs;
        fs.open ("names.txt", ios::out | ios::trunc);

        for (int i = 0; i < n; i++)
        {
            auto it = next(a.begin(),i);
            fs <<it->name;
            fs <<"  ";
            fs <<it->author;
            fs <<" ";
            fs <<it->year;
            fs <<endl;
        }
        fs.close();

        return true;
    }
    void View()
    {
        for(int j=0;j<n;j++)
        {
            auto it1 = next(a.begin(),j);

            cout << it1->name << " "<< it1->author << " " << it1->year << endl;
        }
    }

};

class MyConsole
{
private:
    bool isDigit(string x) {
        for (int i = 0; i < x.size(); i++)
            if (x[i] >= '0' && x[i] <= '9') {
                return false;
            }
        return true;
    }

    bool isLetter(string x) {
        for (int i = 0; i < x.size(); ++i) {
            if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
                return false;
            return true;
        }
    }
public:
    void Start()
    {
        int x,y;
        string n,m,k;
        cout<<"1-use existing 2-create"<<endl;
        cin>>x;
        Reading r;
        r.Read();
        r.Create();
        Book b;
        while(true)
        {
            if(x==1)
            {

                cout<<"1-add 2-search 3-delete 4-View 0-save changes and quit"<<endl;
                cin>>y;
                switch (y)
                {
                    case 0: r.write(); return;
                    case 1:
                        cout << "enter name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        cout << "enter author" << endl;
                        cin >> m;
                        try {
                            if (!(isDigit(m)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> m;
                        }
                        cout << "enter the year" << endl;
                        cin >> k;
                        try {
                            if (!(isLetter(k)))
                                throw new string("You should use only digits");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> k;
                        }
                        if (r.add(n, m, k))
                            cout << "added" << endl;
                        else
                            cout << "not added" << endl;
                        break;
                    case 2:
                        cout << "Enter the name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        cout << r.getinfo(n) << endl;
                        break;
                    case 3:
                        cout << "Enter the name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        if (r.del(n))
                            cout << "deleted" << endl;
                        else
                            cout << "not found" << endl;
                        break;
                    case 4:
                        r.View();
                        break;
                    default: break;
                }
            }
            else if(x==2)
            {
                cout<<"1-add 2-search 3-delete 4-View 0-save changes and quit"<<endl;
                cin>>y;
                switch (y)
                {
                    case 0: b.write(); return;
                    case 1:
                        cout << "enter name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        cout << "enter author" << endl;
                        cin >> m;
                        try {
                            if (!(isDigit(m)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> m;
                        }
                        cout << "enter the year" << endl;
                        cin >> k;
                        try {
                            if (!(isLetter(k)))
                                throw new string("You should use only digits");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> k;
                        }
                        if (b.add(n, m, k))
                            cout << "added" << endl;
                        else
                            cout << "not added" << endl;
                        break;
                    case 2:
                        cout << "Enter the name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        cout << b.getinfo(n) << endl;
                        break;
                    case 3:
                        cout << "Enter the name" << endl;
                        cin >> n;
                        try {
                            if (!(isDigit(n)))
                                throw new string("You should use only letters");
                        }
                        catch (std::string *caught) {
                            std::cout << "Got " << *caught << std::endl;
                            cin >> n;
                        }
                        if (b.del(n))
                            cout << "deleted" << endl;
                        else
                            cout << "not found" << endl;
                        break;
                    case 4:
                        b.View();
                        break;
                    default: break;
                }
            }

        }
    }
};
int main()
{
  /*  Reading r;
    r.Read();
    r.Create();
    r.View();
    if(r.add("a","b","c"))
        cout<<"aded"<<endl;
    r.View();*/
    MyConsole m;
    m.Start();
    return 0;
}
