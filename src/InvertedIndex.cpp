//
// Created by teena on 06.04.2023.
//

#include <algorithm>
#include "InvertedIndex.h"

void InvertedIndex::updateDocumentBase(std::vector<std::string> inputDocs)
{
   for (const auto &doc : inputDocs)
       docs.push_back(doc);
   freqDictionary.clear();
   std::map<std::string, std::vector<Entry>> newFreqDictionary;
   std::vector <std::thread> indexationThreads;

   for (int index = 0; index < docs.size(); ++index)
   {
       indexationThreads.emplace_back(std::thread([this, index]()
       {
           std::stringstream ss(docs[index]);
           std::string word;
           while (ss >> word)
           {
               bool foundWord = false;
               for (auto it = freqDictionary.begin(); it != freqDictionary.end() && !foundWord; ++it)
               {
                   if (it->first == word)
                   {
                       indexation.lock();
                       foundWord = true;
                       bool foundDocId = false;
                       for (int i = 0; i < it->second.size() && !foundDocId; ++i)
                       {
                           if (it->second[i].doc_id == index)
                           {
                               foundDocId = true;
                               ++it->second[i].count;
                           }
                       }
                       if (!foundDocId)
                       {
                           Entry newEntry{static_cast<size_t>(index), 1};
                           it->second.push_back(newEntry);
                           std::sort(it->second.begin(), it->second.end(), Entry::compare);
                       }
                       indexation.unlock();
                   }
               }
               if (!foundWord)
               {
                   indexation.lock();
                   Entry newEntry{static_cast<size_t>(index), 1};
                   freqDictionary.insert
                        (std::pair<std::string, std::vector<Entry>>(word, std::vector<Entry>{newEntry}));
                   indexation.unlock();
               }
           }
       }));
   }

   for (auto &indexationThread : indexationThreads)
       indexationThread.join();
}

std::vector<Entry> InvertedIndex::getWordCount(const std::string &word)
{
    return std::vector<Entry>();
}

