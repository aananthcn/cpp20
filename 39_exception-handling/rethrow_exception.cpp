#include <iostream>
#include <string>
 
class SomethingIsWrong {
public : 
    SomethingIsWrong(const std::string& s) : m_message(s) {}
    ~SomethingIsWrong(){}
    virtual std::string what() const { return m_message + " SomethingIsWrong [Black]"; }
protected : 
    std::string m_message;
};
 
class Warning : public SomethingIsWrong {
public : 
    Warning(const std::string& s) : SomethingIsWrong(s) {}
    virtual std::string what() const override { return m_message + " Warning [Yellow]"; }
};
 
class SmallError : public Warning {
public : 
    SmallError(const std::string& s) : Warning(s) {}
    virtual std::string what() const override { return m_message + " SmallError [Orange]"; }
 
};
 
class CriticalError : public SmallError {
public : 
    CriticalError(const std::string& s) : SmallError(s) {}
    virtual std::string what() const override {return m_message + " Critical Error [Red]"; }
};
 
int main()
{
	int i;
	try {
		try {
			std::cout << "Enter any number between 0 to 3: ";
			std::cin >> i;

			if (i == 0) {
				throw CriticalError("i is 0");
			}

			if (i == 1) {
				throw SmallError("i is 1");
			}

			if (i == 2) {
				throw Warning("i is 2");
			}

			if (i == 3) {
				throw SomethingIsWrong("He didn't shave the beard");
			}
		}
		catch (SomethingIsWrong& ex_inner) {
			if (i == 3) {
				std::cout << "Inner Exception caught : " << ex_inner.what() << std::endl;
			}
			else {
				throw; //   R E T H R O W   O F   E X C E P T I O N  ! !
				//throw ex_inner; // This will do a copy; and slicing will happend. Beware!
			}
		}
	}
	catch (SomethingIsWrong& ex) {
		std::cout << "Outer Exception caught : " << ex.what() << std::endl;
	}

	return 0;
}