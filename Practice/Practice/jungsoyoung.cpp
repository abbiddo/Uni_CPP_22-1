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
	Bomb b;                               // privat 변수 선언 가능
public:
	void load(Bomb bomb) { 
		b = bomb; 
		cout << "\n 탱크 " << b.getTitle() << " 적재함\n"; 
	}
	void use() { cout << " 탱크 " << b.getTitle() << " 발사함\n\n"; }
};
class Fighter :public Weapon {
	Bomb b;
public:
	void load(Bomb bomb) {
		b = bomb;
		cout << "\n 전투기 " << b.getTitle() << " 적재함\n"; 
	}
	void use() { cout << " 전투기 " << b.getTitle() << " 발사함\n\n"; }
};
class Missile :public Weapon {
	Bomb b;
public:
	void load(Bomb bomb) {	
		b = bomb; 
		cout << "\n 미사일 " << b.getTitle() << " 적재함\n";
	}
	void use() { cout << " 미사일 " << b.getTitle() << " 발사함\n\n"; }
};

class Shop {
public:
	virtual Weapon* selectitem() = 0;
};
class BattleShop :public Shop {
public:
	Weapon* selectitem() {
		cout << " ---------------" << endl;
		cout << "   무기 아이템     " << endl;
		cout << " ---------------" << endl;
		cout << " 1. 탱크" << endl;
		cout << " 2. 전투기" << endl;
		cout << " 3. 미사일" << endl;

		int n;
		cout << "\n 아이템 선택(1~3) 그 외 종료 : ";
		cin >> n;

		Weapon* w = NULL;             // 디폴트 NULL

		if (n == 1)  w = new Tank();   // 동적 할당
		else if (n == 2)  w = new Fighter(); 
		else if (n == 3)  w = new Missile(); 
		else  cout << "\n 종료합니다.\n"; 

		return w;
	}
};

int main() {
	BattleShop shop;
	Weapon* weapon;

	while (true) {
		weapon = shop.selectitem();
		Bomb bomb("수소탄(hydrogen bomb)");

		if (weapon == NULL) break;

		weapon->load(bomb);
		weapon->use();

		delete weapon;     // 동적 해제
	}
	return 0;
}