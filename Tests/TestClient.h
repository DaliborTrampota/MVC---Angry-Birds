#pragma once
#include <map>
#include <stdexcept>

std::string makeErrorMsg(const char* expr, int line, const char* file);

#define TestAssert(expr) if(!(expr)) throw std::logic_error(makeErrorMsg(#expr, __LINE__, __FILE__))
#define AddTest(client, func) client.registerTest(func, #func)


class TestClient {
public:
	using FuncPtr = void(*)();
	TestClient() = default;


	void registerTest(FuncPtr func, const char* name);
	void run() const;

private:
	std::map<const char*, FuncPtr> m_tests;

};