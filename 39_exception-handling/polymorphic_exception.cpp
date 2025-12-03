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
			throw SmallError("He didn't shave the beard");
		}
	}
	/*
	catch (CriticalError& ex) {
		std::cout << "CriticalError Exception caught : " << ex.what() << std::endl;
	}
	catch (SmallError& ex) {
		std::cout << "SmallError Exception caught : " << ex.what() << std::endl;
	}
	catch (Warning& ex) {
		std::cout << "Warning Exception caught : " << ex.what() << std::endl;
	} 
	*/
	catch (SomethingIsWrong& ex) {
		std::cout << "Exception caught : " << ex.what() << std::endl;
	}

	return 0;
}