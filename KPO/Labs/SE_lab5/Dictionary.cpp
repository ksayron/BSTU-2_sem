#include "Dictionary.h"

namespace dict {
	Dictionary Create(const char* name, int size) { // ������� ��� �������� ������ ���������� �������
		if (strlen(name) > DICTNAMEMAXSIZE) {
			throw(char*)THROW01;
		}
		if (size > DICTMAXSIZE) {
			throw(char*)THROW02;
		}

		Dictionary inst{};//������ ��������� �������
		strcpy_s(inst.name, name);//����������� ����� � ��������� �������

		inst.maxsize = size;//��������� ���� ������� �������
		inst.size = 0;//������������� ������� ������� ��� 0
		inst.entries = new Entry[size];//��������� ������ ��� �������

		return inst;
	}

	void AddEntry(Dictionary& inst, Entry ed) { // ������� ��� ���������� ������ � �������
		if (inst.size > inst.maxsize) {//���� ������ ������� ������� �� �������
			throw THROW03;
		}
		for (int i = 0; i < inst.maxsize; i++) {
			if (inst.entries[i].id == ed.id)//���� ���������� ������������ ��������������
				throw THROW04;
		}
		inst.entries[inst.size++] = ed;//���������� ����� ������� � �������
	}

	void DelEntry(Dictionary& inst, int id) {// ������� ��� �������� ������ �� ������� �� ��������������.
		for (int i = 0; i < inst.size; ++i) {
			if (inst.entries[i].id == id) {// �������� ������� ������ � ��������� ID
				for (int j = i; j < inst.size - 1; ++j) {// ����� ������� ����� ���������� ��������
					inst.entries[j] = inst.entries[j + 1];
				}
				--inst.size;//���������� ������� �������
				return;//����� �� ������� ����� ��������
			}
		}
		throw THROW06;
	}

	void UpdEntry(Dictionary& inst, int id, Entry new_ed) {// ������� ��� ���������� ������ � �������
		bool find = false;//������� �� ������
		for (int i = 0; i < inst.size; ++i) {

			if (inst.entries[i].id == new_ed.id) { //�������� �� ������� �������������
				throw (char*)THROW08;
			}

			if (inst.entries[i].id == id) {//���� ������ ������, �� �� �����������
				find = true;
				inst.entries[i] = new_ed;
				break;
			}
		}
		if (!find) {
			throw (char*)THROW07;
		}
	}

	Entry GetEntry(Dictionary inst, int id) { //������� ��� ��������� ������ �� ������� �� ��������������
		for (int i = 0; i < inst.size; ++i) {
			if (inst.entries[i].id == id) { // �������� �� ������� �������� ����
				return inst.entries[i];
			}
		}
		throw THROW05;
	}

	void PrintDict(Dictionary d) { // ������� ��� ������ ���� ������� �� �������
		std::cout << "----- " << d.name << " -----" << std::endl;
		for (int i = 0; i < d.size; ++i) {
			std::cout << d.entries[i].id << " " << d.entries[i].name << std::endl;
		}
	}

	void DelDict(Dictionary& d) { // ������� ��� ������������ ������ 
		delete[] d.entries; // �������� ���������� ������
		d.size = 0; //����� ������� �������
		d.maxsize = 0; // ����� ������������� ������� ������� 
	}
}
