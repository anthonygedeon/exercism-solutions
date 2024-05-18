use std::collections::HashMap;

pub struct CodonsInfo<'a> {
    codons: HashMap<&'a str, &'a str>,
}

impl<'a> CodonsInfo<'a> {
    pub fn name_for(&self, codon: &str) -> Option<&'a str> {
        self.codons.get(&codon).copied()
    }

    pub fn of_rna(&self, rna: &str) -> Option<Vec<&'a str>> {
        let mut proteins = vec![];

        for i in (0..rna.len()).step_by(3) {
            match rna.get(i..i + 3) {
                Some(codon) => match self.name_for(codon) {
                    Some(codon) => {
                        if codon == "stop codon" {
                            break;
                        }

                        proteins.push(codon);
                    }
                    None => return None,
                },
                None => return None,
            };
        }

        Some(proteins)
    }
}

pub fn parse<'a>(pairs: Vec<(&'a str, &'a str)>) -> CodonsInfo<'a> {
    CodonsInfo {
        codons: HashMap::from_iter(pairs),
    }
}
