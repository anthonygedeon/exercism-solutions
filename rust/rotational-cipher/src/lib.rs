pub fn rotate(input: &str, key: i8) -> String {
    input
        .chars()
        .map(|c| match c {
            'A'..='Z' => {
                let alphabet_num = (((c as u8 % b'A') as u8 + key.unsigned_abs()) % 26) as u8;
                (b'A' + alphabet_num) as char
            }
            'a'..='z' => {
                let alphabet_num = (c as u8 % b'a').overflowing_add_signed(key);

                if alphabet_num.1 {
                    let ch = (c as u8 % b'a') + 26 + key.unsigned_abs();
                    (97 as u8 + (ch % 26) as u8) as char
                } else {
                    (b'a' + (alphabet_num.0 % 26)) as char
                }
            }
            _ => c,
        })
        .collect()
}
