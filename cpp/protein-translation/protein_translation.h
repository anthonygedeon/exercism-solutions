#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <vector>
#include <string>
#include <map>

using protein_list = std::vector<std::string>;
using protein = std::string;
using codon = std::string;

namespace protein_translation {
        
        extern std::map<codon, protein> map; 

        protein_list proteins(std::string rna);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
