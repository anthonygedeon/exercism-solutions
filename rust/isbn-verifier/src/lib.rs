/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    // TODO: avoid heap allocation
    let isbn = isbn.replace("-", "");

    if isbn.len() != 10 {
        return false;
    }

    let mut sum = 0;
    for (i, c) in isbn.char_indices() {
        if let Some(num) = c.to_digit(10) {
            sum += num * (10 - i as u32);
        } else if i == 9 && c == 'X' {
            // the last character would be multiplied by 1 so we can ignore the multiplication
            sum += 10
        } else {
            return false;
        }
    }

    sum % 11 == 0
}
