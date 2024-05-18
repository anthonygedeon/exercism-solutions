use regex::Regex;
use std::collections::HashMap;

/// Count occurrences of words.
pub fn word_count(words: &str) -> HashMap<String, u32> {
    let re = Regex::new(r"\w+('\w)?").unwrap();
    let mut frequency = HashMap::new();

    re.captures_iter(&words.to_lowercase()[..])
        .for_each(|cap| *frequency.entry(String::from(&cap[0][..])).or_insert(0) += 1);

    frequency
}
