use std::str;

/// "Encipher" with the Atbash cipher.
pub fn encode(plain: &str) -> String {
    // TODO: refactor this grotesque code
    let encoded = plain
        .to_ascii_lowercase()
        .chars()
        .filter(|c| !c.is_ascii_punctuation())
        .filter(|c| !c.is_ascii_whitespace())
        .inspect(|c| println!("{c}"))
        .map(|c| {
            if c.is_ascii_alphabetic() {
                let wraped_char = (26 - (c as u8 % 97)) + 96;
                char::from(wraped_char)
            } else {
                c
            }
        })
        .collect::<String>();

    let encoded = encoded
        .as_bytes()
        .chunks(5)
        .map(str::from_utf8)
        .collect::<Result<Vec<&str>, _>>()
        .unwrap();
    encoded.join(" ")
}

/// "Decipher" with the Atbash cipher.
pub fn decode(cipher: &str) -> String {
    encode(cipher).split_ascii_whitespace().collect()
}
