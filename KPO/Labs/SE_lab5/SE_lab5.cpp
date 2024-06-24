#include "Dictionary.h"
int main() {
	using namespace dict;
	setlocale(LC_ALL, "rus");
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1 )
#error Должно быть определено только одно из тестовых условий

#endif
	try {

#ifdef TEST_CREATE_01 // Если определено TEST_CREATE_01 (первое тестовое условие)
		Dictionary d1 = create("Пример для проверки", 5);
#endif

#ifdef TEST_CREATE_02 // Если определено TEST_CREATE_02 (второе тестовое условие)
		Dictionary d1 = create("Пример строки", 100000);
#endif

#ifdef TEST_ADDENTRY_03
		Dictionary test = create("Test", 0);
		entry test_entry = { 1, "test_entry1" };
		dict::AddEntry(test, test_entry);
#endif

#ifdef TEST_ADDENTRY_04 // Если определено TEST_ADDENTRY_04 (четвертое тестовое условие)
		Dictionary test = create("Test", 2);
		entry test_entry = { 1, "test_entry1" };
		dict::AddEntry(test, test_entry);
		dict::AddEntry(test, test_entry);
#endif

#ifdef TEST_GETENTRY_05 //GetEntry: не найдена запись
		Dictionary test = create("Test", 2);
		entry test_entry = { 1, "test_entry1" };
		dict::AddEntry(test, test_entry);
		dict::GetEntry(test, 2);
#endif

#ifdef TEST_DELENTRY_06 //DelEntry: не найдена запись
		Dictionary test = create("Test", 2);
		entry test_entry = { 1, "test_entry1" };
		dict::AddEntry(test, test_entry);
		dict::DelEntry(test, 2);
#endif

#ifdef TEST_UPDENTRY_07
		Dictionary test = create("Test", 3);
		Entry test_entry = { 1, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		dict::AddEntry(test, test_entry);
		dict::UpdEntry(test, 3, entry_to_update);
#endif

#ifdef TEST_UPDENTRY_08
		Dictionary test = create("Test", 3);
		Entry test_entry = { 2, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		dict::AddEntry(test, test_entry);
		dict::UpdEntry(test, 2, entry_to_update);
#endif

#ifdef TEST_DICTIONARY
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
#endif
	}
	catch (char* e) {
		std::cout << e << std::endl;
	};
	system("pause");
	return 0;
}