///  Adds (1 + 2 + ... + 10) together than ^2 the result.
pub fn square_of_sum(n: u32) -> u32 {
    let numbers = (1..).take(n as usize);
    let numbers: u32 = match numbers.reduce(|accum, item| accum + item) {
        Some(num) => num, 
        None => 0, 
    };
    numbers.pow(2)
}

/// ^2 each number in a list and adds them all up.
pub fn sum_of_squares(n: u32) -> u32 {
    let numbers = (1..).take(n as usize);
    let numbers: u32 = match numbers.reduce(|accum, item| accum + (item as u32).pow(2)) {
        Some(num) => num, 
        None => 0, 
    };
    numbers
}

/// Calculate the difference between the two fns.
pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}
