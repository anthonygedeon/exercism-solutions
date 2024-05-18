#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <vector>
#include <string>
#include <map>

namespace protein_translation {
        
        const extern std::map<std::string, std::string> map; 

        std::vector<std::string> proteins(std::string rna);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
