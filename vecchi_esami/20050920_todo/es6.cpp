class One {
	int i_one;
};

class Two {
	int i_one;
	int i_two;
};

class Three {
	int i_one;
	int i_two;
	int i_three;
};

class OneTwoThree {
private:
	One one;
	std::unique_ptr<Two> p_two;
	std::unique_ptr<Three> p_three;

	// Dichiarati privati e non implementati.
	OneTwoThree(const OneTwoThree&);
	OneTwoThree& operator=(const OneTwoThree&) = delete;

public:
	OneTwoThree(const One& o, const Two& t) :
		one(o), p_two(new Two(t)), p_three(new Three()) { }

	~OneTwoThree() = default;
	// ...
};
