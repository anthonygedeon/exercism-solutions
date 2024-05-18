use std::collections::HashMap;

#[derive(Debug, PartialEq, Eq)]
pub struct Dna(String);

#[derive(Debug, PartialEq, Eq)]
pub struct Rna(String);

impl Dna {
    pub fn new(dna: &str) -> Result<Dna, usize> {
        let mut flag = false;
        for (i, c) in dna.char_indices() {
            if ['G', 'C', 'T', 'A'].contains(&c) {
                flag = true;
            } else {
                return Err(i);
            }
        }

        if flag {
            Ok(Dna(dna.to_string()))
        } else {
            Err(0)
        }
    }

    pub fn into_rna(self) -> Rna {
        let strand = self
            .0
            .chars()
            .map(|nucleotide| match nucleotide {
                'G' => 'C',
                'C' => 'G',
                'T' => 'A',
                'A' => 'U',
                _ => unreachable!(),
            })
            .collect::<String>();
        Rna::new(&*strand).unwrap()
    }
}

impl Rna {
    pub fn new(rna: &str) -> Result<Rna, usize> {
        let mut flag = false;
        for (i, c) in rna.char_indices() {
            if ['C', 'G', 'A', 'U'].contains(&c) {
                flag = true;
            } else {
                return Err(i);
            }
        }

        if flag {
            Ok(Rna(rna.to_string()))
        } else {
            Err(0)
        }
    }
}
