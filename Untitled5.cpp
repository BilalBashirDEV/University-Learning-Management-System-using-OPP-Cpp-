#include<iostream>
#include<conio.h>
#include<fstream>                                           //library
#include<string>
using namespace std;
class user
{                                                            //user class parent
	string regno, cnic, fone, name,password;                    //private members
public:
	void useri();
	void ulogin();                                                       //functions
	void setdata(string aa, string bb, string cc, string dd);
	void setname(string aa);                                                    //setters
	void setregno(string aa);
	void setfone(string aa);
	void setcnic(string cnic);
	string getname();
	string getcnic();                                         //getters
	string getfone();
	string getregno();
	//string regno, password;
	friend bool validname(user *name);                      //friend functions
friend 	bool login();
	friend void isvaliduser();                        //valid functions
};
class student : public user
{
private:
	int sem; float gpa;                           //student class
public:
	void std();
	//friend teacher;
	//student(string aa, string bb, string cc, string dd,string ee,string ff);
	//student(string aa, string bb, string cc, string dd);
	void enrollcourse();
	void unenrollcourse();                  
	void showcourses();                                  
	void setgpa(float aa);
	void showscholarships();
	float getgpa();
	void setsem(int a);
	int getsem();
};
class course
{
	string crsname;                       //course class used for composition
	public:
//	string crsname;
	void setcrs()
	{
		string g;
		cin>>g;
		crsname=g;
	}
	string getcrs()                    //getter
	{
		return crsname;
	}
};
class teacher : public user
{                                               //teacher class
public:
	void tch();
	course c;
	void viewattendance();
	void showstudents();
	//teacher(string aa, string bb, string cc, string dd);
	//teacher(string aa , string bb, string cc, string dd,course c);
	void setcourse(course c);
	course getcource();
	void assigncourse();
	void showcourses();
	void doattendance();
	void viewgrade();
	//void viewattendance();
	void givegrade();
};

	class admin : public user
//class admin : public teacher, public student
{                                                          //admin class
public:
	void addusers();
	course c;
	//admin(string aa, string bb, string cc, string dd);
//	admin();
	void adm();
	void addstudent();
	void showstudents();
	
	bool validpassword(string a1);                       //valid password
	void searchst();
	void addteacher();
	void showteachers();
	void addadmin();
	void showadmins();
	void addcourse(course c);
	void showcourses(course c);
	void searchtch();
	void searchadm();
	void deleteadmin();
	//void deletest();
	//void addadmin();
	//void updatest();
	void deletestudent();
	void updatestudent();
	void deleteteacher();
	void updateteacher();
	//void searchst();
	void addscholarships();
	void showscholarships();
	void updatecourse();
	void updateadmin();
};
void user::setdata(string aa, string bb, string cc, string dd)
{                                                                       //setter for set data
	name = aa;
	regno = bb;
	cnic = cc;
	fone= dd;
}
string user :: getname()
{
	return name;
}
string user::getfone()
{                                                        
	return fone;
}string user::getregno()
{
	return regno;
}string user::getcnic()
{
	return cnic;
}
void user::setname(string aa)
{
	name = aa;
}
void user::setregno(string aa)
{
	regno = aa;
}
void user::setcnic(string aa)
{
	cnic = aa;
}void user::setfone(string aa)
{
	fone = aa;
}
void student::setsem(int a)
{
	sem = a;
}
void student::setgpa(float a)
{
	gpa = a;
}
int student::getsem()
{
	return sem;
}float student:: getgpa()
{
	return gpa;
}
bool validname(user *name)
{
	
	string a1, a2, a3, a4, a5;
	//	char alphabets[]={'q','w','e'};
		//cin>>a1;
	int j, h = 0;
	int k = a1.size();
                                                             //valid name
	int i = 0;
	//for(int i=0;i<k;i++)
	while (i < k)
	{

		if (isalpha(a1[i]))
		{
			//	h+1;
			if (i == (k - 1))
			{
				//cout<<"valid name";
				return true;
				break;
			}
			else {
				//continue;
			//	i++;
				//cout<<"d";
			//	h+1;
			}
			i++;
		}

		else
		{
			//	cout<<"unvalid name";
			return false;
			break;
		}
		//i++;
	}
}
void admin:: addteacher()                         //add teacher
{
	admin n;
	ofstream ost;
	int  k;
	string stname, stregno, stfone, stcnic;
	ost.open("teacher.txt", ios::app);
	cout << "enter the number of teachers you want to now" << endl;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cout << "enter  regno name cnic and fone of teacher" << endl;
		cin >> stname >> stregno >>stcnic>>stfone;
		n.setdata(stname, stregno, stcnic, stfone);
		ost << n.getname() <<" "<< n.getregno() <<" "<< n.getcnic() << " "<<n.getfone()<<endl;
		cout << n.getname() << " " << n.getregno() << " " << n.getcnic() << " " << n.getfone() << endl;
	}
	ost.close();
}
void admin::addstudent()
{
	admin n;
	ofstream ost;
	int  k;
	string stname, stregno, stfone, stcnic;
	ost.open("student.txt", ios::app);
	cout << "enter the number of student you want to now" << endl;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cout << "enter  regno name cnic and fone of student" << endl;
		cin >> stname >> stregno >> stcnic >> stfone;
		n.setdata(stname, stregno, stcnic, stfone);
		ost << n.getname() << " " << n.getregno() << " " << n.getcnic() << " " << n.getfone() << endl;
		cout << n.getname() << " " << n.getregno() << " " << n.getcnic() << " " << n.getfone() << endl;
	}
	ost.close();
}
void admin::addadmin()
{
	admin n;
	ofstream ost;
	int  k;
	string stname, stregno, stfone, stcnic;
	ost.open("admin.txt", ios::app);
	cout << "enter the number of admins you want to now" << endl;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cout << "enter  regno name fcnic and fone of admins" << endl;
		cin >> stname >> stregno >> stcnic >> stfone;
		n.setdata(stname, stregno, stcnic, stfone);
		ost << n.getname() << " " << n.getregno() << " " << n.getcnic() << " " << n.getfone() << endl;
		cout << n.getname() << " " << n.getregno() << " " << n.getcnic() << " " << n.getfone() << endl;
	}
	ost.close();
}
void admin::showteachers()
{
	
	string name, company, colour, price;
	ifstream idata;
	idata.open("teacher.txt", ios::in);
	cout << "name" << " " << "regno" <<" "<<"cnic"<< " "<<"fone"<< endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
	   idata >> price;
		k++;
	}
	idata.close();
	idata.open("teacher.txt", ios::in);

	string tt;

	for (int j = 0; j < k; j++)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		cout << name << " " << company <<" "<< colour<<" "<<price<< endl;
	}
}
void teacher::showstudents()
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("student.txt", ios::in);
	cout << "name" << " " << "regno" << " " << "cnic" << " " << "fone" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		//idata >> price;
		k++;
	}
	idata.close();
	idata.open("student.txt", ios::in);

	string tt;

	for (int j = 0; j < k; j++)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		cout << name << " " << company << " " << colour << endl;
	}
}
void admin::showstudents()
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("student.txt", ios::in);
	cout << "name" << " " << "regno" << " " << "cnic" << " " << "fone" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		k++;
	}
	idata.close();
	idata.open("student.txt", ios::in);

	string tt;

	for (int j = 0; j < k; j++)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		cout << name << " " << company << " " << colour << " " << price << endl;
	}
}
void admin::showadmins()
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("admin.txt", ios::in);
	cout << "name" << " " << "regno" << " " << "cnic" << " " << "fone" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		k++;
	}
	idata.close();
	idata.open("admin.txt", ios::in);

	string tt;

	for (int j = 0; j < k; j++)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		cout << name << " " << company << " " << colour << " " << price << endl;
	}
}
void admin::searchst()
{
	string s1, s2, s3, s4,s5,s6;
	ifstream ii;
	ii.open("student.txt", ios::app); int sn;
	cout << "search the student by name or reg.no **press 1 for name and 2 for reg.no" << endl;
	cin >> sn;
	if (sn == 1)
	{
		cout << "enter name" << endl;
		cin >> s3;
		while (!ii.eof())
		{
			ii >> s1 >> s2>>s5>>s6;
			if (s1 == s3)
			{
				getline(ii, s1);
				cout << s1 << s3 << " " << s2 << " "<<s5<<" "<<s6<<endl;
			}
		}

	}
	else if (sn == 2)
	{
		cout << "enter reg.no" << endl;
		cin >> s4;
		while (!ii.eof())
		{
			ii >> s1 >> s2;
			if (s2 == s4)
			{
				getline(ii, s2);
				cout << s1 << "  " << s2 << "  " << s4 << " " << s5 << " " << s6 << endl;
			}
		}
	}
}
void admin::searchtch()
{
	string s1, s2, s3, s4, s5, s6;
	ifstream ii;
	ii.open("teacher.txt", ios::app); int sn;
	cout << "search the teacher by name or reg.no **press 1 for name and 2 for reg.no" << endl;
	cin >> sn;
	if (sn == 1)
	{
		cout << "enter name" << endl;
		cin >> s3;
		while (!ii.eof())
		{
			ii >> s1 >> s2 >> s5 >> s6;
			if (s1 == s3)
			{
				getline(ii, s1);
				cout << s1 << s3 << " " << s2 << " " << s5 << " " << s6 << endl;
			}
		}

	}
	else if (sn == 2)
	{
		cout << "enter reg.no" << endl;
		cin >> s4;
		while (!ii.eof())
		{
			ii >> s1 >> s2;
			if (s2 == s4)
			{
				getline(ii, s2);
				cout << s1 << "  " << s2 << "  " << s4 <<" "<<s5<<" "<<s6<< endl;
			}
		}
	}
}
void admin::searchadm()
{
	string s1, s2, s3, s4, s5, s6;
	ifstream ii;
	ii.open("admin.txt", ios::app); int sn;
	cout << "search the teacher by name or reg.no **press 1 for name and 2 for reg.no" << endl;
	cin >> sn;
	if (sn == 1)
	{
		cout << "enter name" << endl;
		cin >> s3;
		while (!ii.eof())
		{
			ii >> s1 >> s2 >> s5 >> s6;
			if (s1 == s3)
			{
				getline(ii, s1);
				cout << s1 << s3 << " " << s2 << " " << s5 << " " << s6 << endl;
			}
		}

	}
	else if (sn == 2)
	{
		cout << "enter reg.no" << endl;
		cin >> s4;
		while (!ii.eof())
		{
			ii >> s1 >> s2;
			if (s2 == s4)
			{
				getline(ii, s2);
				cout << s1 << "  " << s2 << "  " << s4 << " " << s5 << " " << s6 << endl;
			}
		}
	}
}
void admin::deletestudent()
{
	ifstream b;
	ofstream d;
	b.open("student.txt", ios::in);
	d.open("student1.txt");
	string s2, temp, s3, s4, s5, s6;
	string v;
	cout << "enter the student regno and name and cnic and fone to delete" << endl;
	cin >> s2 >> s3>>s4>>s5;
	string r = v;
	string h, j, k;//	void books::viewbookss() = v;
	while (getline(b, temp))
		//while(!b.eof())
	{
		if (temp != (s2 + " " + s3+" "+s4+" "+s5))
		{
			d << temp << endl;
		}
		else if (temp == (s2 + " " + s3+" "+s4+" "+s5))
		{
			continue;
		}
	}
	b.close();
	d.close();
	remove("student.txt");
	rename("student1.txt", "student.txt");
	ofstream c;
	c.open("student.txt", ios::app);
	c.close();
	showstudents();
}
void admin::deleteteacher()
{
	ifstream b;
	ofstream d;
	b.open("teacher.txt", ios::in);
	d.open("student1.txt");
	string s2, temp, s3, s4, s5, s6;
	string v;
	cout << "enter the teacher regno and name and cnic and fone to delete" << endl;
	cin >> s2 >> s3 >> s4 >> s5;
	string r = v;
	string h, j, k;//	void books::viewbookss() = v;
	while (getline(b, temp))
		//while(!b.eof())
	{
		if (temp != (s2 + " " + s3 + " " + s4 + " " + s5))
		{
			d << temp << endl;
		}
		else if (temp == (s2 + " " + s3 + " " + s4 + " " + s5))
		{
			continue;
		}
	}
	b.close();
	d.close();
	remove("teacher.txt");
	rename("student1.txt", "teacher.txt");
	ofstream c;
	c.open("teacher.txt", ios::app);
	c.close();
	showteachers();
}
void admin::deleteadmin()
{
	ifstream b;
	ofstream d;
	b.open("admin.txt", ios::in);
	d.open("student1.txt");
	string s2, temp, s3, s4, s5, s6;
	string v;
	cout << "enter the admin regno and name and cnic and fone to delete" << endl;
	cin >> s2 >> s3 >> s4 >> s5;
	string r = v;
	string h, j, k;//	void books::viewbookss() = v;
	while (getline(b, temp))
		//while(!b.eof())
	{
		if (temp != (s2 + " " + s3 + " " + s4 + " " + s5))
		{
			d << temp << endl;
		}
		else if (temp == (s2 + " " + s3 + " " + s4 + " " + s5))
		{
			continue;
		}
	}
	b.close();
	d.close();
	remove("admin.txt");
	rename("student1.txt", "admin.txt");
	ofstream c;
	c.open("admin.txt", ios::app);
	c.close();
	showadmins();
}
void admin::updatestudent()
{
	cout << "enter item name you want to dell" << endl;
	string  name, company, colour, price;
	string  name1, company1, colour1, price1;
	cout << "enter regno" << endl;
	cin >> name1;
	cout << "enter name" << endl;
	cin >> company1;
	cout << "enter cnic" << endl;
	cin >> colour1;
	cout << "enter fone" << endl;
	cin >> price1;
	ofstream odata;
	ifstream indata;
	odata.open("student1.txt");
	indata.open("student.txt", ios::in);

	string fan1;
	string jj,gg;
	while (getline(indata, name))
	{
	
		if (name != (name1 + " " + company1+" " + colour1 + " " + price1))
		{
			//odata << name << endl;
			odata<<name<<" "<<company<<" "<<colour<<" "<<price<<endl;

		}
		else if (name == (name1 + " " + company1+" "+colour1+" "+price1))

		{
			cin >> colour >> price>>jj>>gg;
			odata << colour << " " << price <<" "<<jj<<" "<<gg<< endl;
		}

	}
	indata.close();
	odata.close();
	remove("student.txt");
	rename("student1.txt", "student.txt");
	ofstream c;
	c.open("student.txt", ios::app);
	c.close();
	showstudents();
}
void admin::updateteacher()
{
	cout << "enter teacher name you want to update" << endl;
	string  name, company, colour, price;
	string  name1, company1, colour1, price1;
	cout << "enter regno" << endl;
	cin >> name1;
	cout << "enter name" << endl;
	cin >> company1;
	cout << "enter cnic" << endl;
	cin >> colour1;
	cout << "enter fone" << endl;
	cin >> price1;
	ofstream odata;
	ifstream indata;
	odata.open("student1.txt");
	indata.open("teacher.txt", ios::in);

	string fan1;
	string jj, gg;
	while (getline(indata, name))
	{
		if (name != (name1 + " " + company1 + " " + colour1 + " " + price1))
		{
			//odata << name << endl;
			odata << name << " " << company << " " << colour << " " << price << endl;

		}
		else if (name == (name1 + " " + company1 + " " + colour1 + " " + price1))

		{
			cin >> colour >> price >> jj >> gg;
			odata << colour << " " << price << " " << jj << " " << gg << endl;
		}

	}
	indata.close();
	odata.close();
	remove("teacher.txt");
	rename("student1.txt", "teacher.txt");
	ofstream c;
	c.open("teacher.txt", ios::app);
	c.close();
	showteachers();
}
void admin::updateadmin()
{
	cout << "enter item name you want to dell" << endl;
	string  name, company, colour, price;
	string  name1, company1, colour1, price1;
	cout << "enter regno" << endl;
	cin >> name1;
	cout << "enter name" << endl;
	cin >> company1;
	cout << "enter cnic" << endl;
	cin >> colour1;
	cout << "enter fone" << endl;
	cin >> price1;
	ofstream odata;
	ifstream indata;
	odata.open("student1.txt");
	indata.open("student.txt", ios::in);

	string fan1;
	string jj, gg;
	while (getline(indata, name))
	{
		//	indata>>name;
		//	indata>>company;
		//	indata>>colour;
		//	indata>>price;
		if (name != (name1 + " " + company1 + " " + colour1 + " " + price1))
		{
			//odata << name << endl;
			odata << name << " " << company << " " << colour << " " << price << endl;

		}
		else if (name == (name1 + " " + company1 + " " + colour1 + " " + price1))

		{
			cin >> colour >> price >> jj >> gg;
			odata << colour << " " << price << " " << jj << " " << gg << endl;
		}

	}
	indata.close();
	odata.close();
	remove("admin.txt");
	rename("student1.txt", "admin.txt");
	ofstream c;
	c.open("admin.txt", ios::app);
	c.close();
	showadmins();
}


void admin::addcourse( course c)
{
	admin n;
	ofstream cot;
	//string crsname;
	cot.open("courses.txt", ios::app);
	cout << "enter the number of courses you want" << endl;
	int g;
	cin >> g;
	for (int i = 1; i <= g; i++)
	{
		cout << "enter" << endl;
	//	cin >>n.c.crsname;
    	n.c.setcrs();
				cot <<n.c.getcrs() << endl;
//	cot<<n.c.crsname<<endl;
	}
	cot.close();
}
void admin::addscholarships()
{
	admin n;
	ofstream cot;
	string sname;
	cot.open("scholarships.txt", ios::app);
	cout << "enter the number of scholarships you want" << endl;
	int g;
	cin >> g;
	for (int i = 1; i <= g; i++)
	{
		cout << "enter" << endl;
		cin >> sname;
		cot << sname << endl;
	}
	cot.close();
}
void student:: enrollcourse()
{
	string regno ,ee, dd, ff, gg, hh, jj, kk;
	cin >> regno;
	//cin >> ee;
	int j = 0, t, y;
	ofstream cc;
	ifstream ss;
	cc.open("enrollc.txt", ios::app);
	ss.open("enrollc.txt");
	cout << "enter the nmbr of courses you want enter now" << endl;
	cin >> t;
	string temp;

	if (t > 0 && t < 6)
	{
		cc << regno << "  ";
		for (int i = 0; i < t; i++)
		{
			cout << "enter coursename" << endl;
			cin >> ee;
			cc << ee << "  ";
		}
		cc << endl;
	}
	else
	{
		cout << "enter between 1 to 6, only 5 courses can be registerd at a time";
		//enrollcourse();
		
	}
}
void student::showcourses()
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("courses.txt", ios::in);
	cout << "course" << endl; //<< "company" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
	   //idata >> price;
		k++;
	}
	idata.close();
	idata.open("courses.txt", ios::in);

	string tt;

	for (int j = 0; j < k + 1; j++)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
		//idata >> price;
		cout << name << endl;        //"  " << company << endl;
	}
}
void admin::showcourses(course c)
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("courses.txt", ios::in);
	cout << "course" << endl; //<< "company" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
	   //idata >> price;
		k++;
	}
	idata.close();
	idata.open("courses.txt", ios::in);

	string tt;

	for (int j = 0; j < k + 1; j++)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
		//idata >> price;
		cout << name << endl;        //"  " << company << endl;
	}
}
void student::showscholarships()
{
	string name, company, colour, price;
	ifstream idata;
	idata.open("scholarship.txt", ios::in);
	cout << "course" << endl; //<< "company" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
	   //idata >> price;
		k++;
	}
	idata.close();
	idata.open("courses.txt", ios::in);

	string tt;

	for (int j = 0; j < k + 1; j++)
	{
		idata >> name;
		//idata >> company;
		//idata >> colour;
		//idata >> price;
		cout << name << endl;        //"  " << company << endl;
	}
}
void teacher::assigncourse()
{
	string h,temp,i,d,o,j;
	ifstream k;
	ofstream b;
	k.open("courses.txt");
	b.open("ecourses.txt",ios::app);
	cout << "enter regno" << endl;
	cin >> h;
	cout << "enter crs" << endl;
	cin >> d;
	while (getline(k, temp))
	{
	//	k >> o;
		if (temp != d)
		{
			//b << o << endl;
			
		}
		else if(temp==d)
		{
			cout << "enter teacher regno" << endl;
			cin >> i;
			b << temp << " " << i << endl;
		}
	}
	b.close();
	k.close();

}
void teacher::givegrade()
{
	teacher h;
	ifstream m;
	ofstream n;
	string s, f, d, w,r,y;
	string e;
	m.open("student.txt");
	n.open("grade.txt", ios::app);
	h.showstudents();
	while (getline(m, s))
	{
		cout << "enter grade of this student" << endl;
		cin >> e;
		//m >> s>>f>>d>>y;
		n << s<<" "<<e<<endl;
	}
}
void teacher::doattendance()
{
	teacher h;
	ifstream m;
	ofstream n;
	string s, f, d, w, r, y;
	string e;
	m.open("student.txt");
	n.open("attendance.txt", ios::app);
	h.showstudents();
	while (getline(m, s))
	{
		cout << "enter attendance percentage of this student" << endl;
		cin >> e;
		//m >> s>>f>>d>>y;
		n << s << " " << e << endl;
	}
}

void teacher :: viewgrade()
{
	string name, company, colour, price,hh;
	ifstream idata;
	idata.open("grade.txt", ios::in);
	//cout << "course" << endl<< "company" << endl;
	int j = 0;
	int i = 0;
	int k = 0;
	string jj;
	while (idata >> jj)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
	    idata >> price;
		idata >> hh;
		k++;
	}
	idata.close();
	idata.open("grade.txt", ios::in);

	string tt;

	for (int j = 0; j < k + 1; j++)
	{
		idata >> name;
		idata >> company;
		idata >> colour;
		idata >> price;
		cout << name <<"  " << company<<"  "<<colour <<"  "<<price<<"  "<<hh<< endl;
	}
}
void adm();
bool login()
{
	user uu;
	ifstream up;
	up.open("up.txt");
	ifstream m;
	m.open("up.txt");
	string ss, dd, ff, hh, gg, ii;
	cout << "enter your regno" << endl;
	cin >> ff;
	cout << "enter your password" << endl;
	cin >> gg;
	int i = 0;
	while (getline(up, ii))
	{
		i = i + 1;
	}
	//cout << i;
	int k = 0;
	while (m >> uu.regno >> uu.password)
	{
		k = k + 1;
		if ((uu.regno != ff || uu.password != gg) && (k == i)) {
		//	cout << "soryyyyyyyyyyyyyyy";
		return false;
			break;
		}
		else if (uu.regno == ff && uu.password == gg)
		{
		//	cout << "j";
		return true;
			//admin h;
			//adm();
			
			break;
		}
		else
		{
			//cout << "e";
			//break;
			system("exit");
		}
	}
}//cout << k;
void adm()
{
	admin a;
	system("cls");
	int o;
	cout << "WELCOME AS AN ADMIN" << endl;
	cout << "";
		cout << "";
		cout << "1.addstudent\n";
	cout << "2.addteacher\n";
	cout << "3.addadmin\n";
	cout << "4.showstudents\n";
	cout << "5.showteachers\n";
	cout << "6.showadmins\n";
		cout << "7.deletestudents\n";
		cout << "8.delete teachers\n";
		cout << "9.delete admins\n";
		cout << "10.update students\n";
		cout << "11.update teachers\n";
		cout << "12.update admins\n";
		cout << "13.addusers\n";
		cout << "14.addscholarship\n";
		cout << "15.addcourse\n";
		cout << "16.showcourses\n";
		cout << "17.searchstudents\n";
		cout << "18.searchteachers\n";
		cout << "19.searchadmins\n";
		cout<<"20.main menu";
		cin >> o;
		if (o == 1)
		{
			a.addstudent();
		}
		if (o == 2) 
		{
			a.addteacher();
		}
		if (o == 3)
		{
			a.addadmin();
		}
		if (o == 4)
		{
			a.showstudents();
		}
		if (o ==5 )
		{
			a.showteachers();
		}if (o == 6)
		{
			a.showadmins();

		}if (o == 7)
		{
			a.deletestudent();
		}if (o == 8)
		{
			a.deleteteacher();
		}if (o ==9 )
		{
			a.deleteadmin();

		}if (o ==10 )
		{
			a.updatestudent();

		}if (o == 11)
		{
			a.updateteacher();

		}if (o == 12)
		{
			a.updateadmin();
		}if (o ==13 )
		{
			a.addusers();
		}if (o == 14)
		{
			a.addscholarships();
		}if (o == 15)
		{
		course c;
			a.addcourse(c);
		}if (o == 16)
		{
			course c;
			a.showcourses(c);
		}if (o ==17 )
		{
			a.searchst();
		}if (o == 18)
		{
			a.searchtch();
		}if (o == 19)
		{
			a.searchadm();
		}
		if(o==20)
		{
			a.useri();
		}
		else {
			a.useri();
		}


}
void admin::addusers()
{
	admin n;
	ofstream ost;
	int  k;
	string stname, stregno, stfone, stcnic,password,up,ps;
	ost.open("up.txt", ios::app);
	cout << "enter the number of teachers you want to now" << endl;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cout << "enter  regno name cnic and fone of teacher" << endl;
		cin >> up >> ps;
		ost << up << " " << ps << endl;
		
	}
	ost.close();
}
void st()
{
	student s;
	cout << "1.enrpll course" << endl;
	cout << "2.showcourses" << endl;
	cout << "3.showscholarships" << endl;
	cout<<"4.main menu"<<endl;
	int t;
	cin >> t;
	if (t == 1)
	{
		s.enrollcourse();
	}
	if (t == 2)
	{
		s.showcourses();
	}
	if (t == 3)
	{
		s.showscholarships();
	}
	if(t==4)
	{
		s.useri();
	}
	else
	{
		s.useri();
	}
}
void tch()
{
	system("cls");
	
	teacher f;
	cout << "1.assigncourse" << endl;
	cout << "2 showstudeents" << endl;
	cout << "3 do attendance" << endl;
	cout << "4 view attendance" << endl;
	cout << "5 give grade" << endl;
	cout << "6 showgrade" << endl;
	cout<<"7 main menu"<<endl;
	int p;
	cin >> p;
	if (p ==1 ) {
		f.assigncourse();
	}
	if (p ==2 ) {
		f.showstudents();
	}
	if (p ==3 ) {
		f.doattendance();
	}
	if (p ==4 ) {
	//	f.viewattendance();
	}
	if (p ==5 ) {
		f.givegrade();

	}
	if (p == 6) {
		f.viewgrade();
	}
	if (p==7)
	{
		f.useri();
			}
	else
	{
		f.useri();
	}
}

void user::useri()
{
	user uu;
	cout << "/t/t/t/t Welcome to the ULMS" << endl;
	cout << "/t/t/t/t 1.ADMIN" << endl;
	cout << "/t/t/t/t 2.TEACHER" << endl;
	cout << "/t/t/t/t 3.STUDENT" << endl;
	cout << "/t/t/t/t 4.EXIT" << endl;
	int g;
	cin >> g;
	if (g == 1&& login()==true)
	{
	//	login();
		adm();
	}
	if (g == 2&&login()==true)
	{
	//	login();
		tch();
	}
	if (g == 3&&login()==true)
	{
	//	login();
	}
	if (g == 4)
	{
		system("exit");
	}
}
 void isvaliduser()
{
	ifstream n;
	n.open("up.txt");
	string s;
//	if(s==b);
}
void user::ulogin()
{
	string aa, bb;
	cout << "enter your regno" << endl;
	cout << "enter your password" << endl;
}
int main()
{
	user d;
	d.useri();
//login();
	//admin z;
	//z.addusers();
//	teacher t;
	//t.viewgrade();
	//student r;
	//course h;
	//cin >> h.crsname;
	//r.showcourses();
	return 0;

}
