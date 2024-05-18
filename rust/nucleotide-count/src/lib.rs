use std::collections::HashMap;

pub fn count(nucleotide: char, dna: &str) -> Result<usize, char> {
    nucleotide_counts(dna)?.get(&nucleotide).ok_or(nucleotide).copied()
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, char> {
    let mut nucleotides: HashMap<_, _> = [('A', 0), ('T', 0), ('C', 0), ('G', 0)].into();
    for strand in dna.chars() {
        if !nucleotides.contains_key(&strand) {
            return Err(strand);
        }
        *nucleotides.entry(strand).or_insert(0) += 1;
    }
    Ok(nucleotides)
}
