//
// Created by teena on 08.04.2023.
//

#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>


struct Entry
{
    size_t doc_id, count;
// Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const
    {
        return (doc_id == other.doc_id && count == other.count);
    }

    static bool compare(Entry &a, Entry &b)
    {
        return a.doc_id < b.doc_id;
    }
};

class InvertedIndex
{
private:
    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freqDictionary; // частотный словарь
public:
    InvertedIndex() = default;
/* Обновить или заполнить базу документов, по которой будем совершать
 * поиск @param texts_input содержимое документов
*/
    void updateDocumentBase(std::vector<std::string> input_docs);
/*Метод определяет количество вхождений слова word в загруженной базе документов
* @param word слово, частоту вхождений которого необходимо определить
* @return возвращает подготовленный список с частотой слов
*/
    std::vector<Entry> getWordCount(const std::string& word);
};