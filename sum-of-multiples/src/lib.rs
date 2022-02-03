pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut sum = 0;
    
    for factor in factors {
        for num in 0..limit {
            if num % factor == 0 {
                sum += num
            }
        }
    }

    sum
}
