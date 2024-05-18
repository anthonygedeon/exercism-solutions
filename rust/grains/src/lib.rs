/// Output each number by using the formula 2^(n-1) 
pub fn square(s: u32) -> u64 {
    match s {
        1..=64 => 1<<(s-1), 
        _ => panic!("Square must be between 1 and 64"), 
    }
}

/// Compute the sum of 1..=64
pub fn total() -> u64 {
    u64::MAX
}
