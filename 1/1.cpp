
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	Person(){}
	
	Person(const string& name) {
		this->name = name;

	}
	string& getName() { return name; }
	string getName() const { return name; }

	friend class Group;

private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}



class Group {
public:

	Group(){}

	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}

	// Group(string _name, int _age)
	// {
	// 	Person tmp(_name, _age);
	// }

	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if(members[i].name == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}

	~Group() {
		delete[] members;
	}
	Group(const Person& it){
		members[cap-1]=it;
	}

	friend bool isGroupFull(Group g);

	friend ostream& operator<<(ostream& out, const Group& g) {
	cout << g.size << endl << g.cap;
	for(int i = 0; i < g.cap; i++)
	{
		cout << g.members[i];
	}
	return out;
	}

	Group& operator+(const Group& g)
	{
		Group tmp;
		tmp.cap = this->cap + g.cap;
		tmp.size = this->size + g.size;
		return tmp;
	}

	Group& operator+=(const Group& g)
	{
		Group tmp;
		this->cap = this->cap + g.cap;
		this->size = this->size + g.size;
		return *this;
	}

private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main()
{

	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;

	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;

	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1<<endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;

	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;

	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}
	cout<<*find(persons,persons+10,Erfan);
	

}

