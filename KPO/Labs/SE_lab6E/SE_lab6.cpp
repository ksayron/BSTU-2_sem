#include "D:\\BSTU\\2sem\KPO\Labs\SE_lab6ExL\Dictionary.h"
int main() {
	using namespace dict;
	setlocale(LC_ALL, "rus");
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1 )
#error Должно быть определено только одно из тестовых условий

#endif
	try {

		dict::Dictionary d1 = dict::Create("Преподаватели", 5);
		dict::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" };
		dict::AddEntry(d1, e1);
		dict::AddEntry(d1, e2);
		dict::AddEntry(d1, e3);
		dict::AddEntry(d1, e4);
		PrintDict(d1);
		dict::Entry ex2 = dict::GetEntry(d1, 4);
		dict::DelEntry(d1, 2);
		dict::Entry newentry = { 6, "Тугрин" };
		dict::UpdEntry(d1, 3, newentry);
		dict::Dictionary d2 = dict::Create("Студенты", 5);
		dict::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		dict::AddEntry(d2, s1);
		dict::AddEntry(d2, s2);
		dict::AddEntry(d2, s3);
		PrintDict(d2);
		dict::Entry newentry3 = { 4, "Николаев" };
		dict::UpdEntry(d2, 3, newentry3);    
		PrintDict(d1);
		PrintDict(d2);
		DelDict(d1);
		DelDict(d2);

	}
	catch (char* e) {
		std::cout << e << std::endl;
	};
	system("pause");
	return 0;
}