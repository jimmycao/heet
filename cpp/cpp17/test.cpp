#include <string_view>
#include <iostream>

int main() {
	std::string str = "hello world";
	std::string_view myStr(str.c_str(), 5);
	std::string_view myStr2(str.c_str()+6, 5);
	std::cout << "myStr:" << myStr << std::endl;
	std::cout << "myStr:" << myStr2 << std::endl;
	return 0;
}
