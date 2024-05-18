#include "protein_translation.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>

//TODO: Come back and refactor
namespace protein_translation {
    const std::map<std::string, std::string> map{
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
        {"UAA", ""}, 
        {"UAG", ""}, 
        {"UGA", ""}, 
    };

    std::vector<std::string> proteins(std::string rna) {
        std::vector<std::string> result{};
        result.reserve(rna.length()/3);
        
        for (auto i{0u}; i <= rna.length(); i += 3) {
            auto protein = map.at(rna.substr(i, 3));
            if (protein.empty()) break;
            result.push_back(protein);
        }
        for (auto el : result) {
                std::cout << "{ " << el << " }" <<'\n';
        }

        return result;
    }
}  // namespace protein_translation
