#include <iostream>
using namespace std;

class Student
{
protected: // show data in inheritance (child) class
    string name;
    string id;
    int age;
    string grade;
    string dep;

public:
    Student(string n = "", string i = "", int a = 18, string g = "f", string d = "")
    {
        name = n;
        id = i;
        age = a;
        grade = g;
        dep = d;
    }
    // Getter and Setter:
    string getname()
    {
        return name;
    }
    string getid()
    {
        return id;
    }
    int getage()
    {
        return age;
    }
    string getgrade()
    {
        return grade;
    }
    string getdep()
    {
        return dep;
    }
    void setname(string a)
    {
        name = a;
    }
    void setid(string b)
    {
        id = b;
    }
    void setage(int c)
    {
        age = c;
    }
    void setgrade(string d)
    {
        grade = d;
    }
    void setdep(string e)
    {
        dep = e;
    }
    // functions
    virtual void showdata()
    {
        cout << "name is: " << name << "\nid: " << id << "\nage is: " << age << endl;
        cout << "grade is: " << grade << "\ndepartement of: " << dep << endl;
    }
};

class ThirdStudent : public Student
{
private:
    string spec;

public:
    ThirdStudent(string n, string i, int a, string g, string d, string s) : Student(n, i, a, g, d)
    {
        spec = s;
    }

    void setspec(int a)
    {
        spec = a;
    }
    string getspec(void)
    {
        return spec;
    }
    void showdata()
    {
        cout << "name is: " << name << "\nid: " << id << "\nage is: " << age << endl;
        cout << "grade is: " << grade << "\ndepartement of: " << dep << "\nsp: " << spec << endl;
    }
    friend string spe(ThirdStudent v,Student w);

};

//friend functions
string spe(ThirdStudent v, Student w){
    return(v.spec);
}

class Shape
{
protected:
    string name;

public:
    Shape(string n = "")
    {
        name = n;
    }
    void setname(string a)
    {
        name = a;
    }
    string getname()
    {
        return name;
    }
    virtual float area() = 0;  // become abstract class ,,,, should define in child classes
};

class Circle : public Shape {
    private:
    float rad;
    public:
    Circle(float r = 0, string n = ""):Shape(n) {
        rad = r;
    }
    void setrad(float f){
        rad = f;
    }
    float getrad(){
        return rad;
    }
    float area(){              // the area function is must
        return 3.14*rad*rad;
    }
};

int main()
{
    cout << "============================\n";
    Student s("amr", "2r344", 20, "A", "cs");
    s.showdata();
    cout << "============================\n";

    ThirdStudent t("amr", "3434", 3434, "A", "mathi", "eng");
    t.setname("amr");
    t.showdata();
    cout << "============================\n";

    Student *p;
    p = new ThirdStudent("mohamad", "3434", 568, "B", "cds", "sh");
    p->showdata();
    cout << "============================\n";

    Circle c(10, "cir");
    cout << c.area() << endl;
    cout << "============================\n";
    cout << spe(t, s);
}