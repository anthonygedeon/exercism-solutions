#include "protein_translation.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>

namespace protein_translation {
    std::map<codon, protein> map{
        {"AUG", "Methionine" }, 
        {"UUU", "Phenylalanine"}, 
        {"UUC", "Phenylalanine"}, 
        {"UUA", "Leucine"}, 
        {"UUG", "Leucine"}, 
        {"UCU", "Serine"}, 
        {"UCC", "Serine"}, 
        {"UCA", "Serine"}, 
        {"UCG", "Serine"}, 
        {"UAU", "Tyrosine"}, 
        {"UAC", "Tyrosine"}, 
        {"UGU", "Cysteine"}, 
        {"UGC", "Cysteine"}, 
        {"UGG", "Tryptophan"}, 
        {"UAA", "STOP"}, 
        {"UAG", "STOP"}, 
        {"UGA", "STOP"}, 
    };

    protein_list proteins(std::string rna) {
        protein_list result{};
        for (auto i{0u}; i <= rna.length(); i += 3) {
            auto search = map.find(rna.substr(i, 3));
            if (search != map.end()) {
                if (search->second == "STOP") break;
                result.push_back(search->second);
            }
        }

        return result;
    }

}  // namespace protein_translation
