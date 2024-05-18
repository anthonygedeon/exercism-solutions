
pub fn nth(n: u32) -> u32 {
    let mut primes = vec![];
    
    (2..)
    .filter(|item: &u32| {
        if !primes.iter().any(|p| item % p == 0) {
            primes.push(*item); // memoization
            true
        } else {
            println!("{}", item);
            false
        }
    })
    .nth(n as usize)
    .unwrap()
}
