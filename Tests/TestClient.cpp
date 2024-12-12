#include "TestClient.h"

#include <sstream>
#include <iostream>

void TestClient::registerTest(FuncPtr func, const char* name)
{
	m_tests[name] = func;
}

void TestClient::run() const
{
	int passedTests = 0;
	for (auto const& [name, test] : m_tests) {
		try {
			test();
			passedTests++;
		}
		catch (std::exception e) {
			std::cout << "Test: " << name << " failed\n" << e.what() << std::endl;
		}
	}

	std::cout << "======== Test Results ========\n";
	std::cout << "Passed: " << passedTests << "\nFailed: " << m_tests.size() - passedTests << std::endl;

}

std::string makeErrorMsg(const char* expr, int line, const char* file)
{
	std::stringstream error;
	error << line << " " << file << std::endl << "Expression: " << expr << std::endl;
	return error.str();
}
