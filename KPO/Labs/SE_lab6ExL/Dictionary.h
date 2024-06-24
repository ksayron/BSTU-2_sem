#pragma once
#include <iostream>
#include <locale>
#include <cstring>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной ёмкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace dict{
	struct Entry {
		int id;
		char name[ENTRYNAMEMAXSIZE];
	};
	struct Dictionary {
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* entries;
	};
	Dictionary Create(const char* name, int size);

	void AddEntry(
		Dictionary& inst,
		Entry ed
	);
	void DelEntry(
		Dictionary& inst,
		int id
	);
	void UpdEntry(
		Dictionary& inst,
		int id,
		Entry new_ed
	);
	Entry GetEntry(
		Dictionary inst,
		int id
	);
	void PrintDict(Dictionary d);
	void DelDict(Dictionary& d);
}



