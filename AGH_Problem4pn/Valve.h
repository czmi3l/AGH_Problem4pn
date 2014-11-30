#include "Lista.h"

class Valve
{
public:
	enum Flags{
		Opened,
		Closed
	};
	Valve();
	Valve(Flags);
	~Valve();
	Valve(const Valve&);
	bool IsOpen();
	Valve& operator=(const Valve valve);
	void open();
	void close();
	static void clean();
	friend string status2symbol(Valve& valve); 
private:
	Flags flag;
	static Lista < Valve > list;
};

Lista<Valve> Valve::list;

Valve::Valve()
{
	flag = Closed;
	Valve::list.push_back(this);
}

Valve::Valve(Flags fla)
{
	Valve::list.push_back(this);

	clean();
	flag = Opened;
}

Valve::~Valve()
{
}

Valve::Valve(const Valve& valve){
	flag = valve.flag;
}

bool Valve::IsOpen(){
	if (flag == Opened)
		return true;
	return false;
}

Valve& Valve::operator=(const Valve valve){
	flag = valve.flag;
	return *this;
}

void Valve::open(){
	Lista<Valve>::Iterator iter = Valve::list.begin();
	clean();
	flag = Opened;
}

void Valve::close(){
	flag = Closed;
}

void Valve::clean(){
	Lista<Valve>::Iterator iter = Valve::list.begin();
	for (iter; iter != Valve::list.end(); iter++)
	{
		(*iter).close();
	}
}

string status2symbol(Valve& valve){
	return valve.IsOpen() == 1 ? "Otwarty" : "Zamkniety";
}