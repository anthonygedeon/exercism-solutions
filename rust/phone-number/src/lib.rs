pub fn number(user_number: &str) -> Option<String> {
    let user_number = user_number
        .chars()
        .filter(|c| c.is_ascii_digit())
        .collect::<String>();
    if user_number.len() < 10 {
        None
    } else if user_number.len() > 10 {
        match user_number.chars().nth(0).unwrap() {
            '2'..='9' => None,
            _ => match user_number.chars().nth(1).unwrap() {
                '0' | '1' => None,
                _ => match user_number.chars().nth(4).unwrap() {
                    '0' | '1' => None,
                    _ => Some(user_number[1..].to_string()),
                },
            },
        }
    } else {
        match user_number.as_bytes() {
            [invalid, ..] if (b'0'..=b'1').contains(invalid) => None,
            [_, _, _, invalid, ..] if (b'0'..=b'1').contains(invalid) => None,
            _ => Some(user_number),
        }
    }
}
