// TODO: understand flat_map by writing your own
pub fn abbreviate(phrase: &str) -> String {
    phrase.split(&[' ', '_', '-'])
        .flat_map(|word| {
            word.chars().take(1).chain(
                word.chars()
                .skip_while(|c| c.is_ascii_uppercase())
                .filter(|c| c.is_ascii_uppercase())
            )
        })
    .collect::<String>()
    .to_uppercase()
}
