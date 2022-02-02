pub fn build_proverb(list: &[&str]) -> String {
    let mut proverb: Vec<String> = Vec::new();
    let mut last_word = String::new();
    for (i, word) in list.iter().enumerate() {
        if list.len() > 1 {
            let word2 = match list.get(i + 1) {
                None => break,
                Some(word) => word.to_string(),
            };
            let sentence = format!("For want of a {} the {} was lost.", word, word2);
            proverb.push(sentence);
        }
        last_word = list.first().unwrap().to_string();
    }
    if !list.is_empty() {
        proverb.push(format!("And all for the want of a {}.", &last_word));
    }
    if proverb.is_empty() {
        return String::new();
    }
    return proverb.join("\n");
}
