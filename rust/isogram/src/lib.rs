pub fn check(candidate: &str) -> bool {
    candidate.to_lowercase()
        .bytes()
        .filter_map(|c| c.is_ascii_alphabetic().then(|| c.to_ascii_lowercase()))
        // TODO: Understand what's going on here
        .map(|b| 1u32 << (b as u8 - b'a'))
        .try_fold(0u32, |map, b| (map & b == 0).then(|| map | b))
        .is_some() 
}
