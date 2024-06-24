#include "Dictionary.h"

namespace Dictionary {
	Instance Create(const char* name, int size) { // Функция для создания нового экземпляра словаря
		if (strlen(name) > DICTNAMEMAXSIZE) {
			throw(char*)THROW01;
		}
		if (size > DICTMAXSIZE) {
			throw(char*)THROW02;
		}

		Instance inst{};//создан экземпляр словаря
		strcpy_s(inst.name, name);//копирование имени в экземпляр словаря

		inst.maxsize = size;//установка макс размера словаря
		inst.size = 0;//инициализация размера словаря как 0
		inst.dictionary = new Entry[size];//выделение памяти под словарь

		return inst;
	}

	void AddEntry(Instance& inst, Entry ed) { // функция для добавления записи в словарь
		if (inst.size > inst.maxsize) {//если размер словаря выходит за размеры
			throw THROW03;
		}
		for (int i = 0; i < inst.maxsize; i++) {
			if (inst.dictionary[i].id == ed.id)//если происходит дублирование идентификатора
				throw THROW04;
		}
		inst.dictionary[inst.size++] = ed;//добавление новой фамилии в словарь
	}

	void DelEntry(Instance& inst, int id) {// функция для удаления записи из словаря по идентификатору.
		for (int i = 0; i < inst.size; ++i) {
			if (inst.dictionary[i].id == id) {// проверка наличия записи с указанным ID
				for (int j = i; j < inst.size - 1; ++j) {// сдвиг записей после удаленного элемента
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				--inst.size;//уменьшение размера словаря
				return;//выход из функции после удаления
			}
		}
		throw THROW06;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) {// функция для обновления записи в словаре
		bool find = false;//элемент не найден
		for (int i = 0; i < inst.size; ++i) {

			if (inst.dictionary[i].id == new_ed.id) { //проверка на похожий идентификатор
				throw (char*)THROW08;
			}

			if (inst.dictionary[i].id == id) {//если элеент найден, то он обновляется
				find = true;
				inst.dictionary[i] = new_ed;
				break;
			}
		}
		if (!find) {
			throw (char*)THROW07;
		}
	}

	Entry GetEntry(Instance inst, int id) { //функция для получения записи из словаря по идентификатору
		for (int i = 0; i < inst.size; ++i) {
			if (inst.dictionary[i].id == id) { // проверка на наличие похожего айди
				return inst.dictionary[i];
			}
		}
		throw THROW05;
	}

	void Print(Instance d) { // Функция для вывода всех записей из словаря
		for (int i = 0; i < d.size; ++i) {
			std::cout << d.dictionary[i].id << " " << d.dictionary[i].name << std::endl;
		}
	}

	void Delete(Instance& d) { // Функция для освобождения памяти 
		delete[] d.dictionary; // удаление выделенной памяти
		d.size = 0; //сброс размера словаря
		d.maxsize = 0; // сброс максимального размера словаря 
	}
}
