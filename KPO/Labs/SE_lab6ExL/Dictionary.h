#pragma once
#include <iostream>
#include <locale>
#include <cstring>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������ �������"
#define THROW06 "DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������"

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



