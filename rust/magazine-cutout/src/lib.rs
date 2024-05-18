// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {
    let mut word_frequency = HashMap::new();
    
    for word in magazine {
        *word_frequency.entry(word).or_insert(1) += 1
    }

     

    println!("{:?}", word_frequency);

    true
}
