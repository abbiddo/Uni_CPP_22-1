#include <iostream>
#include <string>
using namespace std;

class Bomb {
	string title;
public:
	Bomb() {}
	Bomb(string title) { this->title = title; }
	string getTitle() { return title; }
};

class Weapon {
public:
	virtual void load(Bomb bomb) = 0;
	virtual void use() = 0;
};
class Tank :public Weapon {
	Bomb b;                               // privat ���� ���� ����
public:
	void load(Bomb bomb) { 
		b = bomb; 
		cout << "\n ��ũ " << b.getTitle() << " ������\n"; 
	}
	void use() { cout << " ��ũ " << b.getTitle() << " �߻���\n\n"; }
};
class Fighter :public Weapon {
	Bomb b;
public:
	void load(Bomb bomb) {
		b = bomb;
		cout << "\n ������ " << b.getTitle() << " ������\n"; 
	}
	void use() { cout << " ������ " << b.getTitle() << " �߻���\n\n"; }
};
class Missile :public Weapon {
	Bomb b;
public:
	void load(Bomb bomb) {	
		b = bomb; 
		cout << "\n �̻��� " << b.getTitle() << " ������\n";
	}
	void use() { cout << " �̻��� " << b.getTitle() << " �߻���\n\n"; }
};

class Shop {
public:
	virtual Weapon* selectitem() = 0;
};
class BattleShop :public Shop {
public:
	Weapon* selectitem() {
		cout << " ---------------" << endl;
		cout << "   ���� ������     " << endl;
		cout << " ---------------" << endl;
		cout << " 1. ��ũ" << endl;
		cout << " 2. ������" << endl;
		cout << " 3. �̻���" << endl;

		int n;
		cout << "\n ������ ����(1~3) �� �� ���� : ";
		cin >> n;

		Weapon* w = NULL;             // ����Ʈ NULL

		if (n == 1)  w = new Tank();   // ���� �Ҵ�
		else if (n == 2)  w = new Fighter(); 
		else if (n == 3)  w = new Missile(); 
		else  cout << "\n �����մϴ�.\n"; 

		return w;
	}
};

int main() {
	BattleShop shop;
	Weapon* weapon;

	while (true) {
		weapon = shop.selectitem();
		Bomb bomb("����ź(hydrogen bomb)");

		if (weapon == NULL) break;

		weapon->load(bomb);
		weapon->use();

		delete weapon;     // ���� ����
	}
	return 0;
}