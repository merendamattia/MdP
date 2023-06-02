#include <iostream>
class ZooAnimal {
	public:
		ZooAnimal() {
			std::cout << "Constructor ZooAnimal" << std::endl;
		}
		virtual void print() {
			std::cout << "ZooAnimal::print" << std::endl;
		}
		virtual ~ZooAnimal() {}
};

class Bear : virtual public ZooAnimal {
	public:
		Bear() {
			std::cout << "Constructor Bear" << std::endl;
		}
		void print() {
			std::cout << "Bear::print" << std::endl;
		}
		virtual ~Bear() {}
};

class Raccoon : virtual public ZooAnimal {
	public:
		Raccoon() {
			std::cout << "Constructor Raccoon" << std::endl;
		}
	virtual ~Raccoon() {}
};
class Endangered {
	public:
		Endangered() {
			std::cout << "Constructor Endangered" << std::endl;
		}
		void print() {
			std::cout << "Endangered::print" << std::endl;
		}
		virtual ~Endangered() {}
};
class Panda : public Endangered, public Bear, public Raccoon {
	public:
		Panda() {
			std::cout << "Constructor Panda" << std::endl;
		}
		void print() {
			std::cout << "Panda::print" << std::endl;
		}
		virtual ~Panda() {}
};
int main() {
	Panda ying_yang;
	ying_yang.print();
	Bear b = ying_yang;
	b.print();
	ZooAnimal* pz = &ying_yang;
	pz->print();
	Endangered& re = ying_yang;
	re.print();
	return 0;
}