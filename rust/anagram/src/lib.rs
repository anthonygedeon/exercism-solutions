use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &'a str, possible_anagrams: &'a [&'a str]) -> HashSet<&'a str> {
    if possible_anagrams
        .iter()
        .any(|&anagram| anagram.to_lowercase() == word.to_lowercase())
    {
        return HashSet::new();
    }

    let mut anagram_set = HashSet::new();

    let mut sorted_word = word.to_lowercase().chars().collect::<Vec<_>>();
    sorted_word.sort();

    for &anagram in possible_anagrams {
        let mut cloned_anagrams = anagram.to_lowercase().clone().chars().collect::<Vec<_>>();
        cloned_anagrams.sort();

        if sorted_word.iter().eq(cloned_anagrams.iter()) {
            anagram_set.insert(anagram);
        }
    }

    if !anagram_set.is_empty() {
        anagram_set
    } else {
        HashSet::new()
    }
}
