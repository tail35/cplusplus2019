#include "iotest.h"


void testxalloc() 
{
	static const int i = std::ios_base::xalloc();
	static const int j = std::ios_base::xalloc();
	std::cout.iword(i) = 11;
	std::cin.iword(i) = 13;
	std::cin.pword(j) =(void*) "testing";
	std::cout << std::cout.iword(i) << std::endl;
	std::cout << std::cin.iword(i) << std::endl;
	std::cout << (char*)std::cin.pword(j) << std::endl;
}

void boolapha() {
	std::cout << true << std::endl;//1
	std::cout << std::boolalpha <<true<<std::endl;//trues
	std::cout << std::noboolalpha << true << std::endl;
}


void getmoney() {
	std::istringstream in("$1,234.56 2.22 USD  3.33");
	long double v1, v2;
	in.imbue(std::locale("en_US.UTF-8"));
	//in.imbue(std::locale("zh_CN.UTF-8"));
	std::_Monobj k = std::get_money(v1);
	in >> k;	
	std::cout << v1;
	return;

	std::string v3;
	in.imbue(std::locale("en_US.UTF-8"));
	in >> std::get_money(v1) >> std::get_money(v2) >> std::get_money(v3, true);
	if (in) {
		std::cout << std::quoted(in.str()) << " parsed as: "
			<< v1 << ", " << v2 << ", " << v3 << '\n';
	}
	else {
		std::cout << "Parse failed";
	}
}

void myputmoney()
{
	long double mon = 123.45; // or std::string mon = "123.45";

	std::cout.imbue(std::locale("en_US.UTF-8"));
	std::cout << std::showbase
		<< "en_US: " << std::put_money(mon)
		<< " or " << std::put_money(mon, true) << '\n';

	std::cout.imbue(std::locale("ru_RU.UTF-8"));
	std::cout << "ru_RU: " << std::put_money(mon)
		<< " or " << std::put_money(mon, true) << '\n';

	std::cout.imbue(std::locale("ja_JP.UTF-8"));
	std::cout << "ja_JP: " << std::put_money(mon)
		<< " or " << std::put_money(mon, true) << '\n';
}

void myput_time() {
	std::tm t = {};
	std::istringstream ss("2011-Februar-18 23:12:34");
	ss.imbue(std::locale("de_DE.utf-8"));
	ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
	if (ss.fail()) {
		std::cout << "Parse failed\n";
	}
	else {
		std::cout << std::put_time(&t, "%c") << '\n';
	}
}

void myquote() {
	std::stringstream ss;
	std::string in = "String with spaces, and embedded \"quotes\" too";
	std::string out;
	ss << quoted(in);
	ss >> quoted(out);
	std::cout << out;
}
void mytestpath()
{
	std::filesystem::path p = "c:/wo/ni/1.txt";
	std::filesystem::path p2 = "d:/ni";
	p.swap(p2);
	std::cout << p << " " << p2;
	//std::cout << p.replace_extension("tt");
	//std::cout << p.replace_filename( "2.txt" );
	//std::cout << p.replace_filename( std::filesystem::path("2.txt"));

	//std::cout << std::boolalpha << p.has_filename();
	//std::cout << p.remove_filename() << " " <<std::boolalpha <<p.has_filename();
	//std::filesystem::path p = "c:/wo/ni";	
	//std::cout << p.make_preferred() << std::endl;

	//std::filesystem::path p = "c:\\wo";	
	//p /= "temp";
	////p /= "temp";
	//std::filesystem::path p = std::filesystem::path("c:wo") / "temp";
	//p.
	//std::cout<<p<<std::endl;
}

void iotest() 
{
	mytestpath();
}