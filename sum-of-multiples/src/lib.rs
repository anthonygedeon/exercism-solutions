/// Sum all multiples of a given number but excluding that said number.
///
/// # Example
/// ```rs
/// assert_eq!(2_203_160, sum_of_multiples(10_000, &[43, 47]));
/// ```
pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut sum = vec![];
    for i in 0..limit {
        for factor in factors {
            if *factor == 0 { continue }
            if i % factor == 0 { sum.push(i); }
        }

    }
    sum.dedup();
    sum.iter().sum()
}
