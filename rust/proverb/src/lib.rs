use std::iter::once;

pub fn build_proverb(list: &[&str]) -> String {
    match list.first() {
        Some(word) => list
            .windows(2)
            .map(|chunk| format!("For want of a {} the {} was lost.\n", chunk[0], chunk[1]))
            .chain(once(format!("And all for the want of a {}.", word)))
            .collect(),
        None => String::new(),
    }
}
