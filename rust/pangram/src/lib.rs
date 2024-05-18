const A_LCASE: u8 = 97;
const A_UCASE: u8 = 65;
const ALPHA_BIT_FIELD: u32 = 0x3FFFFFF;

/// Determine whether a sentence is a pangram.
pub fn is_pangram(sentence: &str) -> bool {
    /// TODO: create a bit_field macro so we can set individual bits like C++'s std::bitset
    let mut bit_flags = 0;

    for letter in sentence.chars() {
        match letter {
            c @ 'A'..='Z' => bit_flags |= 1 << (c as u8 - A_UCASE),
            c @ 'a'..='z' => bit_flags |= 1 << (c as u8 - A_LCASE),
            _ => continue,
        }
    }

    bit_flags == ALPHA_BIT_FIELD
}
